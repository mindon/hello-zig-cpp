const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "hello",
        .root_source_file = b.path("src/hello.zig"),
        .target = target,
        .optimize = optimize,
    });

    // build a c++ lib with c binding
    const xlib = b.addStaticLibrary(.{
        .name = "xlib",
        .target = target,
        .optimize = optimize,
        .version = .{ .major = 0, .minor = 1, .patch = 0 },
    });
    xlib.linkLibC();
    xlib.linkLibCpp();

    xlib.addIncludePath(b.path("vendor/xlib"));
    xlib.addCSourceFiles(.{
        .root = b.path("vendor/xlib"),
        .files = &.{
            "binding.cpp",
            "hello.cpp",
        },
    });
    xlib.installHeader(b.path("vendor/xlib/binding.h"), "xlib/binding.h");
    b.installArtifact(xlib);

    exe.linkLibrary(xlib);
    // ---

    b.installArtifact(exe);

    const run_exe = b.addRunArtifact(exe);
    const run_step = b.step("run", "Run the application");
    run_step.dependOn(&run_exe.step);
}

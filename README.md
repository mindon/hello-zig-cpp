# hello-zig-cpp
A demo how to call c++ from Zig

based on <https://github.com/anagram3k/zig-with-cpp>

1. using a c++ lib, a binding.cpp and binding.h should be appended to build the lib;
2. binding.h should be installed
3. use ```zig
const c = @cImport({
    @cInclude("xlib/binding.h");
});
``` in zig, and call binding things with c.*


`zig build run`

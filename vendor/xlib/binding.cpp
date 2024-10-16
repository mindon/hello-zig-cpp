#include "hello.hpp"
#include "binding.h"
#include <string>

//--------- C-Interface for class std::string ------------------//
hString string_new()
{
    return new std::string{};
}

hString string_new1(const char* text)
{
    return new std::string(text);
}

// Copy constructor
hString string_copy(hString self)
{
    std::string* p = reinterpret_cast<std::string*>(self);
    return new std::string(*p);
}

void string_del(hString self)
{
    delete reinterpret_cast<std::string*>(self);
}

void string_add(hString self, const char* text)
{
    auto p = reinterpret_cast<std::string*>(self);
    *p = *p + text;
}

void string_disp(hString self, const char* name)
{
    auto p = reinterpret_cast<std::string*>(self);
    std::cout << name << " / std::string{ " << *p << "} " << std::endl;
}

//---------- C-Interface for class Runstat ---------------------//

pStat Runstat_new()
{
    return new (std::nothrow) Runstat();
}

void Runstat_del(pStat self)
{
    delete reinterpret_cast<Runstat*>(self);
}

void Runstat_add(pStat self, double x)
{
    auto p = reinterpret_cast<Runstat*>(self);
    p->add(x);
}

double Runstat_mean(pStat self)
{
    Runstat* p = reinterpret_cast<Runstat*>(self);
    return p->mean();
}

double Runstat_sdev(pStat self)
{
    Runstat* p = reinterpret_cast<Runstat*>(self);
    return p->sdev();
}

size_t Runstat_size(pStat self)
{
    Runstat* p = reinterpret_cast<Runstat*>(self);
    return p->size();
}

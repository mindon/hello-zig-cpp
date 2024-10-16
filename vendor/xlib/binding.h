#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

typedef  void* hString;

hString string_new();
hString string_new1 (const char* text);
hString string_copy (hString self);
void    string_del  (hString self);
void    string_add  (hString self, const char* text);
void    string_disp (hString, const char* name);

// Opaque pointer type alias for C-lang
typedef void* pStat;
typedef long unsigned int size_t;

pStat   Runstat_new();
void    Runstat_del (pStat self);
void    Runstat_add (pStat self, double x);
double  Runstat_mean(pStat self);
double  Runstat_sdev(pStat self);
size_t  Runstat_size(pStat self);

#ifdef __cplusplus
}
#endif

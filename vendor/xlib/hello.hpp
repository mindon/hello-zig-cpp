#ifndef _CODECPP_
#define _CODECPP_

#include <iostream>

class Runstat
{
    /// Sum of sequence processed
    double m_sum;
    /// Sum of squares processed
    double m_sumsq;
    /// Size of sequence processed
    size_t m_N;
public:
    Runstat();
    Runstat(Runstat const&)            = delete;
    Runstat& operator=(Runstat const&) = delete;
    ~Runstat();
    void   add(double x);
    void   reset();
    size_t size() const;
    double mean() const;
    /// Standard deviation
    double sdev() const;
};

#endif

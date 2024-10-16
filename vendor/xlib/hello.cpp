#include "hello.hpp"

#include <iostream>
#include <cmath>

//----------- Implementation of class RunningStatics -----------//

Runstat::Runstat()
{
    std::cout << " [TRACE] Object created Ok." << std::endl;
    m_sum = 0.0;
    m_sumsq = 0.0;
    m_N = 0;
}

Runstat::~Runstat()
{
    std::cout << " [TRACE] Object deleted OK" << std::endl;
}

void
Runstat::add(double x)
{
    m_sum += x;
    m_sumsq += x * x;
    m_N++;
}

size_t
Runstat::size() const
{
    return m_N;
}

void
Runstat::reset()
{
    m_sum = 0.0;
    m_sumsq = 0.0;
    m_N = 0;
}

double
Runstat::mean() const
{
    return m_sum / m_N;
}

double
Runstat::sdev() const
{
   size_t N = m_N;
   return std::sqrt((m_sumsq - m_sum * m_sum / N) / (N - 1.0));
}

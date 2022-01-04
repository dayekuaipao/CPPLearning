#include "fac.hpp"
long long fac(int n)
{
    if (n > 0)
    {
        if (n == 1)
        {
            return 1;
        }
        else
        {
            return fac(n - 1) * n;
        }
    }
    else
    {
        return 0;
    }
}
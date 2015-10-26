#include "utils.h"

inline int pow(int x, int n)
{
    int res = 1;
    for(int i = 0; i < n; i++)
        res *= x;
    return res;
}

inline int pow2(int n)
{
    return (n == 0) ? 1 : 2 << (n - 1);
}

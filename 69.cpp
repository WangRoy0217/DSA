#include <bits/stdc++.h>

using namespace std;
/* 69. Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative
 as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

*/
int MySqrt(int x)
{
    uint64_t l = 0;
    uint64_t r = (uint64_t)x+1;

    while(l<r)
    {
        uint64_t mid = l + (r-l)/ 2;
        cout<<l<<","<<r<<","<<mid<<endl;
        if(mid*mid > x)
            r = mid;
        else
            l = mid+1;
    }
    return l-1;
}

int main(int argc, char const *argv[])
{
    cout<<MySqrt(1)<<endl;
    return 0;
}
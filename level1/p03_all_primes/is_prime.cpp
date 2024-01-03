//
// Created by liuhaolu on 2023/12/12.
//
#include "is_prime.h"
bool is_prime(int n)
{
    for(int i=2;i<=n/2;i++)
        if(n%i==0) return 0;
    return 1;
}
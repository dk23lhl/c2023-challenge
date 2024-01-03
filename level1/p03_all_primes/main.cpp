#include <bits/stdc++.h>
#include "is_prime.h"
using namespace std;
int main()
{
    for (int i=2;i<=1000;i++)
        if(is_prime(i)) cout<<i<<endl;
}
#include <bits/stdc++.h>
#include "is_prime.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(is_prime(n)) cout<<"这是素数";
    else cout<<"这不是素数";
    system("pause");
    return 0;
}
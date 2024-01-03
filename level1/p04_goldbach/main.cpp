#include <bits/stdc++.h>
#include"is_prime.h"
using namespace std;

int main()
{
    for(int i=4;i<=100;i+=2)
    {
        int k=0;
        for(int j=2;j<=i/2;j++)
        {
            if(is_prime(j)&&is_prime(i-j))
            {
                cout<<i<<"="<<j<<"+"<<i-j<<endl;
                k=1;
                break;
            }
        }
        if(!k)
        {
            cout<<"¸çµÂ°ÍºÕ²ÂÏë´íÎó"<<endl;
            return 0;
        }
    }
    cout<<"¸çµÂ°ÍºÕ²ÂÏëÕýÈ·"<<endl;
}
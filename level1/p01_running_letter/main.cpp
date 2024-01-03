//
// Created by liuhaolu on 2023/12/12.
//
#include<bits/stdc++.h>
#include<windows.h>
#define SCREEN_WIDTH 120
using namespace std;
int main()
{
    int n,i,k;
    n = 0;k = 1;
    while(1)
    {
        n = n+k;
        if (n == SCREEN_WIDTH || n == 0)
            k = -k;
        for(i = 1;i <= n;i++)
        {
            cout<<" ";
        }
        cout<<"?";
        Sleep(100);
        system("cls");
    }
}
#include <bits/stdc++.h>
using namespace std;

void hanoi(int n,char from,char by, char to);

int main()
{
    hanoi(64,'A','B','C');
    return 0;
}

void hanoi(int n,char from,char by,char to)
{
    if(n==1)
    {
        cout<<from<<"->"<<to<<endl;
        return;
    }
    hanoi(n-1,from,to,by);
    cout<<from<<"->"<<to<<endl;
    hanoi(n-1,by,from,to);
}
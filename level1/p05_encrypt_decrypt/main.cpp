#include<bits/stdc++.h>
using namespace std;

char caesar(char c,bool k);

int main()
{
    string s1;
    char s2[100000],s3[100000];
    cin>>s1;
    for(int i=0;i<s1.length();i++)
    {
        s2[i]=caesar(s1[i],true);
        cout<<s2[i];
    }
    cout<<endl;
    for(int i=0;i<s1.length();i++)
    {
        s3[i]=caesar(s2[i],false);
        cout<<s3[i];
    }
}

char caesar(char c,bool k)
{
    return char(k ? int(c) + 3 : int(c) - 3);
}
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

using namespace std;

char a[10][11];

int main()
{
    cout<<"请选择关卡1、2"<<endl;
    int n;
    cin>>n;
    fstream infile;
    if(n==1)
        infile.open("C:\\Users\\liuhaolu\\CLionProjects\\c2023-challenge\\level1\\p08_push_boxes\\map1.txt",ios::in);
    if(n==2)
        infile.open("C:\\Users\\liuhaolu\\CLionProjects\\c2023-challenge\\level1\\p08_push_boxes\\map2.txt",ios::in);
    if (!infile.is_open())
    {
        cout << "文件打开失败。" << endl;
        system("pause");
        return 0;
    }
    char c;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<11;j++)
        {
            c=infile.get();
            a[i][j]=c;
        }
    }
    infile.close();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<11;j++)
        {
            cout<<a[i][j];
        }
    }
    int x = 1, y = 1,s=0;
    while (1)
    {
        s++;
        char d;
        d = getch();
        if (d == 'w' && a[x - 1][y] != '*')
        {
            if(a[x-1][y]=='?')
            {
                if(a[x-2][y]=='*') continue;
                a[x-2][y]='?';
            }
            a[x][y] = ' ';
            a[x - 1][y] = 'o';
            x--;
        }
        else if (d == 's' && a[x + 1][y] != '*')
        {
            if(a[x+1][y]=='?')
            {
                if(a[x+2][y]=='*') continue;
                a[x+2][y]='?';
            }
            a[x][y] = ' ';
            a[x + 1][y] = 'o';
            x++;
        }
        else if (d == 'a' && a[x][y - 1] != '*')
        {
            if(a[x][y-1]=='?')
            {
                if(a[x][y-2]=='*') continue;
                a[x][y-2]='?';
            }
            a[x][y] = ' ';
            a[x][y - 1] = 'o';
            y--;
        }
        else if (d == 'd' && a[x][y + 1] != '*')
        {
            if(a[x][y+1]=='?')
            {
                if(a[x][y+2]=='*') continue;
                a[x][y+2]='?';
            }
            a[x][y] = ' ';
            a[x][y + 1] = 'o';
            y++;
        }
        system("cls");
        for (int i = 0; i < 10; i++)
        {
            for(int j=0;j<11;j++)
            {
                cout<<a[i][j];
            }
            if (x == 2 && y == 8)
            {
                system("cls");
                cout << "成功到达！"<<endl;
                cout<<"分数为"<<100-s<<endl;
                system("pause");
                return 0;
            }
        }
    }
}
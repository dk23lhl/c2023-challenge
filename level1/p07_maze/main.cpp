#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

char a[9][10] = { "*********","*o  * * *","*** * * E","***   * *",
                  "** *  * *","***  ** *","*** *   *","**     **","*********" };

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << endl;
    }
    int x = 1, y = 1, m = 0;
    while (1)
    {
        char d;
        m++;
        d = getch();
        if (d == 'w' && a[x - 1][y] != '*')
        {
            a[x][y] = ' ';
            a[x - 1][y] = 'o';
            x--;
        }
        else if (d == 's' && a[x + 1][y] != '*')
        {
            a[x][y] = ' ';
            a[x + 1][y] = 'o';
            x++;
        }
        else if (d == 'a' && a[x][y - 1] != '*')
        {
            a[x][y] = ' ';
            a[x][y - 1] = 'o';
            y--;
        }
        else if (d == 'd' && a[x][y + 1] != '*')
        {
            a[x][y] = ' ';
            a[x][y + 1] = 'o';
            y++;
        }
        system("cls");
        for (int i = 0; i < 9; i++)
        {
            cout << a[i] << endl;
            if (x == 2 && y == 8)
            {
                system("cls");
                cout << "成功到达！";
                system("pause");
                return 0;
            }
        }
    }
}
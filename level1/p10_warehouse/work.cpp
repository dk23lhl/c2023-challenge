#include<bits/stdc++.h>
#include "work.h"

using namespace std;

void menu()
{
    int input;
    while(true)
    {
        printf("����������Ҫ�Ĺ��ܶ�Ӧ�����֣�\n");
        printf("1����ʾ����б�\n"
               "2�����\n"
               "3������\n"
               "4���˳�����\n");
        scanf("%d",&input);
        getchar();
        switch (input)
        {
            case 1:
            {
                showware();
                break;
            }
            case 2:
            {
                addin();
                break;
            }
            case 3:
            {
                decrease();
                break;
            }
            case 4:
            {
                return;
            }
            default:
            {
                printf("�����������������\n");
            }
        }
    }
}

void decrease()
{
    ware temp,cmp;
    FILE *fp1,*fp2;
    fp1 = fopen("ware.data", "r+b");
    fp2 = fopen("temp.data", "w+b");
    while (true)
    {
        cmp.num = 0;
        printf("������Ҫ��������� ���� �������Կո��� ��Q Q Q����");
        scanf("%s %s %lf", cmp.name, cmp.type, &cmp.num);
        getchar();
        if((cmp.name[0] == 'Q' || cmp.name[0] == 'q') && (cmp.type[0] == 'Q' ||cmp.type[0] == 'q') && cmp.num == 0)
        {
            break;
        }
        while (true)
        {
            int k = fread(&temp, sizeof(ware), 1, fp1);
            if (k == 0)
            {
                break;
            }
            if (strcmp(temp.name, cmp.name) != 0 && strcmp(temp.type, cmp.type) != 0)
            {
                fwrite(&temp, sizeof(ware), 1, fp2);
            }
            else
            {
                if (cmp.num > temp.num)
                {
                    printf("�����������������\n");
                    fclose(fp2);
                    remove("temp.data");
                    break;
                }
                else if (cmp.num == temp.num)
                {
                    continue;
                }
                else if (cmp.num < temp.num)
                {
                    temp.num -= cmp.num;
                    fwrite(&temp, sizeof(ware), 1, fp2);
                }
                else
                {
                    fclose(fp1);
                    fclose(fp2);
                    remove("temp.data");
                    return;
                }
            }
        }
        fclose(fp1);
        fclose(fp2);
        remove("ware.data");
        rename("temp.data","ware.data");
    }
    fclose(fp1);
    fclose(fp2);
}

void addin()
{
    FILE *fp;
    fp = fopen("ware.data", "a+b");
    while(true)
    {
        if (fp == nullptr)
        {
            printf("��ȡ/���������ļ�ʧ��\n");
            system("pause");
            system("cls");
            return;
        }
        ware temp;
        temp.num = 0;
        printf("���������� ���� �������Կո��� ��Q Q Q����");
        scanf("%s %s %lf", temp.name, temp.type, &temp.num);
        getchar();
        if ((temp.name[0] == 'Q' || temp.name[0] == 'q') && (temp.type[0] == 'Q' ||temp.type[0] == 'q') && temp.num == 0)
        {
            break;
        }
        else
        {
            fwrite(&temp,sizeof(ware),1,fp);
        }
    }
    fclose(fp);
}

void showware()
{
    system("cls");
    ware temp[100];
    FILE *fp;
    int ch;
    fp = fopen("ware.data","rb");
    if(fp == nullptr)
    {
        printf("�������ļ���������");
        printf("\n");
        system("pause");
        system("cls");
    }
    else
    {
        for (int i = 0; i < 100; ++i)
        {
            int k = fread(&temp[i], sizeof(ware),1,fp);
            if(k == 0)
            {
                break;
            }
            printf("%s %s %f",temp[i].name,temp[i].type,temp[i].num);
            printf("\n");
        }
        printf("\n");
        system("pause");
        fclose(fp);
        system("cls");
    }
}
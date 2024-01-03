#include <bits/stdc++.h>

using namespace std;

typedef struct LinkedList
{
    int number;
    int data;
    struct LinkedList *next;
}LinkedList;

LinkedList * CreatLinked(int length);//��������lengthΪ������.
void PrintLinked(LinkedList * head);//��ӡ�����ֵ����������.
int FindOneValue(LinkedList * head,int value);//��ѯ�ڵ��ֵ������������ͬ�Ľڵ���ţ�δ���ҵ��򷵻�-1.
LinkedList * TransNum(LinkedList * head);//��������.
void FindAllValue(LinkedList * head,int value,int * a);//��ѯ�ڵ��ֵ��������ƥ����Ŵ�����������.
LinkedList * FindNum(LinkedList * head,int number);//Used for AddValue&DelValue.
void AddValue(LinkedList * head,int CurrentData,int BeforeNumber);//��������ĳһ��֮�����ֵ.
void DelValue(LinkedList * head,int BeforeNumber);//ɾ������ĳһ�����һ��.
void FreeLinked(LinkedList * head);//�ͷſռ�.

int main()
{
    int length;
    LinkedList *head;
    cin>>length;
    getchar();
    head = CreatLinked(length);
    AddValue(head,3,2);
    DelValue(head,2);
    AddValue(head,3,2);
    int a[length];
    int same = FindOneValue(head,5);
    printf("%d\n",same);
    FindAllValue(head,5,a);
    for (int i = 0; i < length; ++i)
    {
        printf("%d ",a[i]);
    }
    head = TransNum(head);
    PrintLinked(head);
    FreeLinked(head);
    return 0;
}


LinkedList * CreatLinked(int length)
{
    LinkedList * head = NULL;
    LinkedList *prev,*next;
    for(int i = 1;i <= length;++i)
    {
        next = (LinkedList*) malloc(sizeof (LinkedList));
        next->next = NULL;
        if(head == NULL)
            head = next;
        else
            prev->next = next;
        scanf("%d",&next->data);
        next->number = i;
        getchar();
        prev = next;
    }
    return head;
}

void PrintLinked(LinkedList * head)
{
    LinkedList * finder = head;
    for(;finder != NULL;)
    {
        finder = finder->next;
    }
}

int FindOneValue(LinkedList * head,int value)
{
    LinkedList * finder = head;
    for(;finder != NULL;finder = finder->next)
    {
        if(finder->data == value)
        {
            return finder->number;
        }
    }
    if(finder == NULL)
    {
        return -1;
    }
}

LinkedList * TransNum(LinkedList * head)
{
    LinkedList * p1,*p2,*p3;
    p1 = head;
    p2 = head->next;
    p3 = p2->next;
    for(;p3 != NULL;)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    head->next = NULL;
    head = p2;
    return head;
}

void FindAllValue(LinkedList * head,int value,int * a)
{
    LinkedList * finder = head;
    for(int i = 0;finder != NULL;finder = finder->next,++i)
    {
        if(finder->data == value)
        {
            a[i] = finder->number;
        }
        else
            a[i] = -1;
    }
}

void FreeLinked(LinkedList * head)
{
    LinkedList * current;
    while (head != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
}

LinkedList * FindNum(LinkedList * head,int number)
{
    LinkedList * finder = head;
    for(;finder != NULL;finder = finder->next)
    {
        if(finder->number == number)
        {
            return finder;
        }
    }
    if(finder == NULL)
    {
        return NULL;
    }
}

void AddValue(LinkedList * head,int CurrentData,int BeforeNum)
{
    LinkedList * before = FindNum(head,BeforeNum);
    LinkedList *after;
    after = (LinkedList *)malloc(sizeof (LinkedList));
    after->next = before->next;
    after->data = CurrentData;
    before->next = after;
}

void DelValue(LinkedList * head,int BeforeNumber)
{
    LinkedList * before = FindNum(head,BeforeNumber);
    LinkedList * del = before->next;
    before->next = del->next;
    free(del);
}
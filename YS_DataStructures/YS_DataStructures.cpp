#include <iostream>
#include "YS_stack.h"
#include "YS_queue.h"
#include "YS_linkedlist.h"
#include "YS_doublelinkedlist.h"

int main()
{
    /*stack stack;

    for (int i = 0; i <= 5; i++)
    {
        stack.Push(i);
    }
    int deleteindex = 0;
    stack.Pop(deleteindex);
    stack.Pop(deleteindex);
    stack.Show_TotalStack();

    queue Queue;

    for (int i = 0; i <= 5; i++)
    {
        Queue.Push(i);
    }

    int DeleteIndex = 0;
    Queue.Pop(DeleteIndex);

    Queue.Show_TotalQueue();*/

    /*linkedlist<int> SList;
    LNode<int>* HeadNode = nullptr;

    bool bSuccessed = SList.CreateList(Data<int>(0), HeadNode);
    if (bSuccessed == false)
    {
        return 0;
    }

    for (int i = 1; i <= 5; i++)
    {
        SList.AddNode(Data<int>(i));
    }

    for (int i = 7; i <= 10; i++)
    {
        SList.AddNode(Data<int>(i));
    }

    SList.AddNode(Data<int>(5), Data<int>(6));

    SList.DeleteNode(Data<int>(3));

    SList.DeleteNode();
    SList.DeleteNode();
    SList.DeleteNode();

    SList.PrintList();
    return 0;*/

    doublelinkedlist<int> DList;
    DList.CreateList(Ddata<int>(3));

    DList.AddNext(Ddata<int>(2), false);

    DList.PrintList();
}
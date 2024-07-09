#include "YS_Stack.h"

#include <iostream>

stack::stack()
{
    std::cout << "Stack Created!" << std::endl;
}

void stack::Push(int x)
{
    top = new SNode(x, top);
}

void stack::Pop(int& value)
{
    if (IsEmpty())
    {
        std::cout << "Empty Stack" << std::endl;
        return;
    }

    const SNode* CurrentTop = top;
    top = CurrentTop->GetNext();
    value = CurrentTop->GetValue();

    std::cout << "Delete Top Data : \'" << value << "\'" << std::endl;

    delete CurrentTop;
}

int stack::Size(int x)
{
    int Size = 0;
    const SNode* NextTop = top;
    while (NextTop != nullptr)
    {
        Size++;
        NextTop = NextTop->GetNext();
    }

    return Size;
}

bool stack::IsEmpty() const
{
    return top == nullptr;
}

int stack::Top() const
{
    return top != nullptr ? top->GetValue() : -1;
}

void stack::Show_TotalStack()
{
    const SNode* NextTop = top;
    while (NextTop != nullptr)
    {
        std::cout << NextTop->GetValue() << std::endl;
        NextTop = NextTop->GetNext();
    }
}

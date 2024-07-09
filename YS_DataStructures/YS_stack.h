#pragma once
class SNode
{
public:
    int GetValue() const { return value; }
    SNode* GetNext() const { return nextNode; }

    SNode(int val = 0, SNode* newNode = nullptr) { value = val; nextNode = newNode; }
private:

    int value;
    SNode* nextNode;
};

class stack
{
    //  스택은 순서가 보존되는 선형 데이터 구조 유형이다. 가장 마지막 요소부터 처리하는 "후입선출" 매커니즘을 가지고 있다.
    //  장점
    //  1. 동적인 메모리 크기
    //  2. 데이터를 받는 순서대로 정렬된다.
    //  3. 빠른 런타임

    //  단점
    //  1. 가장 최신 요소만 가져온다
    //  2. 한번에 하나의 데이터만 처리 가능하다.

    //  사용 예시) 가장 마지막으로 입력된 것을 순차적으로 바로 처리하고 싶을 때, 브라우저의 뒤로가기, 실행 취소, 재귀

public:
    stack();

    void Push(int x);
    void Pop(int& value);
    int Size(int x);
    bool IsEmpty() const;
    int Top() const;
    void Show_TotalStack();

private:
    SNode* top = nullptr;
};

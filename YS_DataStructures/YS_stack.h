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
    //  ������ ������ �����Ǵ� ���� ������ ���� �����̴�. ���� ������ ��Һ��� ó���ϴ� "���Լ���" ��Ŀ������ ������ �ִ�.
    //  ����
    //  1. ������ �޸� ũ��
    //  2. �����͸� �޴� ������� ���ĵȴ�.
    //  3. ���� ��Ÿ��

    //  ����
    //  1. ���� �ֽ� ��Ҹ� �����´�
    //  2. �ѹ��� �ϳ��� �����͸� ó�� �����ϴ�.

    //  ��� ����) ���� ���������� �Էµ� ���� ���������� �ٷ� ó���ϰ� ���� ��, �������� �ڷΰ���, ���� ���, ���

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

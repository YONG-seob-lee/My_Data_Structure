#pragma once

class QNode
{
public:
	QNode(int value) { Value = value; node = nullptr; }

	int GetValue() { return Value; }
	QNode* GetNode() { return node; }
	void SetNode(QNode* BeforeNode) { node = BeforeNode; }

private:
	int Value;
	QNode* node;
};

class queue
{
	// ť�� ���ð� ��������� ���� ���� �Էµ� ��Ҹ� ó���ϴ� "���Լ���" ��Ŀ������ ������. 
	// ����
	// 1. ������ �޸� ũ��
	// 2. �����͸� �޴� ������� ���ĵȴ�.
	// 3. ���� ��Ÿ��

	// ����
	// 1. ���� ������ ��Ҹ� �����´�
	// 2. �ѹ��� �ϳ��� �����͸� ó�� �����ϴ�.

	// �ݺ����̰� ���� �޴� �����͸� �񵿱������� ó�� �� �� ȿ����
	// ĳ��(Cache) ����, ���� ������ó�� ������ �ΰ��� �����͸� ó���� �� ���

public:
	queue();

	void Push(int x);
	void Pop(int& x);
	bool IsEmpty();
	void Show_TotalQueue();

private:
	void Enqueue(int x);
	void Dequeue(int& x);

	QNode* Back = nullptr;
	QNode* Front = nullptr;
};


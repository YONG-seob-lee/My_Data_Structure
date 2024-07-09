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
	// 큐는 스택과 비슷하지만 가장 먼저 입력된 요소를 처리하는 "선입선출" 매커니즘을 가진다. 
	// 장점
	// 1. 동적인 메모리 크기
	// 2. 데이터를 받는 순서대로 정렬된다.
	// 3. 빠른 런타임

	// 단점
	// 1. 가장 오래된 요소만 가져온다
	// 2. 한번에 하나의 데이터만 처리 가능하다.

	// 반복적이고 자주 받는 데이터를 비동기적으로 처리 할 때 효율적
	// 캐시(Cache) 구현, 음성 데이터처럼 순서에 민감한 데이터를 처리할 때 사용

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


#include "YS_queue.h"
#include <iostream>

queue::queue()
{
	std::cout << "Queue Created!!" << std::endl;
}

void queue::Push(int x)
{
	Enqueue(x);
}

void queue::Pop(int& x)
{
	Dequeue(x);
}

bool queue::IsEmpty()
{
	return Front == nullptr;
}

void queue::Show_TotalQueue()
{
	if (Front == nullptr)
	{
		std::cout << " There is Empty Structure" << std::endl;
		return;
	}
	std::cout << Front->GetValue() << std::endl;

	QNode* NodeItem = Front->GetNode();
	while (NodeItem != nullptr)
	{
		std::cout << NodeItem->GetValue() << std::endl;
		NodeItem = NodeItem->GetNode();
	}
}

void queue::Enqueue(int x)
{
	if (Front == nullptr)
	{
		Front = new QNode(x);
	}
	else
	{
		if (Back == nullptr)
		{
			Back = new QNode(x);
			Front->SetNode(Back);
		}
		else
		{
			QNode* NewBack = new QNode(x);
			Back->SetNode(NewBack);
			Back = NewBack;
		}
	}
}

void queue::Dequeue(int& x)
{
	if (Front == nullptr)
	{
		std::cout << " There is Empty Structure" << std::endl;
		return;
	}

	QNode* NextFront = Front->GetNode();
	if (NextFront == nullptr)
	{
		std::cout << "모든것이 사라졌습니다." << std::endl;
		return;
	}

	x = Front->GetValue();

	delete Front;

	std::cout << "Delete Queue Value : \'" << x << "\'" << std::endl;

	Front = NextFront;
}

#pragma once
#include "iostream"

template <typename T>
struct  Data
{
public:
	Data() {}
	Data(T _data) { data = _data; }
	T GetValue() { return data; }

	void PrintData(int DataCount);

private:
	T data;

public:
	bool operator == (const Data& a)
	{
		return data != a.data;
	}
};

template <typename T>
class LNode
{
public:
	LNode(Data<T> _Data) { data = _Data; NextNode = nullptr; }
	LNode(Data<T> _Data, LNode<T>* _NextNode) { data = _Data, NextNode = _NextNode; }

	Data<T> GetData() { return data; }

	LNode<T>* GetNext() { return NextNode; }

	void SetNextNode(LNode<T>* _NextNode) { NextNode = _NextNode; }
	void DeleteNextNode() { NextNode = nullptr; delete NextNode; }

private:
	Data<T> data;
	LNode<T>* NextNode;

};

template <typename T>
class linkedlist
{
	// 데이터의 물리적 배치를 사용하지 않는 데이터 구조.
	// 인덱스나 위치보다 "참조 시스템" 을 사용.
	// 각 요소는 노드라는 것에 저장, 다음 노드 연결에 대한 포인터 또는 주소가 포함된 또 다른 노드에 저장
	// 모든 노드가 연결된 때까지 반복이 돼서 노드의 연결로 이루어진 자료구조이다.

	// 장점
	// 1. 새로운 요소들의 추가 및 삭제가 용이하고 효율적이다.
	// 2. 배열처럼 메모리에 연속적으로 위치하지 않는다.
	// 3. 배열처럼 구조의 재구성이 필요없다.
	// 4. 동적인 메모리 크기
	// 5. 메모리를 더 효율적으로 쓸 수 있기 때문에 대용량 데이터 처리에 적합

	// 단점
	// 1. 배열보다 메모리를 더 많이 사용한다.
	// 2. 처음부터 끝까지 순회하기 때문에 원하는 값을 비효율적으로 검색,탐색한다.
	// 3. 노드를 반대 방향으로 검색할 때 비효율적이다.(이중 연결 리스트일 떄)

	// 메모리 크기가 정해져 있지 않을 때, 데이터를 연속적으로 빠르게 삽입 및 제거가 필요할 때

public:
	bool CreateList(Data<T> _Data, LNode<T>*& _HeadNode);

	void AddNode(Data<T> _Data);
	void AddNode(Data<T> PrevData, Data<T> _Data);

	void DeleteNode();
	void DeleteNode(Data<T> DeleteData);

	void PrintList();

private:
	inline int GetNodeCount() { return NodeCount; }

	void AddCount(bool bAdd = true);
	LNode<T>* SearchNode(Data<T> _Data, LNode<T>*& PrevNode, LNode<T>*& NextNode);
	LNode<T>* FindLastNode(LNode<T>*& PrevNode);
	LNode<T>* HeadNode = nullptr;
	int NodeCount = 0;

};


template <typename T>
inline void Data<T>::PrintData(int DataCount)
{
	std::cout << "\"Node " << DataCount << " :" << data << "\"  " << std::endl;
}

template <typename T>
inline bool linkedlist<T>::CreateList(Data<T> _Data, LNode<T>*& _HeadNode)
{
	if (HeadNode != nullptr)
	{
		std::cout << " Is Already Created Head!!" << std::endl;
		return false;
	}

	HeadNode = new LNode<T>(_Data);
	_HeadNode = HeadNode;

	AddCount();
	return HeadNode != nullptr;
}

template <typename T>
inline void linkedlist<T>::AddNode(Data<T> _Data)
{
	if (HeadNode == nullptr)
	{
		std::cout << " There is No have Data!!" << std::endl;
		return;
	}
	
	LNode<T>* PrevNode = nullptr;
	LNode<T>* LastNode = FindLastNode(PrevNode);

	if (LastNode)
	{
		LastNode->SetNextNode(new LNode<T>(_Data));
	}
}

template <typename T>
inline void linkedlist<T>::AddNode(Data<T> PrevData, Data<T> _Data)
{
	LNode<T>* TempNode = nullptr;
	LNode<T>* NextNode = nullptr;
	LNode<T>* PrevNode = SearchNode(PrevData, TempNode, NextNode);

	if (PrevNode)
	{
		LNode<T>* TargetNode = new LNode<T>(_Data, NextNode);

		PrevNode->SetNextNode(TargetNode);
	}

}

template <typename T>
inline void linkedlist<T>::DeleteNode()
{
	LNode<T>* PrevNode;
	LNode<T>* LastNode = FindLastNode(PrevNode);

	if (HeadNode == LastNode)
	{
		delete HeadNode;
		HeadNode = nullptr;
		std::cout << "Delete Single Linked List Container!" << std::endl;
		return;
	}

	if (PrevNode)
	{
		PrevNode->SetNextNode(nullptr);
		delete LastNode;
	}

	AddCount(false);
}

template <typename T>
inline void linkedlist<T>::DeleteNode(Data<T> DeleteData)
{
	LNode<T>* PrevNode = nullptr;
	LNode<T>* NextNode = nullptr;
	LNode<T>* TargetNode = SearchNode(DeleteData, PrevNode, NextNode);

	if (TargetNode)
	{
		PrevNode->SetNextNode(NextNode);
		delete TargetNode;
		AddCount(false);
		std::cout << "This Data is Deleted" << std::endl;
	}
	else
	{
		std::cout << "there is no have This Data in structure. Please check Data" << std::endl;
	}
}

template <typename T>
inline void linkedlist<T>::PrintList()
{
	if (HeadNode == nullptr)
	{
		std::cout << "there is no have Structure. Please check Head Node" << std::endl;
		return;
	}
	int NodeCnt = 1;

	HeadNode->GetData().PrintData(NodeCnt);
	NodeCnt++;
	LNode<T>* NextNode = HeadNode->GetNext();

	while (NextNode != nullptr)
	{
		NextNode->GetData().PrintData(NodeCnt);
		NodeCnt++;
		NextNode = NextNode->GetNext();
	}
}

template <typename T>
inline void linkedlist<T>::AddCount(bool bAdd /* = true */)
{
	bAdd ? ++NodeCount : --NodeCount;
}

template <typename T>
inline LNode<T>* linkedlist<T>::SearchNode(Data<T> _Data, LNode<T>*& PrevNode, LNode<T>*& NextNode)
{
	PrevNode = HeadNode;
	NextNode = nullptr;

	LNode<T>* TargetNode = PrevNode->GetNext();

	if (TargetNode == nullptr)
	{
		if (_Data == PrevNode->GetData())
		{
			return PrevNode;
		}
		else
		{
			std::cout << "there is no have This Data in structure. Please check Data" << std::endl;
			return nullptr;
		}
	}

	NextNode = TargetNode->GetNext();

	if (NextNode == nullptr)
	{
		if (TargetNode->GetData() == _Data)
		{
			return TargetNode;
		}
		else
		{
			std::cout << "there is no have This Data in structure. Please check Data" << std::endl;
			return nullptr;
		}
	}

	while (NextNode != nullptr)
	{
		if (TargetNode->GetData().GetValue() == _Data.GetValue())
		{
			return TargetNode;
		}

		PrevNode = TargetNode;
		TargetNode = NextNode;
		NextNode = NextNode->GetNext();
	}

	return nullptr;
}

template<typename T>
inline LNode<T>* linkedlist<T>::FindLastNode(LNode<T>*& PrevNode)
{
	if (HeadNode == nullptr)
	{
		std::cout << "there is no have Structure. Please check Head Node" << std::endl;
		return nullptr;
	}

	PrevNode = HeadNode;
	LNode<T>* LastNode = PrevNode->GetNext();

	if (LastNode == nullptr)
	{
		return HeadNode;
	}

	LNode<T>* EndNode = LastNode->GetNext();
	
	while (EndNode != nullptr)
	{
		PrevNode = LastNode;
		LastNode = EndNode;
		EndNode = LastNode->GetNext();
	}

	return LastNode;
}


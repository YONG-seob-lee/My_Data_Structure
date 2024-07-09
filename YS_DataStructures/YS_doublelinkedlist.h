#pragma once
#include "iostream"

template <typename T>
struct Ddata
{
public:
	Ddata<T>() {}
	Ddata<T>(T _Data) { Data = _Data; }

	void PrintData(int Index);
private:
	T Data;

public:
	bool operator == (const Ddata& Rv)
	{
		return Data == Rv.Data;
	}
	bool operator != (const Ddata& Rv)
	{
		return Data != Rv.Data;
	}
};

template <typename T>
class DLNode
{
public:
	DLNode<T>() {}
	DLNode<T>(Ddata<T> _Data) { Data = _Data; }

	Ddata<T> GetData() { return Data; }
	DLNode<T>* GetNext() { return NextNode; }
	DLNode<T>* GetPrev() { return PrevNode; }

	void SetNext(DLNode<T>* _NextNode) { NextNode = _NextNode; }
	void SetPrev(DLNode<T>* _PrevNode) { PrevNode = _PrevNode; }

	void AddNext(Ddata<T> _Data);
	void AddPrev(Ddata<T> _Data);
private:
	DLNode<T>* PrevNode = nullptr;
	DLNode<T>* NextNode = nullptr;

	Ddata<T> Data;
};

template <typename T>
class doublelinkedlist
{
public:
	bool CreateList(Ddata<T> data);
	void AddNext(Ddata<T> data, bool bAddNext = true);
	void AddNode(Ddata<T> PrevData, bool bAddNext = true);
	void DeleteLast(bool bDeleteEnd = true);
	void DeleteNode(Ddata<T> data);

	void PrintList();

private:
	DLNode<T>* FindNode(Ddata<T> data, bool bStartHead = true);
	bool IsEmpty();
	
	DLNode<T>* HeadNode = nullptr;
	DLNode<T>* EndNode = nullptr;
};

template <typename T>
inline void Ddata<T>::PrintData(int Index)
{
	std::cout << "\" Node (" << Index << ") : " << Data << " \"" << std::endl;
}

template <typename T>
inline void DLNode<T>::AddNext(Ddata<T> _Data)
{
	DLNode<T>* NewNode = new DLNode<T>(_Data);

	if (NextNode != nullptr)
	{
		NewNode->AddNext(NextNode);
		NewNode->AddPrev(this);

		NextNode->PrevNode = NewNode;
	}

	NextNode = NewNode;
}

template <typename T>
inline void DLNode<T>::AddPrev(Ddata<T> _Data)
{
	DLNode<T>* NewNode = new DLNode<T>(_Data);
	if (PrevNode != nullptr)
	{
		PrevNode->AddNext(NewNode);
		DLNode<T>* ThisNode = PrevNode->GetNext();
		NewNode->AddPrev(PrevNode);
		NewNode->AddNext(ThisNode);
	}

	PrevNode = NewNode;
}

template <typename T>
inline bool doublelinkedlist<T>::CreateList(Ddata<T> data)
{
	if (HeadNode || EndNode)
	{
		std::cout << "There is Already Created!" << std::endl;
		return false;
	}

	HeadNode = EndNode = new DLNode<T>(data);
	
	if (HeadNode && EndNode)
	{
		return true;
	}

	return false;
}

template <typename T>
inline void doublelinkedlist<T>::AddNext(Ddata<T> data, bool bAddNext/* = true*/)
{
	if (bAddNext)
	{
		EndNode->AddNext(data);
	}
	else
	{
		HeadNode->AddPrev(data);
	}
}

template <typename T>
inline void doublelinkedlist<T>::AddNode(Ddata<T> PrevData, bool bAddNext/* = true */)
{
	DLNode* PrevNode = nullptr;
	DLNode* NextNode = nullptr;
	FindNode(PrevData, PrevNode, NextNode);


}

template <typename T>
inline void doublelinkedlist<T>::DeleteLast(bool bDeleteEnd /* = true */)
{
	if (IsEmpty())
	{
		std::cout << "There Is Empty" << std::endl;
		return;
	}

	if (HeadNode == EndNode)
	{
		delete HeadNode;
		HeadNode = EndNode = nullptr;
	}

	if (bDeleteEnd)
	{
		DLNode<T>* LastNode = EndNode->GetPrev();
		LastNode->SetNext(nullptr);
		delete EndNode;
		EndNode = LastNode;
	}
	else
	{
		DLNode<T>* NewHeadNode = HeadNode->GetNext();
		NewHeadNode->SetPrev(nullptr);
		delete HeadNode;
		HeadNode = NewHeadNode;
	}
}

template <typename T>
inline void doublelinkedlist<T>::DeleteNode(Ddata<T> data)
{
	DLNode<T>* TargetNode = FindNode(data);
	if (TargetNode == nullptr)
	{
		std::cout << "There is No Data in List. Please Check Data or List" << std::endl;
	}

	DLNode<T>* PrevNode = TargetNode->GetPrev();
	DLNode<T>* NextNode = TargetNode->GetNext();

	if (PrevNode)
	{
		PrevNode->SetNext(NextNode);
	}
	if (NextNode)
	{
		NextNode->SetPrev(PrevNode);
	}

	delete TargetNode;
}

template <typename T>
inline void doublelinkedlist<T>::PrintList()
{
	if (IsEmpty())
	{
		std::cout << "There is No Data!" << std::endl;
		return;
	}
	int NodeCount = 1;
	HeadNode->GetData().PrintData(NodeCount);
	++NodeCount;
	DLNode<T>* NextNode = HeadNode->GetNext();
	while (NextNode != nullptr)
	{
		NextNode->GetData().PrintData(NodeCount);
		++NodeCount;
		NextNode = NextNode->GetNext();
	}
}

template <typename T>
inline DLNode<T>* doublelinkedlist<T>::FindNode(Ddata<T> data, bool bStartHead /* = true */)
{
	if (IsEmpty())
	{
		std::cout << "There Is Empty" << std::endl;
		return nullptr;
	}

	if (HeadNode && HeadNode->GetData() == data)
	{
		return HeadNode;
	}

	if (EndNode && EndNode->GetData() == data)
	{
		return EndNode;
	}

	DLNode<T>* NextNode = bStartHead ? HeadNode->GetNext() : EndNode->GetPrev();
	while (NextNode != nullptr)
	{
		if (NextNode->GetData() == data)
		{
			return NextNode;
		}

		NextNode = bStartHead ? NextNode->GetNext() : NextNode->GetPrev();
	}

	return nullptr;
}

template <typename T>
inline bool doublelinkedlist<T>::IsEmpty()
{
	return HeadNode == nullptr || EndNode == nullptr;
}
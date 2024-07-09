#include "YS_HashTables.h"

#include <iostream>

HashBucket::~HashBucket()
{
    const HashNode* NextNode = HeadNode;
    const HashNode* DeleteNode = nullptr;
    while(DeleteNode != nullptr)
    {
        DeleteNode = NextNode->GetNext();
        delete NextNode;
        NextNode = DeleteNode;
    }
}

void HashBucket::Push(HashNode* Node)
{
    HashNode* NewNode = HeadNode;
    HashNode* NextNode = HeadNode->GetNext();
    NewNode->SetNext(Node);
    Node->SetNext(NextNode);
    
    Count++;
}

HashNode* HashBucket::FindNode(const std::string& Key) const
{
    HashNode* TargetNode = HeadNode;

    while(TargetNode != nullptr)
    {
        if(TargetNode->GetKey() == Key)
        {
            break;
        }
        TargetNode = TargetNode->GetNext();
    }

    return TargetNode;
}

void HashBucket::DeleteNode(const std::string& Key)
{
    HashNode* TargetNode = HeadNode;
    HashNode* PrevNode = nullptr;

    while(TargetNode != nullptr)
    {
        if(TargetNode->GetKey() == Key)
        {
            if(PrevNode)
            {
                PrevNode->SetNext(TargetNode->GetNext());
            }
            else
            {
                HeadNode->SetNext(TargetNode->GetNext());
            }
            delete TargetNode;
            --Count;
            return;
        }

        PrevNode = TargetNode;
        TargetNode = TargetNode->GetNext();
        
    }
}

void HashBucket::Display()
{
    HashNode* Node = HeadNode->GetNext();
    while(Node != nullptr)
    {
        std::cout << Node->GetValue() << "  ";
        Node = Node->GetNext();
    }
}

HashMap::HashMap()
{
    BucketSize = 16;
    Count = 0;
    Bucket = new HashBucket[16];
}

HashMap::HashMap(int _BucketSize)
{
    BucketSize = _BucketSize;
    Count = 0;
    Bucket = new HashBucket[_BucketSize];
}

HashMap::~HashMap()
{
    delete[] Bucket;
}

void HashMap::Insert(const std::string& Key, int Value)
{
    int Hash = HashFunc(Key);

    // 중복된 키 값 찾기
    const HashNode* OverLap = Bucket[Hash].FindNode(Key);

    if(OverLap != nullptr)
    {
        return;
    }

    Bucket[Hash].Push(new HashNode(Key, Value));
    Count++;
}

void HashMap::Delete(const std::string& Key)
{
    int Hash = HashFunc(Key);

    Bucket[Hash].DeleteNode(Key);
    Count--;
}

int HashMap::Find(const std::string& Key)
{
    int Hash = HashFunc(Key);

    HashNode* TargetNode = Bucket[Hash].FindNode(Key);

    if(TargetNode == nullptr)
    {
        std::cout << "Find Fail!\n";
        return -1;
    }

    return TargetNode->GetValue();
}

int HashMap::operator[](const std::string& Key)
{
    int Hash = HashFunc(Key);

    const HashNode* TargetNode = Bucket[Hash].FindNode(Key);

    if(TargetNode == nullptr)
    {
        return -1;
    }

    return TargetNode->GetValue();
}

void HashMap::Display()
{
}


/////////////// Hash Map //////////////////////


int HashMap::HashFunc(const std::string& Key)
{
    int Hash = 401;

    for(int i = 0 ; i < Key.length(); i++)
    {
        Hash = ((Hash << 4) + static_cast<int>(Key[i])) % BucketSize;
    }

    return Hash;
}

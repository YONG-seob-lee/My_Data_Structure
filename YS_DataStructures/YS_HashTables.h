#pragma once
#include <string>

class HashNode
{
public:
    HashNode() : HashKey(""), HashValue(0), NextNode(nullptr) {}
    HashNode(const std::string Key, const int Value) : HashKey(Key), HashValue(Value), NextNode(nullptr) {}

    HashNode* GetNext() const { return NextNode; }
    void SetNext(HashNode* _NextNode) { NextNode = _NextNode; }
    const std::string& GetKey() const { return HashKey; }
    int GetValue() const { return HashValue; }
private:
    std::string HashKey;
    int HashValue;
    HashNode* NextNode;    
    
};

class HashBucket // 해쉬 노드를 담을 연결리스트 버킷
{
public:
    HashBucket() : Count(0), HeadNode(nullptr) { HeadNode = new HashNode(); }
    ~HashBucket();

    const bool& IsEmpty() const { return Count == 0; }
    void Push(HashNode* Node);
    HashNode* FindNode(const std::string& Key) const;
    void DeleteNode(const std::string& Key);
    void Display();
    
private:
    int Count;
    HashNode* HeadNode;
};

class HashMap
{
public:
    HashMap();
    HashMap(int _BucketSize);
    ~HashMap();

    void Insert(const std::string& Key, int Value);
    void Delete(const std::string& Key);
    int Find(const std::string& Key);
    int operator [](const std::string& Key);
    void Display();
    
private:
    int HashFunc(const std::string& Key);

    int BucketSize;
    int Count;
    HashBucket* Bucket;
};
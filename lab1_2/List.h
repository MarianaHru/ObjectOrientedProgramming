#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    int getData() const { return data; }
    Node *getNext() const { return next; }

    void setData(int value) { data = value; }
    void setNext(Node *n) { next = n; }
    void Init(int value)
    {
        data = value;
        next = nullptr;
    }
};

class List
{
private:
    Node *head = nullptr;

public:
    Node *getFirst() const;
    int setFirst(int value);
    bool Init(int value);
    void Read();
    void Display() const;
    void add(int value);
    void remove(int value);
    void sort();
    void clear();
};

List makeList(int value);
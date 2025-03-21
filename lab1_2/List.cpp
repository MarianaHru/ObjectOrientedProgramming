#include "List.h"
#include <iostream>

using namespace std;

int List::setFirst(int value)
{
    if (head == nullptr)
    {
        head = new Node();
        head->Init(value);
    }
    head->setData(value);
}
bool List::Init(int value)
{
    return setFirst(value);
}

void List::Read()
{
    int value;
    char choice;

    cout << "Enter value for the first element: ";
    cin >> value;
    Init(value);

    do
    {
        cout << "Enter value to add to the list: ";
        cin >> value;
        add(value);

        cout << "Do you want to add another value? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void List::Display() const
{
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

void List::add(int value)
{
    Node *newNode = new Node;
    newNode->Init(value);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void List::remove(int value)
{

    if (head->getData() == value)
    {
        Node *temp = head;
        head = head->getNext();
        delete temp;
        return;
    }

    Node *current = head;
    while (current->getNext() != nullptr && current->getNext()->getData() != value)
    {
        current = current->getNext();
    }

    if (current->getNext() != nullptr)
    {
        Node *temp = current->getNext();
        current->setNext(current->getNext()->getNext());
        delete temp;
    }
}

void List::sort()
{
    if (head == nullptr)
        return;

    for (Node *i = head; i != nullptr; i = i->getNext())
    {
        for (Node *j = i->getNext(); j != nullptr; j = j->getNext())
        {
            if (i->getData() > j->getData())
            {
                int temp = i->getData();
                i->setData(j->getData());
                j->setData(temp);
            }
        }
    }
}
void List::clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->getNext();
        delete temp;
    }
}

List makeList(int value)
{
    List l;
    if (!l.Init(value))
    {
        cout << "Error: Failed to initialize the list." << endl;
        exit(EXIT_FAILURE);
    }
    return l;
}
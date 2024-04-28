#include "circularLinkedList.h"
#include <iostream>

CLList::CLList() : head(nullptr), length(0) {}

CLList::~CLList()
{
    CLLNode* cur = head;
    CLLNode* nextNode = nullptr;

    for (int i = 0; i < length; ++i)
    {
        nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
}

int CLList::getLength() const
{
    return length;
}

bool CLList::search(int val) const
{
    CLLNode* cur = head;

    for (int i = 0; i < length; ++i)
    {
        if (val == cur->data)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void CLList::insertAtBeg(int val)
{
    CLLNode* newNode = new CLLNode(val);

    if (!head)
    {
        head = newNode;
        newNode->next = newNode;
    }
    else
    {
        CLLNode* cur = head;

        for (int i = 0; i < length - 1; ++i)
        {
            cur = cur->next;
        }

        cur->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    ++length;
}

void CLList::insertAtIndex(int val, int index)
{
    if (index < 0 || index > length)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    else if (index == 0)
    {
        insertAtBeg(val);
    }
    else if (index == length)
    {
        insertAtEnd(val);
    }
    else
    {
        CLLNode* newNode = new CLLNode(val);
        CLLNode* cur = head;

        for (int j = 0; j < index - 1; ++j)
        {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        ++length;
    }
}

void CLList::insertAtEnd(int val)
{
    CLLNode* newNode = new CLLNode(val);

    if (!head)
    {
        head = newNode;
        newNode->next = newNode;
    }
    else
    {
        CLLNode* cur = head;
        for (int i = 0; i < length - 1; ++i)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->next = head;
    }
    ++length;
}

void CLList::deleteAtBeg()
{
    if (!head)
    {
        return;
    }
    else if (!head->next)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        CLLNode* tmp = head -> next;
        head -> next = tmp -> next;
        delete tmp;
    }
    --length;
}

void CLList::deleteAtIndex(int index)
{
    if (index < 0 || index >= length)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    else if (index == 0)
    {
        deleteAtBeg();
    }
    else if (index == length - 1)
    {
        deleteAtEnd();
    }
    else
    {
        CLLNode* cur = head;

        for (int j = 0; j < index - 1; ++j)
        {
            cur = cur->next;
        }

        CLLNode* tmp = cur->next;
        if(tmp != nullptr)
         {
               cur->next = tmp->next; // reconnect the list
              delete tmp; // free memory at the deletion point
            --length;  
        }
        
    }
}

void CLList::deleteAtEnd()
{
    if (!head)
    {
        return;
    }
    else if (!head->next)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        CLLNode* cur = head;
        CLLNode* prev = nullptr;

        while (cur->next != head)
        {
            prev = cur;
            cur = cur->next;
        }

        std::cout << "Deleting node with data: " << cur->data << std::endl; // Debugging output

        prev->next = head; // Update the previous node's next pointer to point to the new head.
        delete cur;
    }
    --length;
}

CLLNode* CLList::getHead() const
{
    return head;
}
void CLList::display() const
{
    if (!head)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    CLLNode* cur = head;
    do {
        std::cout << cur->data << ' ';
        cur = cur->next;
    } while (cur != head);

    std::cout << std::endl;
}

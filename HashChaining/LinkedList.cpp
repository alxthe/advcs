//*****************************************************************
//  LinkedList.cpp
//  HashTable

//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#include "LinkedList.h"

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
    head = NULL;
    length = 0;
}

// Inserts an item at the end of the list.
void LinkedList::insert( Element * newElement )
{
  if (head == nullptr) {
    head = newElement;
    length++;
    return;
  }

  Element * current = head;
  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = newElement;
  length++;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
bool LinkedList::remove( string Key )
{
  Element * current = head;
  if (current->key == Key) {
    delete current;
    length--;
    return true;
  }
  Element * previous = nullptr;
  while (current->next != nullptr && current->key != Key) {
      previous = current;
      current = current->next;
  }
  if (current == nullptr) {
    return false;
  }
  if (Key != current->key)
    return false;

  previous->next = current->next;
  delete current;
  length--;
  return true;
  
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
Element * LinkedList::get( string Key )
{
  Element * current = head;
  while (current != nullptr) {
    if (current->key == Key) {
      return current;
    }
    current = current->next;
  }
  return nullptr;
}

// Displays list contents to the console window.
void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Element * p = head;
    Element * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        //if (p != head)
        if (p != nullptr)
        {
            cout << p -> key;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
  Element * cur = this->head;
  while (cur) {
    this->head = cur->next;
    this->length -= 1;
    delete cur;
    cur = this->head;
  }
}

//*****************************************************************
// End of File
//*****************************************************************
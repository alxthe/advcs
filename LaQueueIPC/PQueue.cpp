/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 

PQueue::PQueue() {
  front = nullptr;
}

*/
		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	node* newNode = new node;
  newNode->data = item;
  newNode->priority = priority;
  newNode->link = nullptr;

  if (!front || priority > front->priority) {
    newNode->link = front;
    front = newNode;
  } 
  
  else {
    node* current = front;

     while (current->link && current->link->priority >= priority) {
      current = current->link;
     }

    newNode->link = current->link;
    current->link = newNode;
  }
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	if (front) {
    return front->data;
  }
  else {
    return nullptr;
  }
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	if (front) {
    node* temp = front;
    front = front->link;
    delete temp;
  }
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

  node* current = front;
  while (current) {
    std::cout << "Priority: " << current->priority << ", Data: " << current->data << std::endl;
  }
	
	/* Use the following out command for the data */
	std::cout<<current->priority<<" "<<(char*)current->data<<std::endl;

}
	
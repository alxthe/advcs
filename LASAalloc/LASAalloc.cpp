	/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * 		LASAalloc.h
	 * 		LASAalloc class declaration.  
	 * 
	 * 		Do not change this file other than to add local varaibles and Functions.
	 *    Make any changes only in the provided block.
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include<iostream>
#include<stdlib.h>
#include "LASAalloc.h"

// Defines for LASAalloc buffer simulation.  
// Keep it simple, no changes to program break
#define INITIAL_MALLOC_SIZE 100000
#define MAX_MALLOC_SIZE 100000


using namespace std;

//typedef unsigned char BYTE_t;

LASAalloc::LASAalloc()
{
	brk(INITIAL_MALLOC_SIZE);
	
	// Point to where first node will be located.
	block* firstBlock = (block*)bufferBase;
	freeList = firstBlock;
  
	// Configure first node on freeList
	firstBlock->size = (int)(bufferSize);
	firstBlock->prev_block = nullptr;
	firstBlock->next_block = nullptr; 
	firstBlock->this_block_data = (void*)((long long int)bufferBase+(long long int)sizeof(block)); 
	firstBlock->freeFlag = true; 
	
	// Show initial statistics
	cout<<"buffer Allocation: "<< bufferBase << " - " << brk(0) << endl;
	cout<<"freeList: "<< freeList << " - " << brk(0) << endl;
	cout<<"Block header size " << sizeof(block) << endl;
	cout<<"integer size " << sizeof(int) << endl;
	
	display_node(freeList);

}

LASAalloc::~LASAalloc()
{
}

 

void LASAalloc::display_node(struct block *p)
{
		cout << "Prev: " << p->prev_block;
		cout << "\tNext: " << p->next_block;
		cout << "\tFree: " << p->freeFlag;
		cout << "\tSize: " << p->size;
		cout << "\tThis: " << p->this_block_data << endl;
		cout << endl;	
}

void LASAalloc::display(struct block *begin)
{
	struct block *p;
	if(begin==NULL)
	{
		cout<<"List is empty\n";
		return;
	}
	p=begin;
	cout<<"List is :\n";
	while(p!=NULL)
	{
		display_node(p);
		p=p->next_block;
	}
	cout<<"\n";
}

//two display functions!
void LASAalloc::display() {
  struct block *p;
  if (freeList == NULL) {
    cout << "List is empty\n";
    return;
  }
  p = freeList;
  cout << "List is :\n";
  while (p != NULL) {
    if (p->freeFlag)
      display_node(p);
    p = p->next_block;
  }
  cout << "\n";
}

//there is a lot of code in comments because i saved all my previous work as something to use and work off of, just reminders for myself :)

void* LASAalloc::lalloc(int size)
{
  block * temp = (block*) findFit(size);
  temp->freeFlag = false;

  if (size < (temp->size - 32)) 
    split(temp, size);

  return temp->this_block_data;
}


void LASAalloc::lfree(void* userBlock)
{

  block* x = this->freeList;

  while (x->freeFlag || x->this_block_data != userBlock) {
    x = x->next_block;
  }
  x->freeFlag = true;

  //coalescing

  while (x && x->freeFlag) {
    if (x->next_block && x->next_block->freeFlag) {
      if (x->next_block->next_block) {
        x->next_block->next_block->prev_block = x;
      }
    x->size = x->size + x->next_block->size + 32;
      x->next_block = x->next_block->next_block;
    }

    if (x->prev_block && x->prev_block->freeFlag) {
      x->prev_block->size = x->prev_block->size + x->size + 32;
      if(x->next_block) {
        x->next_block->prev_block = x->next_block;
      }
       x->prev_block->next_block = x->next_block;
      x = x->prev_block;
    }
    x = x->next_block;
  }
}

void* LASAalloc::findFit(int size)
{
  
  block *tim = this->freeList;
  bool ifFound = true;
  
  while (!(tim->freeFlag && tim->size > size + sizeof(block))) {
    if (tim->next_block) {
      tim = tim->next_block;
    }
    else {
      ifFound = false;
      break;
    }
  }

  if (!ifFound) {
    while (!(tim->freeFlag && tim->size >= size)) {
      if (tim->next_block)
        tim = tim->next_block;
      else
        break;
    }
  }
  
  return tim;
}

void* LASAalloc::split(block* target, int size)
{
  
  block* timmy = (block*)((long long int)target + (long long int)size + 32); ///adding 32 to target to get to the next block
  timmy->freeFlag = true;
  timmy->prev_block = target;
  timmy->size = target->size - size - 32;
  

  if (target->next_block) {
    timmy->next_block = target->next_block;
  }
  else {
    timmy->next_block = nullptr;
  }
  
  target->next_block = timmy;
  target->size = size;
  timmy->this_block_data = (void*)((long long int)target + (long long int)size + 32 + 32);
  return timmy;
}
 


/*
 *   >>>>>>  DO NOT CHANGE THIS SECTION  <<<<<<<
 * 
 * brk()
 * Function to simulate the libc brk() function to allocate memory for a buffer
 * 
 */

void * LASAalloc::brk(int size)
{
	
	if (size !=0)
	{
		if (bufferBase == 0)
		{
			bufferBase = malloc(size);
			bufferSize = size;
		}
		else
		{
			cout<<"buffer already locked/n";
			return 0;
		}
		
	}
	return (void*)((long long int)bufferSize + (long long int)bufferBase); 
}
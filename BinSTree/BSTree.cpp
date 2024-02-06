/*
 * Binary Search Tree class
 * Do not alter the display() function, this will break the Repl.it 
 * tests
 */

 
#include <iostream>
#include <cstdlib>
#include "BSTree.h"

using namespace std;


 
/*
 * Find Element in the Tree
 * find a node by item_key and provide an updated parent node
 *   pointer and location node pointer
 */
 
 
void BST::find(int item_key, node **prnt, node **loc)
{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *prnt = NULL;
        return;
    }
    if (item_key == root->key_value)
    {
        *loc = root;
        *prnt = NULL;
        return;
    }
    if (item_key < root->key_value)
        ptr = root->p_left;
    else
        ptr = root->p_right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item_key == ptr->key_value)
        {
            *loc = ptr;
            *prnt = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item_key < ptr->key_value)
            ptr = ptr->p_left;
      	else
	          ptr = ptr->p_right;
    }  
    *loc = NULL;
    *prnt = ptrsave;
}
 
/*
 * Inserting Element into the Tree
 */
void BST::insert(node *tree, node *newnode)
{
    // if (we are at root)
    if (root == NULL)
    {
        root = newnode;
        // Just create a single node for root to point to,
        //    with all the data in it.
        return;
    }
    // if (there is already a node with our key value)
    if (tree->key_value == newnode->key_value)
    {
        //Just return
        return;
    }
    
    //if (the new node is less than the current node)
    if (newnode->key_value < tree->key_value)
    {
        //if (see if something is already a child on the left)
        if (tree->p_left != NULL)
        {
            // if so, the recurse insert at this subtree 	
            insert(tree->p_left, newnode);
      	}
      	else
      	{
            // otherwise the new node goes here as a leaf (ie no children)
            tree->p_left = newnode;
            return;
        }
    }
    else  // it must be to the right
    {
        //if (is there already a child on right?)
        if (tree->p_right != NULL)
        {
             // if so, the recurse insert at this subtree 
            insert(tree->p_right, newnode);
        }
        else
        {
            // otherwise the new node goes here as a leaf (ie no children)
            tree->p_right = newnode;
            return;
        }	
    }
}
 
/*
 * Delete Element from the tree
 */
void BST::remove(int item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
  
    //if (there is no child on left or right)
    if (location->p_left == NULL && location->p_right == NULL)
        case_0(parent, location);
    //if (there is one child on left only)
    if (location->p_left != NULL && location->p_right == NULL)
        case_1(parent, location);
    //if (there is one child on right only)
    if (location->p_left == NULL && location->p_right != NULL)
        case_1(parent, location);
   // if (there are childred on left and right)
    if (location->p_left != NULL && location->p_right != NULL)
        case_2(parent, location);
    //free(location);
}
 
/*
 * Case 0
 * the node is simply removed no other updates necessary.
 */
void BST::case_0(node *prnt, node *loc )
{
    //if (we are at the root)
    if (prnt == NULL)
    {
        //update the root
        root = NULL;
    }
    else
    {
      // otherwise simply remove node
      if (loc == prnt->p_left)
        prnt->p_left = NULL;
      else
        prnt->p_right = NULL;
    }

  //delete loc;
  
}
 
/*
 * Case 1
 * We have only one child so promote the child and replace the target
 * node
 */
void BST::case_1(node *prnt, node *loc)
{
    node *child;
    //if (the child is on the left?)
    if (loc->p_left != NULL) {
        //point left
        child = loc->p_left;
        //loc = child;
    }
   // else  // must be the right side has child
    else {
        //point right
        child = loc->p_right;
        //loc = child;
    }
    //if (we are at the root handle specialy)
    if (prnt == NULL)
    {
       // update the root
      root = child;
    }
    
    else
    {
        //if (the node is left child of parent)
        if (prnt->p_left == loc)
            //promote the left
            prnt->p_left = child;
        //else // the node is right of parent
        else {
        //    promote right 
          prnt->p_right = child;
        }
    }

  //delete loc;
  
}
 
/*
 * Case case_2
 * We have to find and promote a successor or predecessor
 */
void BST::case_2(node *prnt, node *loc)
{
    // temporary pointers for node we are manipulating
    node *successor = loc->p_right;
    node *sucParent = loc;

    // Find successor: Step to the right child !!!!!!!!

    // Find the min of the subtree on parent's right !!!!!
  while (successor->p_left != NULL)
    {
        sucParent = successor;
        successor = successor->p_left;
    }
    

    //if (found node has no children)
    if (successor->p_left == NULL && successor->p_right == NULL)
    {
      // Replace the target node with the successor node
        //loc->key_value = successor->key_value;
        //sucParent->p_left = successor->p_right;

      successor->p_left = loc->p_left;
    }

      
    else {

      remove(successor->key_value);
        // Temporarily remove the successor node by replacing it with its right child, we will replace the node we are remove with the successor we just removed.
 
      successor->p_left = loc->p_left;
      successor->p_right = loc->p_right;
    
    }

   if (prnt == NULL) //loc or NULL
    {
          //then update root
     root = successor;
  }

  else
    {
      // Insert the successor node where the target node we
        if(prnt->p_left == loc) {
            prnt->p_left = successor;
          //   are removing is located
        }
        else 
          {
            prnt->p_right = successor;
          }

    }
    // then update the successor child pointers to reflect the old 
    //     target's child pointers.
    // loc->p_left = successor->p_left;
    // loc->p_right = successor->p_right;
  //delete successor;
}
 

/*
 * Display Tree Structure
 */
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->p_right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->key_value;
        display(ptr->p_left, level+1);
    }
}


/*
*  Node.cpp -- Node class for recursive List, Lab 8, CS 223
*
*  <student name>
*  <date created>
*/

#include <iostream>
#include "Node.h"

using namespace std;

// Global variables for exception strings to be thrown
extern const string EXC_OUT_OF_BOUNDS = "Index-out-of-bounds exception!";
extern const string EXC_LIST_NOT_ORDERED = "List-not-ordered exception!";

// ##### BASIC FUNCTIONALITY ##### //

/*
*  No destructor for Node class.
*
*  List class will deallocate Node storage in the List destructor.
*
*  Test your List operations for memory leaks using valgrind
*
*  Your Node operations might seem to have memory leaks, but as long as
*  they don't cause List to have memory leaks, that is OK.  Node is not
*  meant to be a stand-alone class.
*/

// *** Getters *** //
Person Node::getData() const
{
    return data;
}
Node * Node::getRest() const
{
    return rest;
}

// ** Setters *** //
void Node::setData(Person P)
{
    data = P;
}
void Node::setRest(Node * ptr)
{
    rest = ptr;
}

/*
*  @function      append a Person to the end of this list
*  @param         Person P
*
*  Note: MUST be implemented with recursion.
*/
void Node::append(Person P)
{
   if (rest == NULL)
   {
       Node *newNode = new Node(P, NULL);
       rest = newNode;
   }
   else
   {
       rest->append(P);
   }
}

/*!
*  @function      retrieve the Person at the given index
*  @param         int n - relative index of item to retrieve from this list
*  @precondition  0 <= n < length
*  @return        Person at index n
*  @exception     throw string EXC_OUT_OF_BOUNDS if index `n` is positive
*                 and `rest` is NULL
*
*  Note: List.retrieve will handle case n < 0, so *assume* n >= 0.
*
*  Note: Do NOT use size() method to implement this method.
*
*  Note: MUST be implemented with recursion.
*/
Person Node::retrieve(int n) const
{
    if (n == 0)
    {
        return data;
    }
    else
    {
        if (n > 0 && rest == NULL)
        {
            throw EXC_OUT_OF_BOUNDS;
        }
        return rest->retrieve(n-1);
    }
}

// ##### ADDITIONAL FUNCTIONALITY ##### //

/*!
*  @function         setElementAt
*  @param            int n - index at which to set a new Person value
*  @precondition     0 <= n < length
*  @param            Person P
*  @exception        throw string EXC_OUT_OF_BOUNDS if index is too large
*
*  Note:  List class is responsible for ensuring n >= 0. Don't test for
*  it here.
*
*  Note:  Each node believes itself to be at index 0 (relative to its own
*  list), so setElementAt(0, P) will store P in the current node.
*
*  Note: MUST be implemented with recursion.
*
*  Note: Do NOT use size() method to implement this method.
*/
void Node::setElementAt(int n, Person P)
{
    if (n == 0)
    {
        setData(P);
    }
    else
    {
        if (n > 0 && rest == NULL)
        {
            throw EXC_OUT_OF_BOUNDS;
        }
        return rest->setElementAt(n-1, P);
    }
}

/*!
*  @function      size
*  @return        int - number of nodes in this list
*
*  Note: MUST be implemented with recursion.
*/
int Node::size() const
{
    if (rest == NULL)
    {
        return 1;
    }
    else
    {
        return rest->size() + 1;
    }
}

/*!
*  @function         insertAt
*  @param            int n - index at which to insert
*  @precondition     1 <= n <= length
*  @param            Person P - to be inserted
*  @exception        throw string EXC_OUT_OF_BOUNDS if index is too large
*
*  Note:  List class is responsible for ensuring n > 0. Don't test for
*  it here.
*
*  Note:  Each node believes itself to be at index 0 (relative to its own
*  list), so insertAt(1, P) will insert P immediately AFTER the current node.
*
*  Note: MUST be implemented with recursion.
*
*  Note: Do NOT use size() method to implement this method.
*/
void Node::insertAt(int n, Person P)
{
    if (n == 1)
    {
        Node *newNode = new Node(P, rest);
        rest = newNode;
    }
    else
    {
        if (n > 0 && rest->rest == NULL)
        {
            throw EXC_OUT_OF_BOUNDS;
        }
        rest->insertAt(n-1, P);
    }
}

/*!
*  @function      removeFrom - delete a node for a given index
*  @param         int n - relative index (this node is index 0)
*  @return        Person - data from the deleted node
*  @precondition  1 <= n < length
*  @exception     throw string EXC_OUT_OF_BOUNDS if index is out
*                 of bounds
*
*  Note: List.removeFrom will handle the cases n < 0 and n == 0.
*
*  Note: Do NOT use size() method to implement this method.
*
*  Note: MUST be implemented with recursion.
*/
Person Node::removeFrom(int n)
{
    if (n == 1)
    {
        Person hold = rest->data;
        Node *temp = rest;
        rest = rest->rest;
        delete temp;
        return hold;
    }
    else
    {
        if (rest == NULL)
        {
            throw EXC_OUT_OF_BOUNDS;
        }
        return rest->removeFrom(n-1);
    }
}

// ##### ORDER-BASED FUNCTIONALITY ##### //

/*!
*  @function      isOrdered
*  @return        bool - return true iff this list is in ascending order:
*                 for each i, j with 0 <= i < j < length, retrieve(i) is
*                 less than or equal to retrieve(j)
*
*  Note: MUST be implemented with recursion.

*/
bool Node::isOrdered() const
{
    if(rest == NULL)
    {
        return true;
    }
    else
    {
        if(rest->data < data)
        {
            return false;
        }
        rest->isOrdered();
    }
}

/*!
*  @function      orderedInsert - for an ordered list, inserts a given
*                 Person into its proper place to maintain ascending order
*  @param         Person P
*  @precondition  list is ordered
*  @postcondition P is inserted into list and list is still ordered
*
*  Note: List.orderedInsert will throw string EXC_LIST_NOT_ORDERED if
*  precondition fails -- node should *assume* list is ordered.
*
*  Note: If the new Person needs to go before all the nodes of a given List,
*  List.orderedInsert will handle that insertion -- node should *assume*
*  that the data in this node is less than (or equal to) `P`.
*
*  Note: MUST be implemented with recursion.
*/
void Node::orderedInsert(Person P)
{
    if (rest == NULL)
    {
        append(P);
    }
    else if (P < rest->data)
    {
        Node *newNode = new Node(P, rest);
        rest = newNode;
    }
    else
    {
        rest->orderedInsert(P);
    }
}

// ##### OPERATOR OVERLOADS ##### //

/*!
*  @function      equivalence operator
*                 compare two lists for logical equivalence
*  @param         Node other - head node for the list to be compared with
*  @return        bool - return true iff this list and other list are
*                 logically equivalent (same contents, same order)
*
*  Note: Do not use size() method.
*
*  Note: MUST be implemented with recursion.
*/
bool Node::operator==(const Node &other)
{
    if (rest == NULL && other.rest == NULL)
    {
        return true;
    }
    else if(data == other.data)
    {
        return *rest == *other.rest;
    }
    else
    {
        return false;
    }
}

/**
* stream output operator
* Write information from a list to an output stream.
*
* If this node heads a list of length 2 where Tom Brady is stored in this
* node's data field and Russell Wilson is stored in the node after this one,
* then the output message would look EXACTLY as follows:
*
* Person: Tom Brady, age 37\n
* Person: Russell Wilson, age 26\n
*
* Note: MUST be implemented with recursion.
*/
ostream& operator<< (ostream &out, const Node &node)
{
    out << node.getData();
    if (node.getRest()!= NULL)
    {
        out << *(node.getRest());
        return out;
    }
}

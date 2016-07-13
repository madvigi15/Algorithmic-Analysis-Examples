/*
 *  List.cpp for Lab 8, recursive list class
 *
 *  < student name >
 *  < date created >
 */

#include <cassert>
#include <string>
#include <iostream>
#include <sstream>
#include "List.h"

using namespace std;

extern const string EXC_OUT_OF_BOUNDS;
extern const string EXC_LIST_NOT_ORDERED;

 // ###### Basic Functionality ###### //

/*!
*  Constructor with 0 parameters - initialize an empty list
*/
List::List()
{
    head = NULL;
}

/*!
*  Destructor - test it indirectly using valgrind
*/
List::~List()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->rest;
        delete current;
        current = next;
    }
}

/*
*  @function      append a Person to the end of the list
*  @param         Person P
*
*  Note: You MUST use Node.append in this implementation.
*/
void List::append(Person P)
{
    if (head == NULL)
    {
        Node *newNode = new Node(P, NULL);
        head = newNode;
    }
    else
    {
        head->append(P);
    }
}

/*!
*  @function         retrieve the Person at the given index
*  @param            int n - index of item to retrieve from the list
*  @precondition     0 <= n < length
*  @return           Person at index n (counting from 0)
*  @exception        throw string EXC_OUT_OF_BOUNDS if index is out
*                    of bounds
*
*  Note: You MUST use Node.retrieve in this implementation.
*
*  Note: Do NOT use size() method to implement this method.
*/
Person List::retrieve(int n) const
{
    if (n < 0 || isEmpty())
    {
        throw EXC_OUT_OF_BOUNDS;
    }
    else
    {
       return head->retrieve(n);
    }
}

/*!
*  @function         isEmpty
*  @return           bool - true if the list is empty; otherwise, false
*
*  Note: For efficiency reasons, do NOT use either version of size() here
*/
bool List::isEmpty() const
{
    if ( head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

 // ######### Additional Functionality ######### //

/*!
*  @function      copy constructor
*  @param         List other - the list to be duplicated
*
*  Note:  The new list is an independent copy of `other`.  Subsequent
*  changes to one of the lists will *not* change the other.
*
*  Note:  You are not required to use recursion for implementing this method.
*/
List::List(const List &other)
{
    head = NULL;
    Node *temp = other.head;
    for (int i = 0; i < other.size(); i++)
    {
        append(temp->data);
        temp = temp->rest;
    }
}

/*!
*  @function         setElementAt
*  @param            int n - index at which to set a new Person value
*  @precondition     0 <= n < length
*  @param            Person P
*  @postcondition    size of list is unchanged; element at index `n` is `P`
*  @exception        throw string EXC_OUT_OF_BOUNDS if index is out
*                    of bounds
*
*  Note: You MUST use Node.setElementAt in this implementation.
*
*  Note: Do NOT use size() method to implement this method.
*/
void List::setElementAt(int n, Person P)
{
    if(n < 0 || isEmpty())
    {
        throw EXC_OUT_OF_BOUNDS;
    }
    else
    {
        head->setElementAt(n, P);
    }
}

/*!
    return head->size();
*  @function         size
*  @return           int - number of elements in this list
*
*  Note: You MUST use Node.size in this implementation.
*/
int List::size() const
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return head->size();
    }
}

/*!
*  @function         insertAt
*  @param            int n - index at which to insert
*  @precondition     0 <= n <= length
*  @param            Person P -  to be inserted
*  @postcondition    size of list is increased by 1; element at index `n`
*                    is `P`, all other elements are in their original
*                    relative to each other
*  @exception        throw string EXC_OUT_OF_BOUNDS if index is out
*                    of bounds
*
*  Note: You MUST use Node.insertAt in this implementation.
*
*  Note: Do NOT use size() method to implement this method.
*/
void List::insertAt(int n, Person P)
{
    if(n < 0 || isEmpty())
    {
        throw EXC_OUT_OF_BOUNDS;
    }
    else if(n == 0)
    {
        Node *newNode = new Node(P, head);
        head = newNode;
    }
    else
    {
        head->insertAt(n, P);
    }
}

/*!
*  @function         removeFrom
*  @param            int n - index from which to remove
*  @return           Person - the element which was removed
*  @precondition     0 <= n < length
*  @exception        throw string EXC_OUT_OF_BOUNDS if index is out
*                    of bounds
*
*  Note: You MUST use Node.removeFrom in this implementation.
*
*  Note: Do NOT use size() method to implement this method.
*/
Person List::removeFrom(int n)
{
    if(n < 0 || isEmpty())
    {
        throw EXC_OUT_OF_BOUNDS;
    }
    else if(n == 0)
    {
        Person hold = head->data;
        Node *temp = head;
        head = head->rest;
        delete temp;
        return hold;
    }
    else
    {
        return head->removeFrom(n);
    }
}

/*!
*  @function         isOrdered
*  @return           bool - return true iff the List is in ascending order:
*                    for each i, j with 0 <= i < j < length, retrieve(i) is
*                    less than or equal to retrieve(j)
*
*  Note: Return true if the list is empty.
*
*  Note: You MUST use Node.isOrdered in this implementation.
*/
bool List::isOrdered() const
{
    if ( head == NULL)
    {
        return true;
    }
    else
    {
        return head->isOrdered();
    }
}

/*!
*  @function         orderedInsert - for an ordered List, inserts a given
*                    Person into its proper place to maintain ascending order
*  @param            Person P
*  @precondition     List is ordered
*  @postcondition    P is inserted into List and List is still ordered
*  @exception        throw string EXC_LIST_NOT_ORDERED if precondition fails
*
*  Note: You MUST use Node.orderedInsert in this implementation.
*
*  Note: Do NOT use size() method to implement this method.
*/
void List::orderedInsert(Person P)
{
    if (isOrdered()==false)
    {
        throw EXC_LIST_NOT_ORDERED;
    }
    else if (head == NULL)
    {
        append(P);
    }
    else if (P < head->data)
    {
        Node *newNode = new Node(P, head);
        head = newNode;
    }
    else
    {
        head->orderedInsert(P);
    }
}

// ##### OPERATOR OVERLOADS ##### //

/*!
*  @function      equivalence operator
*                 compare two List objects for logical equivalence
*  @param         List other - the list to be compared with
*  @return        bool - return true iff this list and other List have
*                 equal lengths and, for all i with 0 <= i < length,
*                 the ith Person in this list and the ith Person in
*                 `other` are equivalent (==).
*
*  Note: You MUST use Node.operator== in this implementation.
*
*  Implementation note:  DO NOT use Node.size().
*/
bool List::operator==(const List &other)
{
    if (head==NULL && other.head==NULL)
    {
        return true;
    }
    else if (head != NULL && other.head ==NULL)
    {
        return false;
    }
    else if (head == NULL && other.head != NULL)
    {
        return false;
    }
    else
    {
        return *head == *(other.head);
    }
}

/*!
*  @function      inequivalence operator
*                 compare two List objects for logical inequivalence
*  @param         List other - the list to be compared with
*  @return        bool - return true iff this list and other List are
*                 NOT equivalent (==)
*
*  Implementation note:  Do NOT use Node.size().  DO USE either
*  Node.operator== or List.operator==.
*/
bool List::operator!=(const List &other)
{
    return !(*this == other);
}

// ######### Stream I/O Operator Overriding ######### //

/**
*  stream output operator
*  Write information from a list to an output stream.
*
*  If list L has length two, if L[0] is a Person with full name "Tom Brady" and
*  age 37, and if L[1] is a Person with full name "Russell Wilson" and age 26,
*  then the output message for L would look EXACTLY as follows (where '\n'
*  indicates line breaks -- two breaks in a row after the last Person):
*
*  List of size 2\n
*  Person: Tom Brady, age 37\n
*  Person: Russell Wilson, age 26\n\n
*
*  If L is empty, then the output message for L would look like:
*
*  List of size 0\n
*
*  Note:  You MUST use the Node output stream operator in this implementation.
*
*/
ostream& operator<< (ostream &out, const List &L)
{
    if (L.head == NULL)
    {
        return out << "List of size 0" << endl;
    }
    else
    {
        out << "List of size " << L.size() << endl;
        out << *(L.head);
        return out;
    }
}

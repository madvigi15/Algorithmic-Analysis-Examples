/*
* List.cpp
* Ian Madvig
* < current date >
* Lab 7, CS 223:  Circular doubly-linked list with sentinel.
*/

#include <sstream>
#include <string>
#include <iostream>
#include <cctype>
#include "List.h"    // List.h includes Node.h and Person.h

using namespace std;

// Global variable for exception string to be thrown
extern const string EXC_INDEX_OUT_OF_BOUNDS = "Index-out-of-bounds exception!";
extern const string EXC_LIST_NOT_ORDERED = "List-not-ordered exception!";

// Global Person variable for data field of sentinel node
const Person sentinel("Sentinel","Node");

// ###### Basic Functionality ###### //

/*!
*  Constructor with 0 parameters - initialize an empty list
*  An empty List has just one node (the sentinel).
*/
List::List()
{
    head = new Node(sentinel);
    head->next = head;
    head->prev = head;
}

/*!
*  Destructor - test it indirectly by checking for memory leaks
*/
List::~List()
{
    while (isEmpty()==false)
    {
        removeFrom(0);
    }
}

/*
*  @function      append a Person to the end of the list
*  @param         Person P
*/
void List::append(Person P)
{
    Node *temp = new Node(P);

    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
}

/*!
*  @function      retrieve the Person at the given index
*  @param         int n - index of item to retrieve from the list
*  @precondition  0 <= n < length
*  @return        Person at index n (counting from 0)
*  @exception     throw string EXC_INDEX_OUT_OF_BOUNDS if index is out
*                 of bounds
*/
Person List::retrieve(int n) const
{
    if (n < 0)
    {
        throw EXC_INDEX_OUT_OF_BOUNDS;
    }
    Node *temp;
    temp = head->next;
    for(int i = 0; i < n; i++)
    {
        if(temp == head)
        {
          throw EXC_INDEX_OUT_OF_BOUNDS;
        }
        temp = temp->next;
    }
    return temp->data;
}

/*!
*  @function      isEmpty
*  @return        bool - true if the list is empty; otherwise, false
*  Note:  Implement this in an efficient way (don't count all the nodes,
*                 just compare pointers)
*/
bool List::isEmpty() const
{
    if (head->prev == head)
    {
        return true;
    }
    return false;
}
// ######### Additional Functionality ######### //

/*!
*  @function      indexOf Person
*  @param         Person P
*  @return        int - leftmost index of P in the list, or -1 if not found
*/
int List::indexOf(Person P) const
{
    Node *temp = head->next;
    int i = 0;
    while (temp != head)
    {
        if (temp->data == P)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

/*!
*  @function      set element at given index to the given Person
*                 (replace the previous Person at that index)
*  @param         int n - index
*  @precondition  0 <= n < length [NOTE: different from lab 4]
*  @param         Person P
*  @exception     throw string EXC_INDEX_OUT_OF_BOUNDS if index is out
*                 of bounds
*/
void List::setElementAt(int n, Person P)
{
    if (n < 0)
    {
        throw EXC_INDEX_OUT_OF_BOUNDS;
    }
    Node *temp = head->next;
    for (int i = 0; i < n; i++)
    {
        if (temp == head)
        {
            throw EXC_INDEX_OUT_OF_BOUNDS;
        }
        temp = temp->next;
    }
    temp->data = P;
}

/*!
*  @function      insertAt
*  @param         int n - index at which to insert
*  @precondition  0 <= n < length
*  @param         Person P -  to be inserted
*  @exception     throw string EXC_INDEX_OUT_OF_BOUNDS if index is out
*                 of bounds
*/
void List::insertAt(int n, Person P)
{
    if (n < 0)
    {
        throw EXC_INDEX_OUT_OF_BOUNDS;
    }
    Node *temp = head->next;
    for (int i = 0; i < n; i++)
    {
        if (temp == head)
        {
            throw EXC_INDEX_OUT_OF_BOUNDS;
        }
        temp = temp->next;
    }
    Node *node = new Node(P);
    node->next = temp;
    node->prev = temp->prev;
    temp->prev->next = node;
    temp->prev = node;
}

/*!
* @function       remove leftmost occurrence of a Person from the list
* @param          Person P
* @return         int - index of P before removal, or -1 if not found
*/
int List::remove(Person P)
{
    Node *temp = head->next;
    int acc = 0;
    while (temp != head)
    {
        if (temp->data == P)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return acc;
        }
        acc++;
        temp = temp->next;
    }
    return -1;
}

/*!
*  @function      removeFrom
*  @param         int n - index from which to remove
*  @return        Person - the element which was removed
*  @precondition  0 <= n < length
*  @exception     throw string EXC_INDEX_OUT_OF_BOUNDS if index is out
*                 of bounds
*/
Person List::removeFrom(int n)
{
    if (n < 0)
    {
        throw EXC_INDEX_OUT_OF_BOUNDS;
    }
    Person hold;
    Node *temp;
    temp = head->next;
    for(int i = 0; i < n; i++)
    {
        if(temp == head)
        {
          throw EXC_INDEX_OUT_OF_BOUNDS;
        }
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    hold = temp->data;
    delete temp;
    return hold;
}

/*!
* @function      isOrdered
* @return        bool - return true iff the List is in ascending order:
*                for each i, j with 0 <= i < j < length, retrieve(i) is
*                less than or equal to retrieve(j)
* Note: Return true if the list is empty.
*/
bool List::isOrdered() const
{
    if (isEmpty()==true)
    {
        return true;
    }
    Node *temp = head->next;
    while (temp->next != head)
    {
       temp = temp->next;
       if (temp->data < temp->prev->data)
       {
           return false;
       }
   }
    return true;
}

/*!
* @function      orderedInsert - for an ordered List, inserts a given
*                Person into its proper place to maintain ascending order
* @param         Person P
* @precondition  List is ordered
* @postcondition P is inserted into List and List is still ordered
* @exception     throw string EXC_LIST_NOT_ORDERED if precondition fails
*/
void List::orderedInsert(Person P)
{
    if (isEmpty()==true)
    {
        append(P);
    }
    if (isOrdered()==false)
    {
        throw EXC_LIST_NOT_ORDERED;
    }
    int acc = 0;
    Node *temp = head->next;
    bool stop = false;
    while (temp != head && stop == false)
    {
        if (P < temp->data)
        {
            insertAt(acc, P);
            stop = true;
        }
        acc++;
    }
}

// ######### Required Class Functionality ######### //

/*!
*  Copy constructor
*  @param         List other - the list to be duplicated
*  Note:  The new list is an independent copy of `other`.  Subsequent
*  changes to one of the lists will *not* change the other.
*/
List::List(const List &other)
{
    head = new Node(sentinel);
    head->next = head;
    head->prev = head;

    Node *temp = other.head->next;
    while (temp != other.head)
    {
        append(temp->data);
        temp = temp->next;
    }
}

/*!
* @function       assignment operator
*                 copy the data from a given List to this list
* @param          List other - the list to be copied from
* @return         List& - returns (by reference) this list
* Implementation hint:  See the Cents::operator= code at
* http://www.learncpp.com/cpp-tutorial/911-the-copy-constructor-and-
* overloading-the-assignment-operator/
*/
List& List::operator=(const List &other)
{
    while(isEmpty()==false)
    {
        removeFrom(0);
    }
    List newList(other);
    head->next = newList.head->next;
    return *this;
}

// ######### (In)Equivalence Operator Overriding ######### //

/*!
* @function       equivalence operator
*                 compare two List objects for logical equivalence
* @param          List other - the list to be compared with
* @return         bool - return true iff this list and other List have
*                 equal lengths and, for all i with 0 <= i < length,
*                 the ith Person in this list and the ith Person in
*                 `other` are equivalent (==).
* Implementation note:  DO NOT calculate the list lengths.
*/
bool List::operator==(const List &other)
{
    Node *temp1, *temp2;
    temp1 = head->next;
    temp2 = other.head->next;
    bool compare = true;
    while (compare == true)
    {
        if (temp1 == head && temp2 == other.head)
        {
            compare = false;
        }
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else //if (temp1->data != temp2->data)
        {
            return false;
        }
    }
    return true;
}

/*!
* @function       inequivalence operator
*                 compare two List objects for logical inequivalence
* @param          List other - the list to be compared with
* @return         bool - return true iff this list and other List are
*                 NOT equivalent (==)
*/
bool List::operator!=(const List &other)
{
   return !(*this == other);
}

// ######### Stream I/O Operator Overriding ######### //

/**
* stream output operator
* Write information from a list to an output stream.
*
* If list L has length two, if L[0] is a Person with full name "Tom Brady" and
* age 37, and if L[1] is a Person with full name "Russell Wilson" and age 26,
* then the output message for L would look EXACTLY as follows (where '\n'
* indicates line breaks -- two breaks in a row after the last Person):
*
* List\n
* Person: Tom Brady, age 37\n
* Person: Russell Wilson, age 26\n\n
*
* If L is empty, then the output message for L would look like:
*
* Empty List\n
*
*/
ostream& operator<< (ostream &out, const List &L)
{
    if (L.isEmpty()==true)
    {
        out << "Empty List" << endl;
    }
    else
    {
        out << "List" << endl;
        Node *temp = L.head;
        temp = (*temp).getNext();
        while (temp != L.head)
        {
            out << (*temp).getData();
            temp = (*temp).getNext();
        }
    }
    return out;
}

/**
* stream input operator
* Replace the current contents of `L` with new elements based on the
* information read from the input stream `in`.
*
* Return (by reference) the instream `in`.
*
* Hint:  Assume the information in `in` is formatted EXACTLY as for the
* stream output operator.
*
* Hint:  Remember to remove all the elements that are in the list before
* adding the new elements.
*/
istream& operator>> (istream &in, List &L)
{
    while ( L.isEmpty()==false)
    {
        L.removeFrom(0);
    }
    string hold, junk;
    getline(in, junk);
    bool stop = false;
    while (stop == false)
    {
        getline(in, hold);
        if (hold.length()==0)
        {
            stop = true;
        }
        else
        {
            Person P;
            stringstream temp;
            temp << hold;
            temp >> P;
            L.append(P);
        }
    }
    return in;
}

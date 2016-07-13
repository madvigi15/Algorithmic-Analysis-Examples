/*
 *  List.h:  Recursive List class for CS 223 Lab 8
 *  Node class is a friend!  You need to use the Node methods to implement the
 *  List methods.
 *
 *  Created:  March 14, 2015
 *  Author:  Barb Wahl
 *
 *  DO NOT CHANGE THIS FILE
 */

#ifndef LIST_H_LAB8
#define LIST_H_LAB8

#include "Node.h" // Node.h includes Person.h

class List
{
   private:

      /*
      *  Instance Variable
      *  Every List has a pointer to its head node
      */
      Node * head;

      /*!
      * List assignment operator is disabled by making it private.
      *  DO NOT IMPLEMENT.  DO NOT USE.
      */
      List& operator=(const List &other);

   public:

      // ###### Basic Functionality ###### //

      /*!
      *  Constructor with 0 parameters - initialize an empty list
      */
      List();

      /*!
      *  Destructor - test it indirectly using valgrind
      */
      ~List();

      /*
      *  @function      append a Person to the end of the list
      *  @param         Person P
      *
      *  Note: You MUST use Node.append in this implementation.
      */
      void append(Person P);

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
      Person retrieve(int n) const;

      /*!
      *  @function         isEmpty
      *  @return           bool - true if the list is empty; otherwise, false
      *
      *  Note: For efficiency reasons, do NOT use either version of size() here
      */
      bool isEmpty() const;

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
      List(const List &other);

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
      void setElementAt(int n, Person P);

      /*!
      *  @function         size
      *  @return           int - number of elements in this list
      *
      *  Note: You MUST use Node.size in this implementation.
      */
      int size() const;

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
      void insertAt(int n, Person P);

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
      Person removeFrom(int n);

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
      bool isOrdered() const;

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
      void orderedInsert(Person P);

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
      bool operator==(const List &other);

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
      bool operator!=(const List &other);

      // declare stream IO operators to be friends
      friend ostream & operator<<(ostream &out, const List &L);
};

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
ostream& operator<< (ostream &out, const List &L);



#endif /* LIST_H_LAB8 */
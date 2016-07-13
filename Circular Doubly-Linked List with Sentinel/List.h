/*
*  List.h
*  Header file for CS 223, Lab 7
*
*  Created by:   Barb Wahl, Feb 14, 2015
*  Modified by:  Barb Wahl and Theresa Wilson, March 2015
*  Modified by:  < student name , date >
*
*  List is a circular, doubly-linked list with sentinel node.
*  Exceptions are thrown to indicate error conditions.
*/

#ifndef List_H_lab7
#define List_H_lab7

#include "Node.h" // Node.h includes Person.h

class List
{
   private:

      /*
      *  Instance Variable
      *  Every List has a pointer (called `head`) to its sentinel node.
      */
      Node * head;

      // ###### Private Methods Section ###### //
      /*
      *  Declare any private helper methods here.
      */

   public:

      // ###### Basic Functionality ###### //

      /*!
      *  Constructor with 0 parameters - initialize an empty list
      *  An empty List has just one node (the sentinel).
      */
      List();

      /*!
      *  Destructor - test it indirectly by checking for memory leaks
      */
      ~List();

      /*
      *  @function      append a Person to the end of the list
      *  @param         Person P
      */
      void append(Person P);

      /*!
      *  @function      retrieve the Person at the given index
      *  @param         int n - index of item to retrieve from the list
      *  @precondition  0 <= n < length
      *  @return        Person at index n (counting from 0)
      *  @exception     throw string EXC_OUT_OF_BOUNDS if index is out
      *                 of bounds
      */
      Person retrieve(int n) const;

      /*!
      *  @function      isEmpty
      *  @return        bool - true if the list is empty; otherwise, false
      *  Note:  Implement this in an efficient way (don't count all the nodes,
      *                 just compare pointers)
      */
      bool isEmpty() const;

      // ######### Additional Functionality ######### //

      /*!
      *  @function      indexOf Person
      *  @param         Person P
      *  @return        int - leftmost index of P in the list, or -1 if not found
      */
      int indexOf(Person P) const;

      /*!
      *  @function      set element at given index to the given Person
      *                 (replace the previous Person at that index)
      *  @param         int n - index
      *  @precondition  0 <= n < length [NOTE: different from lab 4]
      *  @param         Person P
      *  @exception     throw string EXC_OUT_OF_BOUNDS if index is out
      *                 of bounds
      */
      void setElementAt(int n, Person P);

      /*!
      *  @function      insertAt
      *  @param         int n - index at which to insert
      *  @precondition  0 <= n < length
      *  @param         Person P -  to be inserted
      *  @exception     throw string EXC_OUT_OF_BOUNDS if index is out
      *                 of bounds
      */
      void insertAt(int n, Person P);

      /*!
      * @function       remove leftmost occurrence of a Person from the list
      * @param          Person P
      * @return         int - index of P before removal, or -1 if not found
      */
      int remove(Person P);

      /*!
      *  @function      removeFrom
      *  @param         int n - index from which to remove
      *  @return        Person - the element which was removed
      *  @precondition  0 <= n < length
      *  @exception     throw string EXC_OUT_OF_BOUNDS if index is out
      *                 of bounds
      */
      Person removeFrom(int n);

      /*!
      * @function      isOrdered
      * @return        bool - return true iff the List is in ascending order:
      *                for each i, j with 0 <= i < j < length, retrieve(i) is
      *                less than or equal to retrieve(j)
      * Note: Return true if the list is empty.
      */
      bool isOrdered() const;

      /*!
      * @function      orderedInsert - for an ordered List, inserts a given
      *                Person into its proper place to maintain ascending order
      * @param         Person P
      * @precondition  List is ordered
      * @postcondition P is inserted into List and List is still ordered
      * @exception     throw string EXC_LIST_NOT_ORDERED if precondition fails
      */
      void orderedInsert(Person P);

      // ######### Required Class Functionality ######### //

      /*!
      *  Copy constructor
      *  @param         List other - the list to be duplicated
      *  Note:  The new list is an independent copy of `other`.  Subsequent
      *  changes to one of the lists will *not* change the other.
      */
      List(const List &other);

      /*!
      * @function       assignment operator
      *                 copy the data from a given List to this list
      * @param          List other - the list to be copied from
      * @return         List& - returns (by reference) this list
      * Implementation hint:  See the Cents::operator= code at
      * http://www.learncpp.com/cpp-tutorial/911-the-copy-constructor-and-
      * overloading-the-assignment-operator/
      */
      List& operator=(const List &other);

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
      bool operator==(const List &other);

      /*!
      * @function       inequivalence operator
      *                 compare two List objects for logical inequivalence
      * @param          List other - the list to be compared with
      * @return         bool - return true iff this list and other List are
      *                 NOT equivalent (==)
      */
      bool operator!=(const List &other);

      // declare stream I/O operators to be friends of List
      friend ostream & operator<< (ostream &out, const List &L);
      friend istream &  operator>> (istream &in, List &L);

};  // end of class

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
ostream& operator<< (ostream &out, const List &L);

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
istream& operator>> (istream &in, List &L);


#endif /* List_H_lab7 */

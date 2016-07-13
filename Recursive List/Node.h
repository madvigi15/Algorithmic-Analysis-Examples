/*
*  Node.h -- Node class for recursive List, Lab 8, CS 223
*
*  In a recursive list implementation, the nodes are "smart" and "dual-natured".
*
*  Each node considers itself to be the first node of the list which consists
*  of the current node and all nodes which follow it.  These nodes have list
*  functionality (append, retrieve, setElementAt, size, etc.); all of the
*  node-list methods are implemented RECURSIVELY.
*
*  Because this class is only to be used by List, everything except basic
*  functionality is declared private.
*
*  Created:  March 14, 2015
*  Author:   Barb Wahl
*
*  DO NOT CHANGE THIS FILE
*/

#ifndef NODE_H_LAB8
#define NODE_H_LAB8

#include "Person.h"

class Node
{
   public:

      // ##### BASIC FUNCTIONALITY ##### //

      /*!
      *  Constructor with 2 parameters
      *  @param      Person P - to be stored in `data`
      *  @param      Node * ptr - to be stored in `rest`
      *  Note: already implemented with the following code.
      */
      Node (Person P, Node * ptr) : data(P) { rest = ptr; }

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
      Person getData() const;
      Node * getRest() const;

      // ** Setters *** //
      void setData(Person P);
      void setRest(Node * ptr);

      /*
      *  @function      append a Person to the end of this list
      *  @param         Person P
      *
      *  Note: MUST be implemented with recursion.
      */
      void append(Person P);

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
      Person retrieve(int n) const;

   private:

      // Instance variables
      Person data; // Person stored in this node / head of this list
      Node * rest; // pointer to first node of the rest of this list

      /*!
      *  Node copy constructor is disabled by making it private.
      *  DO NOT IMPLEMENT.  DO NOT USE.
      */
      Node(const Node &other);

      /*!
      *  Node assignment operator is disabled by making it private.
      *  DO NOT IMPLEMENT.  DO NOT USE.
      */
      Node& operator=(const Node &other);

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
      void setElementAt(int n, Person P);

      /*!
      *  @function      size
      *  @return        int - number of nodes in this list
      *
      *  Note: MUST be implemented with recursion.
      */
      int size() const;

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
      void insertAt(int n, Person P);

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
      Person removeFrom(int n);

      // ##### ORDER-BASED FUNCTIONALITY ##### //

      /*!
      *  @function      isOrdered
      *  @return        bool - return true iff this list is in ascending order:
      *                 for each i, j with 0 <= i < j < length, retrieve(i) is
      *                 less than or equal to retrieve(j)
      *
      *  Note: MUST be implemented with recursion.

      */
      bool isOrdered() const;

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
      void orderedInsert(Person P);

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
      bool operator==(const Node &other);

      // FRIENDS
      friend class List;
};

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
ostream& operator<< (ostream &out, const Node &node);






#endif /* NODE_H_LAB8 */
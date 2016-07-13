/*
* Node.h
* Node header file for CS 223, Lab 7
*
* Authors: Theresa Wilson & Barb Wahl
* Date:    March, 2015
*
* NOTE: DO NOT MODIFY THIS FILE!
* NOTE: Do not create Node.cpp, there are no methods for it to implement.
*/

#ifndef NODE_H_lab7
#define NODE_H_lab7

#include "Person.h" // from previous labs

class Node
{
   private:
      // Instance variables
      Person data;
      Node * prev;
      Node * next;

   public:
      /*!
      *  Constructor with 1 parameter -- initializes the `data` field
      *  @param      P - Person object to be stored by the Node
      */
      Node(Person P) : data(P) {}

       // *** Getters *** //
      Person getData() const { return data; }
      Node * getNext() const { return next; }
      Node * getPrev() const { return prev; }

   // ######### Friends can access private data ######### //
   friend class List;
};

#endif /* NODE_H_lab7 */

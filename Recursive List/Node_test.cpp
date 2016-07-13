/*
   Node_test.cpp
   Lab 8 Recursive List
   Unit Tests for Node class
   Provided for free!

   DO NOT write unit tests for the private Node methods.
*/

#include <cassert>
#include <iostream>
#include <sstream>
#include "Node.cpp"
#include "Person.cpp"


using namespace std;

void test_basic_functionality()
{
   // testing: Node(), getters, setters, append, retrieve
   // non-exceptional inputs only
   Person P;
   Person Q("Donald", "Duck", 10);
   Person Z("Ziggy", "Wilson", 5);
   Node n1(P, NULL);
   assert(n1.getData() == P);
   assert(n1.getRest() == NULL);
   n1.setData(Q);
   assert(n1.getData() == Q);
   n1.setRest(&n1);
   assert(n1.getRest() == &n1);
   n1.setRest(NULL);
   n1.append(P);
   n1.append(Z);  // [Q, P, Z]
   assert(n1.retrieve(0) == Q);
   assert(n1.retrieve(1) == P);
   assert(n1.retrieve(2) == Z);
}

int main()
{
   test_basic_functionality();
   cout << "Basic Node functions seem OK" << endl;
   return 0;
}

/*
   List_test.cpp
   Lab 8 Recursive List
   Unit Tests for List class

   < student name >
   < date >
*/

#include <cassert>
#include <iostream>
#include <sstream>
#include "List.cpp"
#include "Node.cpp"
#include "Person.cpp"

using namespace std;

//extern const string EXC_OUT_OF_BOUNDS = "Index-out-of-bounds exception!";
//extern const string EXC_LIST_NOT_ORDERED = "List-not-ordered exception!";

// Declare global Person objects here, for use in testing

void test_basic_functionality()
{
   // testing: List(), append, retrieve, isEmpty
   // non-exceptional inputs only
   List L;
   Person p1("Ian", "Madvig", 22);
   Person p2("Donald", "Glover", 31);
   Person p3 = Person();
   L.isEmpty();
   assert(L.isEmpty());
   L.append(p1);
   assert(L.isEmpty()==false);
   L.append(p2);
   assert(L.isEmpty()==false);
   L.append(p3);
   assert(L.isEmpty()==false);
   assert(L.retrieve(0)==p1);
   assert(L.isEmpty()==false);
   assert(L.retrieve(1)==p2);
   assert(L.isEmpty()==false);
   assert(L.retrieve(2)==p3);
   assert(L.isEmpty()==false);
}

void test_copy_constructor()
{
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    L.append(p1);
    L.append(p2);
    L.append(p3);

    List L2(L);
    assert(L2.isEmpty()==false);
    assert(L.retrieve(0)==L2.retrieve(0));
    assert(L.retrieve(1)==L2.retrieve(1));
    assert(L.retrieve(2)==L2.retrieve(2));

    List L3;
    List L4(L3);
    assert(L3.isEmpty());
    assert(L4.isEmpty());
}

void test_setElementAt()
{
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    L.append(p1);
    L.append(p2);
    L.append(p3);
    L.setElementAt(1, p1);
    assert(L.retrieve(0)==p1);
    assert(L.retrieve(1)==p1);
    assert(L.retrieve(2)==p3);
}

void test_size()
{
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    assert(L.size()==0);
    L.append(p1);
    assert(L.size()==1);
    L.append(p2);
    assert(L.size()==2);
    L.append(p3);
    assert(L.size()==3);
}

void test_insertAt()
{
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    L.append(p1);
    L.append(p2);
    L.append(p3);
    L.insertAt(1, p2);
    assert(L.retrieve(1)==p2);
    assert(L.retrieve(2)==p2);
    assert(L.size()==4);

    L.insertAt(0, p2);
    assert(L.retrieve(0)==p2);
    assert(L.retrieve(1)==p1);
    assert(L.size()==5);

    L.insertAt(4, p1);
    assert(L.retrieve(4)==p1);
    assert(L.retrieve(5)==p3);
    assert(L.size()==6);
}

void test_removeFrom()
{
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    L.append(p1);
    L.append(p2);
    L.append(p3);
    L.removeFrom(1);
    assert(L.retrieve(0)==p1);
    assert(L.retrieve(1)==p3);
    assert(L.size()==2);

    L.removeFrom(0);
    assert(L.retrieve(0)==p3);
    assert(L.size()==1);

    L.removeFrom(0);
    assert(L.size()==0);
}

void test_isOrdered()
{
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    L.append(p1);
    L.append(p2);
    L.append(p3);
    assert(L.isOrdered()==false);

    List L2;
    L2.append(p3);
    L2.append(p2);
    L2.append(p1);
    assert(L2.isOrdered());

    List L3;
    assert(L3.isOrdered());
}

void test_orderedInsert()
{
    List L2;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    Person p4("Z", "Z", 0);
    L2.append(p3);
    L2.append(p2);
    L2.append(p1);
    assert(L2.isOrdered());
    L2.orderedInsert(p1);
    assert(L2.isOrdered());
    assert(L2.retrieve(3)==p1);
    assert(L2.retrieve(2)==p1);
    assert(L2.size()==4);
    L2.orderedInsert(p4);
    assert(L2.isOrdered());
    assert(L2.size()==5);
    assert(L2.retrieve(4)==p4);
    assert(L2.retrieve(0)==p3);

    List L;
    L.orderedInsert(p1);
    assert(L.isOrdered());
    L.orderedInsert(p3);
    assert(L.isOrdered());
}

void test_equivalence_inequivalence()
{
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    L.append(p1);
    L.append(p2);
    L.append(p3);

    List L2;
    L2.append(p1);
    L2.append(p2);
    L2.append(p3);

    assert(L==L2);
}

void test_stream_output()
{
    stringstream out1, out2;
    List L, L2;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    L.append(p1);
    L.append(p2);
    L.append(p3);

    string correct = "List of size 3\nPerson: Ian Madvig, age 22\nPerson: Donald Glover, age 31\nPerson: Jane Doe, age 0\n";
    out1 << L;
    assert(out1.str()==correct);

    out2 << L2;
    correct = "List of size 0\n";
    assert(out2.str()==correct);

}

void test_EXC_OUT_OF_BOUNDS()
{
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();

    //retrieve
    //index out of bounds
    try
    {
        L.retrieve(-1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
    //list is empty
    try
    {
        L.retrieve(2);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
    //index out of list's scope
    L.append(p1);
    L.append(p2);
    L.append(p3);
    try
    {
        L.retrieve(10);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }

    //setElementAt
    //index out of bounds
    try
    {
        L.setElementAt(-1, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
    //index out of list's scope
    try
    {
        L.setElementAt(7, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
    //list is empty
    List L2;
    try
    {
        L2.setElementAt(7, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }

    //insertAt
    //index out of bounds
    try
    {
        L.insertAt(-1, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
    //index out of list's scope
    try
    {
        L.insertAt(7, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
    //list is empty
    try
    {
        L2.insertAt(7, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }

    //removeFrom
    //index out of bounds
    try
    {
        L.removeFrom(-1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
    //index out of list's scope
    try
    {
        L.removeFrom(7);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
    //list is empty
    try
    {
        L2.removeFrom(7);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_OUT_OF_BOUNDS);
    }
}

void test_EXC_LIST_NOT_ORDERED()
{
    //isOrdered equals false
    List L;
    Person p1("Ian", "Madvig", 22);
    Person p2("Donald", "Glover", 31);
    Person p3 = Person();
    L.append(p1);
    L.append(p2);
    L.append(p3);

    try
    {
        L.orderedInsert(p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_LIST_NOT_ORDERED);
    }
}

int main()
{
   test_basic_functionality();
   cout << "basics ok" << endl;

   test_copy_constructor();
   cout << "copy constr ok" << endl;

   test_setElementAt();
   cout << "setElementAt ok" << endl;

   test_size();
   cout << "size ok" << endl;

   test_insertAt();
   cout << "insertAt ok" << endl;

   test_removeFrom();
   cout << "removeFrom ok" << endl;

   test_isOrdered();
   cout << "isOrdered ok" << endl;

   test_orderedInsert();
   cout << "orderedInsert ok" << endl;

   test_equivalence_inequivalence();
   cout << "equiv ok" << endl;

   test_stream_output();
   cout << "<< OK" << endl;

   test_EXC_OUT_OF_BOUNDS();
   cout << "EXC_OUT_OF_BOUNDS ok" << endl;

   test_EXC_LIST_NOT_ORDERED();
   cout << "EXC_LIST_NOT_ORDERED ok" << endl;

   cout << "all tests passing!" << endl;
   return 0;
}

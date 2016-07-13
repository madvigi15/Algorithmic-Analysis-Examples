/*
* List_test.cpp
* Ian Madvig
* < date >
* Lab 7, CS 223:  Circular doubly-linked list with sentinel.
* Unit Tests for List class
*/

#include <cassert>
#include <iostream>
#include <sstream>
#include "Person.cpp"
#include "List.cpp"

using namespace std;

void test_basic_functionality()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    assert(l1.isEmpty());
    l1.append(p1);
    l1.append(p2);
    l1.append(p3);
    assert(l1.retrieve(0) == p1);
    assert(l1.retrieve(1) == p2);
    assert(l1.retrieve(2) == p3);
}

void test_indexOf()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    assert(l1.indexOf(p1)==0);
    assert(l1.indexOf(p2)==1);
    assert(l1.indexOf(p3)==2);

    List l2;

    assert(l2.indexOf(p1)==-1);

    Person p4("XYZ", "ABC", 0);

    assert(l1.indexOf(p4)==-1);
}

void test_setElementAt()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    l1.setElementAt(2,p1);
    assert(l1.retrieve(2)==p1);
}

void test_insertAt()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    l1.insertAt(0, p1);
    assert(l1.retrieve(0)==p1);

    l1.insertAt(3,p1);
    assert(l1.retrieve(3)==p1);

    List l2;

    l2.insertAt(0,p1);
    assert(l2.retrieve(0)==p1);
}

void test_remove()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    assert(l1.remove(p2)==1);
    assert(l1.retrieve(1)==p3);

    Person p4("XYZ", "ABC", 0);
    assert(l1.remove(p4)==-1);
}

void test_removeFrom()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    assert(l1.removeFrom(0)==p1);
    assert(l1.retrieve(0)==p2);

}

void test_isOrdered()
{
    List l1;
    assert(l1.isOrdered());
    Person p1("Z", "Z", 0);
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    assert(l1.isOrdered()==false);

    List l2;
    assert(l2.isOrdered());
    l2.append(p3);
    l2.append(p2);
    l2.append(p1);
    assert(l2.isOrdered());
}

void test_orderedInsert()
{
    List l1;
    assert(l1.isOrdered());
    Person p1("Z", "Z", 0);
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p3);
    l1.append(p2);
    l1.append(p1);
    assert(l1.isOrdered());

    Person p4("Childish", "Gambino", 31);

    l1.orderedInsert(p4);
    assert(l1.isOrdered());
}

void test_copy_constr()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    List l2(l1);

    assert(l2.retrieve(0)==l1.retrieve(0));
    assert(l2.retrieve(1)==l1.retrieve(1));
    assert(l2.retrieve(2)==l1.retrieve(2));
}

void test_assignment()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    List l2;

    l2.append(p1);
    l2.append(p3);

    l2 = l1;

    assert(l2.retrieve(0)==l1.retrieve(0));
    assert(l2.retrieve(1)==l1.retrieve(1));
    assert(l2.retrieve(2)==l1.retrieve(2));
}

void test_equality_inequality()
{
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);

    List l2;

    l2.append(p1);
    l2.append(p2);
    l2.append(p3);

    assert(l1==l2);

    List l3;

    l3.append(p3);
    l3.append(p2);
    l3.append(p1);

    assert(l1!=l3);
}

void test_EXC_INDEX_OUT_OF_BOUNDS()
{
    List L;
    // retrieve exception tests
    try
    {
        L.retrieve(-1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_INDEX_OUT_OF_BOUNDS);
    }
    Person p1 = Person();
    L.append(p1);
    L.append(p1);
    try
    {
        L.retrieve(7);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_INDEX_OUT_OF_BOUNDS);
    }

    //setElementAt exception tests
    try
    {
        L.setElementAt(-1, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_INDEX_OUT_OF_BOUNDS);
    }
    try
    {
        L.setElementAt(7, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_INDEX_OUT_OF_BOUNDS);
    }

    //insertAt exception tests
    try
    {
        L.insertAt(-1, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_INDEX_OUT_OF_BOUNDS);
    }
    try
    {
        L.insertAt(7, p1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_INDEX_OUT_OF_BOUNDS);
    }

    //removeFrom exception tests
    try
    {
        L.removeFrom(-1);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_INDEX_OUT_OF_BOUNDS);
    }
    try
    {
        L.removeFrom(7);
        assert(false);
    }
    catch(string e)
    {
        assert(e == EXC_INDEX_OUT_OF_BOUNDS);
    }
}

void test_EXC_LIST_NOT_ORDERED()
{
    List L;
    Person p1("Z", "Z", 0);
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

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
        assert(e==EXC_LIST_NOT_ORDERED);
    }
}

void test_stream_output()
{
    stringstream out1, out2;
    List l1;
    Person p1 = Person();
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);

    l1.append(p1);
    l1.append(p2);
    l1.append(p3);
    string correct = "List\nPerson: Jane Doe, age 0\nPerson: Ian Madvig, age 22\nPerson: Donald Glover, age 31\n";

    out1 << l1;
//    cout << l1;
//    cout << correct;
    assert(out1.str()==correct);

    List l2;
    out2 << l2;
    correct = "Empty List\n";
    assert(out2.str()==correct);
}

void test_stream_input()
{
    stringstream in;
    in << "List\nPerson: Jane Doe, age 0\nPerson: Ian Madvig, age 22\nPerson: Donald Glover, age 31\n\n";
    List L;
    Person p1("Jane", "Doe", 0);
    Person p2("Ian", "Madvig", 22);
    Person p3("Donald", "Glover", 31);
    in >> L;
//    cout << L;
    assert(L.retrieve(0)==p1);
    assert(L.retrieve(1)==p2);
    assert(L.retrieve(2)==p3);
}

int main()
{
 // insert testing function calls here
    test_basic_functionality();
    cout << "Basic Functionality Passed" << endl;
    test_indexOf();
    cout << "IndexOf Functionality Passed" << endl;
    test_setElementAt();
    cout << "SetElementAt Functionality Passed" << endl;
    test_insertAt();
    cout << "InsertAt Functionality Passed" << endl;
    test_remove();
    cout << "Remove Functionality Passed" << endl;
    test_removeFrom();
    cout << "RemoveFrom Functionality Passed" << endl;
    test_isOrdered();
    cout << "IsOrdered Functionality Passed" << endl;
    test_orderedInsert();
    cout << "OrderedInsert Functionality Passed" << endl;
    test_copy_constr();
    cout << "Copy Constructor Functionality Passed" << endl;
    test_assignment();
    cout << "Assignment Overload Functionality Passed" << endl;
    test_equality_inequality();
    cout << "Equality Inequality Functionality Passed" << endl;
    test_EXC_INDEX_OUT_OF_BOUNDS();
    cout << "Exception: Index Out of Bounds Functionality Passed" << endl;
    test_EXC_LIST_NOT_ORDERED();
    cout << "Exception: Non-ordered List Functionality Passed" << endl;
    test_stream_output();
    cout << "IOStream Output Functionality Passed" << endl;
    test_stream_input();
    cout << "IOStream Input Functionality Passed" << endl;
    return 0;
}


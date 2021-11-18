// list_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ListNode.h"
#include "my_list.h"
#include <list>
#include "my_list_iterator.h"
#include <algorithm>
using namespace std;
int main()
{
    // TODO: implement code for question 1 and question 2 here. Answer the questions in the ReadMe.txt file
    
    my_list* l = new my_list;
    l->push_back(1);
    l->push_back(2);
    l->push_back(3);
    //my_list* l_copy = new my_list(*l);

    my_list* l_copy = new my_list(*l);


    
 
    
    cout << "l size: "<< l->get_size() << endl;
    cout << "l_copy size: " << l_copy->get_size() << endl;
    cout << "l first: " << l->back() << endl;
    cout << "l_copy first: " << l_copy->back()<< endl;

    delete l;
    delete l_copy;
    

    /*
    Question1:
    
    list<int> l1 = { 1,2,3,4,5 };
    list<int> l2;
    l2 = l1;
    cout << "l1 is: ";
    for (int n : l1) {
        cout << n << " ";
    }
    cout << endl;

    cout << "l2 is: ";
    for (int n : l2) {
        cout << n << " ";
    }

    cout << "After l1 push back 6 into the list" << endl;

    l1.push_back(6);

    cout << "l1 is: ";
    for (int n : l1) {
        cout << n << " ";
    }
    cout << endl;

    cout << "l2 is: ";
    for (int n : l2) {
        cout << n << " ";
    }
    */
    
    /*
    Question2:
    my_list* l1 = new my_list;
    l1->push_back(1);
    l1->push_back(4);
    l1->push_back(3);
    if (is_sorted(l1->begin(), l1->end()))
    {
        cout << "list one Sorted!" << endl;
    }

    else {
        cout << "list one Not Sorted!" << endl;
    }
    delete l1;

    my_list* l2 = new my_list;
    l2->push_back(1);
    l2->push_back(2);
    l2->push_back(3);
    if (is_sorted(l2->begin(), l2->end()))
    {
        cout << "list two Sorted!" << endl;
    }

    else {
        cout << "list two Not Sorted!" << endl;
    }
    delete l2;
    */

    return 0;
}



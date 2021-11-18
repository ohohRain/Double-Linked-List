Exam Assignment ReadMe

Name:Yuxing(Rain) Chen
Student ID:

ToDo: Record your answers to questions 1 and 2 here. Code should be written in list_assignment.cpp

Question 1:

a:

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

b: output:

   l1 is: 1 2 3 4 5
   l2 is: 1 2 3 4 5 
   After l1 push back 6 into the list
   l1 is: 1 2 3 4 5 6
   l2 is: 1 2 3 4 5

   The output shows that std::list provides a deep copy constructor since when we push back one more
   value in to the l1 list, the l2 does not change and it stays what it was before. 

c: std::list provides a deep copy.


Question 2:

1. The iterator type of my_list_iterator is Bidirectional Iterators.

2. code:

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
    return 0;


    output:

    list one Not Sorted!
    list two Sorted!

3. No, we can not use std::sort algorithm because the iterator type of std::sort is Random
   Access but our my_list_iterator is not that type. 
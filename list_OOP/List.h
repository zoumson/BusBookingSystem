//
//  List.h
//  Created by ZOUMA Adama on 10/23/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

#ifndef List_h
#define List_h
#include <iostream>
#include "Node.h"



using namespace std;
class List:public Node {
private:
      // Data member
    unsigned int length;

public:
    List();// Default constructor
    List(unsigned int);// Constructor with user define length
    List(const List &);// Copy constructor
    ~List();// Deconstructor
    List& operator=(const List&);// Assignemnt operator
    int setLength(unsigned int);// Set List length is it was 0
    unsigned int getLength();// Get List length
    int setElement(unsigned int, long);// Set List element by index
    long getElement(unsigned int);// Get List element by index
    List operator+(const List &);// Addition operator +
    List operator+=(const List &);// Addition operator + =
    List operator++();// Pre-increment operator
    List operator++(int);// Post-increment operator
    List operator--();// Pre-decrement operator
    List operator--(int);// Post-decrement operator
    friend ostream& operator<< (ostream &, List &);// Output operator
    friend istream& operator>> (istream &, List &);// Input operator
};


#endif /* List_h */

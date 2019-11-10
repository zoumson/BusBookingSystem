//
//  List.cpp
//  devoir3
//
//  Created by ZOUMA Adama on 10/23/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "List.h"
using namespace std;



// Default constructor
List::List(): Node() {length = 0;}

// Specified constructor with List length
List::List(unsigned int _length):Node(_length), length(_length){}

// Copy constructor
List::List(const List &org){
    if(org._Node != 0){
        length = org.length;
        _Node = new long[length];
        for(int i = 0; i < length; i++){
            _Node[i] = org._Node[i];
        }// end of for
    }else{

        _Node = 0;// null pointer
    }
}// End of Copy constructor

// Deconstructor
List::~List(){length = 0;}

// Assignemnt operator =
List& List::operator=(const List& other){
    if(other._Node != 0){
        length = other.length;
        _Node = new long[length];
        for(int i = 0; i < length; i++){
            _Node[i] = other._Node[i];
        }// end of for
    }else{

        _Node = 0;// null pointer
    }

    return *this;
}// End of Assignemnt operator

// Function setLength
int List::setLength(unsigned int _length){// Set new list
    if(length == 0){
        length = _length;
        _Node = reCreate(_length);
        return 1;
    }else{
        cout << "Attempt to change an existing List!!\n";
        return 0;
    }

}// End of setLength
// Function getLength
unsigned int List::getLength(){return length;}


// Function setElement
int List::setElement(unsigned int pos, long val){
    if(pos >= 0 && pos < length){// Legal index
        _Node[pos] = val;
        return 1;
    }
    else{// Illegal index

        cout <<"Index out of bounds while attempting to set an element.\n";
        return 0;
    }
}// End of setElement


// Function getElement
long List::getElement(unsigned int pos){
    if(pos >= 0 && pos < length){// Legal index
        return _Node[pos];
    }
    else{// Illegal index
        cout <<"Attempt to retrieve an element from a non existent index.\n";
        return -999999;
    }
}// End of getElement

// Addition operator +
List List::operator+(const List &other){
    if(length == 0)return other; // Internal List is empty
    if(other.length == 0)return *this; // Incoming List is empty
    // Choose the longer List as return length
    unsigned int LENGTH = length >= other.length? length: other.length;
    List result(LENGTH);

    // Internal List is shorter than incoming List
    if(length <= other.length){
        for(int i = 0; i < LENGTH; i++){
            if(i < length){
            result._Node[i] = _Node[i] + other._Node[i];
            }
            else result._Node[i] = other._Node[i];// Skip internal List
        }

    }else
    {// Incoming List other is shorter than internal List
        for(int i = 0; i < LENGTH; i++){
            if(i < other.length){
            result._Node[i] = _Node[i] + other._Node[i];
            }
            else result._Node[i] = _Node[i];// Skip incoming other List
        }
    }

return result;
}// End of Addition operator +

// Addition operator +=
List List::operator+=(const List & other){
    *this = *this + other;
    return *this;
}// End of Addition operator +=

// Pre-increment operator --
List List::operator++(){
    if(_Node == 0)return *this;
    for(int i = 0; i < length; i++){
        ++_Node[i];
    }// end of for

return *this;
}// End of pre-increment operator

// Post-increment operator --
List List::operator++(int){
    List result(*this);
    if(_Node == 0)return *this;
    for(int i = 0; i < length; i++){
        _Node[i]++;
    }// end of for

return result;
}// End of post-increment operator

// Pre-decrement operator --
List List::operator--(){
    if(_Node == 0)return *this;
    for(int i = 0; i < length; i++){
        --_Node[i];
    }// end of for

    return *this;
}// End of pre-decrement operator

// Post-decrement operator --
List List::operator--(int){
    List result(*this);
    if(_Node == 0)return *this;
    for(int i = 0; i < length; i++){
        _Node[i]--;
    }// end of for

    return result;
}// End of post-decrement operator

//------------------INPUT OUTPUT OPERATOR----------------------------------

// Output operator <<
ostream& operator <<(ostream & stream, List& other ){

    if(other.getLength() == 0) {// List is empty, return empty bracket
        stream << "[]";
        return stream;
    }
    stream <<"["<<other.getElement(0); // Openning bracket for the List
    for(int i = 1; i < other.getLength()-1; i++){

        stream << ", " <<other.getElement(i);// Separate all list element by
                                             // Commas
    }// End of for
    stream <<", "<<other.getElement(other.getLength()-1)<<"]";// Closing bracket
return stream;
}// End of Output operator <<

// Input operator >>
istream& operator >>(istream &stream, List& other){
    // Other length doesn't matter as it will be updated according to length
    // read from the list
    string data;               // keep temporary string read from file
    long d;                    // convert string number into integer form
    unsigned int l;            // List length read from the file
    stream >> data;            // First string is the List length
    l = stoi(data);
    List resize_other(l);      // Resize the pre-existing List to accomodate
    other = resize_other;      // List read from the input file

    unsigned int i = 0;        // Index to insert data in the list
    while (stream >> data && i < other.getLength())
    {
      d = stoi(data);          // convert string number into integer form
      other.setElement(i, d);  // Insert data in integer form in the list
                               // At position i
      i++;
    }// End of while

return stream;
}// End of Input operator >>

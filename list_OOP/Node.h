
//  Node.h
//  Created by ZOUMA Adama on 10/23/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

#ifndef Node_h
#define Node_h
#include <iostream>
using namespace std;

class Node {
protected:// Make data availabe for derived classes
    // Data member
    long *_Node;
public:
    Node();// Default constructor
    Node(unsigned int _length);// Constructor with define length
    virtual~Node();// Deconstructor, called implicitly in derived classes
    long* reCreate(unsigned int _length);// Recreate an array with
                                         //length differnt from the original
};


#endif /* Node_h */

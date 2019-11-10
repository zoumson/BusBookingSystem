
//  Created by ZOUMA Adama on 10/23/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

#include "Node.h"
#include <iostream>
using namespace std;

// Default constructor
Node::Node(){_Node = 0;}

// Constructor with defined length
Node::Node(unsigned int _length){
    _Node = new long[_length + 1];
    assert(_Node != 0);
    _Node[0] = _length;
}// End of customized constructor

// Deconstructor
Node::~Node(){if(_Node != 0)delete[] _Node;}

// Create a new array with different length
long* Node::reCreate(unsigned int _length){
        delete [] _Node;
        _Node = new long[_length];
        assert(_Node != 0);

return this->_Node;
}// End of reCreate

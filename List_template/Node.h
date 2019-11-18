//  Node.h
//  Created by ZOUMA Adama on 11/14/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

//-----------------------------------HEADER-----------------------------------
#ifndef Node_h
#define Node_h
#include <iostream>

//---------------------------CLASS DECLARATION---------------------------------
template < class T>

class Node
{
  protected:// Make data availabe for derived classes

    T* _Node;//Data member

  public:

    Node();//1. Default constructor

    Node(unsigned int _length);//2. Constructor with defined length

    virtual~Node();//3. Deconstructor, called implicitly in derived classes

    T* reCreate(unsigned int _length);//4. Recreate an array with
                                      //length differnt from the original
                                      //and return address
};// End of class declaration

//-------------------------CLASS MEMBER FUNCTIONS DEFINITION-------------------

// 1. Default constructor
template < class T>

Node<T>::Node(){_Node = 0;}

// 2. Constructor with defined length
template < class T>

Node<T>::Node(unsigned int _length)
{
    _Node = new T[_length];

    assert(_Node != 0);
}// End of customized constructor

// 3. Deconstructor
template < class T>

Node<T>::~Node(){if(_Node != 0)delete[] _Node;}

// 4. Create a new array with different length
template < class T>

T* Node<T>::reCreate(unsigned int _length)
{
    if(_Node != 0)delete [] _Node;

    _Node = new T[_length];

    assert(_Node != 0);

return this->_Node;
}// End of reCreate


#endif /* Node_h */

//------------------------------------END-------------------------------------

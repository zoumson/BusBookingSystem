//  List.h
//  list
//  Created by ZOUMA Adama on 11/14/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

//-----------------------------------HEADER-----------------------------------
#ifndef List_h
#define List_h
#include <iostream>
#include "Node.h"

//---------------------------CLASS DECLARATION---------------------------------
template < class T>

class List:public Node<T>
{
    private:

        unsigned int length;// Data member

    public:

        List();//1. Default constructor

        List(unsigned int);//2. Constructor with user defined length

        List(const List<T> &);//3. Copy constructor

        ~List();//4. Deconstructor

        List<T>& operator=(const List<T> &);//5. Assignemnt operator

        int setLength(unsigned int);//6. Set List length if it was 0

        // inline because used in other functions
        inline unsigned int getLength() const;//7. Get List length


        int setElement(unsigned int, T);//8. Set List element by index

        // inline because used in other functions
        inline T getElement (unsigned int) const;//9. Get List element by index

        //inline for homework requirement
        inline bool operator==(const List<T> &);//10. Equality operator

        //11. Ouput opeartor defined inside class to avoid clang error
        friend std::ostream& operator <<(std::ostream& stream, List & other)
        {

            if(other.getLength() == 0)
            {// List is empty, return empty bracket
                stream << "[]";

                return stream;
            }

            // Openning bracket for the List and print the first list element
            stream <<"["<<other.getElement(0);

            //Print remaining element except last one
            for(int i = 1; i < other.getLength() - 1; i++)
            {
                stream << ", " << other.getElement(i);// Separate all list
                                                     // elements by Commas
            }// End of for

            // Closing bracket and print the last list element
            stream <<", "<< other.getElement(other.getLength()-1) <<"]";

        return stream;
        }// End of Output operator <<

};// End of class declaration


//-------------------------CLASS MEMBER FUNCTIONS DEFINITION-------------------

//1. Default constructor
template < class T>

List<T>::List(): Node<T>::Node() , length(0){}

//2. Specified constructor with List length
template < class T>

List<T>::List(unsigned int _length):Node<T>::Node(_length), length(_length){}

//3. Copy constructor
template < class T>

List<T>::List(const List<T> &other)
{
    if(other.length != 0)
    {
        length = other.length;

        Node<T>::_Node = new T[length];

        for(int i = 0; i < length; i++)
        {
            Node<T>::_Node[i] = other.Node<T>::_Node[i];
        }// end of for

    }
    else Node<T>::_Node = 0;// null pointer

}// End of Copy constructor


//4. Deconstructor
template < class T>

List<T>::~List(){length = 0;}

//5. Assignemnt operator =
template < class T>

List<T>& List<T>::operator=(const List<T>& other)
{
    if(other.Node<T>::_Node != 0)
    {
        length = other.length;

        Node<T>::_Node = new T[length];

        for(int i = 0; i < length; i++)
        {
            Node<T>::_Node[i] = other.Node<T>::_Node[i];
        }// end of for
    }
    else Node<T>::_Node = 0;// null pointer

    return *this;
}// End of Assignemnt operator

//6. setLength
template < class T>

int List<T>::setLength(unsigned int _length)
{// Set new list if length was 0
    if(length == 0)
    {
        length = _length;

        Node<T>::_Node = Node<T>::reCreate(length);

        return 1;
    }
    else
    {
        std::cerr << "\nAttempt to change an existing List!!\n";

        return 0;
    }

}// End of setLength

// Function getLength, added const because used in == operator
template < class T>

unsigned int List<T>::getLength()const{return length;}

//7. setElement
template < class T>

int List<T>::setElement(unsigned int pos, T val)
{
    if(pos >= 0 && pos < length)
    {// Legal index
        Node<T>::_Node[pos] = val;

        return 1;
    }
    else
    {// Illegal index
        std::cerr <<"\nIndex out of bounds while attempting to set an element.\n";

        return 0;
    }
}// End of setElement

//8. getElement
template < class T>

T List<T>::getElement (unsigned int pos)const
{

    assert(pos >= 0 && pos < length && "Attempt to retrieve an element from a non existent index.\n");

    return Node<T>::_Node[pos];

}// End of getElement

//9. Equality operator
template < class T>

bool List<T>::operator== (const List<T>& other)
{
  if(length != other.length) return false;// differnt length

  for(int i = 0; i < length; i++)
  {
      if(this->getElement(i) != other.getElement(i)) return false;//one element differnt

  }

return true; // all elements are equal and lists have same length

}


#endif /* List_h */
//------------------------------------END-------------------------------------

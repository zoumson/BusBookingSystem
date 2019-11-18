//  main.cpp
//  Created by ZOUMA Adama on 11/14/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

//-----------------------------------HEADER-----------------------------------
#include <iostream>//output std::cerr std::endl belong to std namespace
#include <fstream>// std::ifstream  std::ios belong to std namespace
#include <string>// std::string as string is defined in std namespace
#include "Node.h"
#include "List.h"
#define debug 1  //assert included in debugging session
#if !debug
#define NDEBUG // NDEBUG not defined, but DEBUG yes, so assert is active
#endif
#include <assert.h>// used for debugging, included only if NDEBUG is disabled


int main(int argc, const char * argv[])
{
  assert(argc == 3 && "Only two inputs data allowed, no more, no less.");

  std::ofstream output;
  output.open("RESULT", std::ios::out);
//------------------------PROCESSING DOUBLE FILE-------------------------------

  output <<"\n\t\t\tPROCESSING DOUBLE FILE\n";

  std::ifstream input_double;
  input_double.open(argv[1], std::ios::in);

  if(!input_double.fail())
  {

  unsigned int length_double;       // List length read from the file
  input_double >> length_double;    // First read input data is the List length

// 4. First double list object to hold double file data

  List< double >_4_double_list(length_double);

  unsigned int i = 0;        // Index to insert data in the list
  double data;               // double data read from double file

  while (input_double >> data && i < _4_double_list.getLength())
  {
    // Insert data in double form in the list at position i
      _4_double_list.setElement(i++, data);
  }// End of while

  // 5. Second double list object gets the copy of the first double list object
  // using copy constructor
  List< double >_5_double_list(_4_double_list);

  // 7. Using == to check if first double list and second double list objects
  // are the same
  if(_4_double_list == _5_double_list)
  {
    output <<"\nThe two lists "<<_4_double_list << " and "<< _5_double_list
    <<" are the same.\n";
  }
  else
  {
    output <<"\nThe two lists "<<_4_double_list << " and "<< _5_double_list
    <<" are different.\n";
  }

  // 8. setElement usage
  // - first list object _4_double_list
  for(int i = 0; i < _4_double_list.getLength(); i++)
  {
    _4_double_list.setElement(i, _4_double_list.getElement(i) + 7.5);
  }

  // - second list object _5_double_list
  for(int i = 0; i < _5_double_list.getLength(); i++)
  {
    _5_double_list.setElement(i, _5_double_list.getElement(i) -20.8);
  }

  output <<"\nFirst double list is changed to: "<<_4_double_list
   <<" after adding 7.5 to it.\n";

  output <<"\nSecond double list is changed to: "<<_5_double_list
  <<" after subtracting 20.8 to it.\n";


  input_double.close();

}
else
{
  std::cerr <<"\nDouble file could not be opened.\n";

}

output << std::endl;

//------------------------PROCESSING STRING FILE-------------------------------

  output <<"\n\t\t\tPROCESSING STRING FILE\n";

  std::ifstream input_string;

  input_string.open(argv[2], std::ios::in);

  if(!input_string.fail())
  {

  unsigned int length_string;       // List length read from the file
  input_string >> length_string;    // First data  is the List length

  //4. First string list initiated to hold data read from string file
  List< std::string >_4_string_list1(length_string);

  //4. Second string list initiated using default constructor
  List< std::string >_4_string_list2;

  //4. First string list holding string file data
  unsigned int i = 0;             // Index to insert data in the list
  std::string data;               // string data read from string file

  while (input_string >> data && i < _4_string_list1.getLength())
  {
    // Insert data in string form in the list at position i
    _4_string_list1.setElement(i++, data);

  }// End of while


   // 6. Second string list object gets the copy of the first string list object
   // using assignment operator
  _4_string_list2 = _4_string_list1;


  // 7. Using == to check if first string list and second string list objects
  // are the same
  if(_4_string_list2 == _4_string_list1)
  {
    output <<"\nThe two lists "<<_4_string_list1 << " and "<<_4_string_list2
    <<" are the same.\n";
  }
  else
  {
    output <<"\nThe two lists "<<_4_string_list1 << " and "<<_4_string_list2
    <<" are different.\n.";
  }

  // 8. setElement usage
  // - first list object _4_string_list1
  for(int i = 0; i < _4_string_list1.getLength(); i++)
  {
    _4_string_list1.setElement(i, _4_string_list1.getElement(i).append(" first changed"));
  }

  // - second list object 4_string_list2
  for(int i = 0; i < _4_string_list2.getLength(); i++)
  {
    _4_string_list2.setElement(i, _4_string_list2.getElement(i).append(" second changed"));
  }

  output <<"\nFirst string list is changed to: "<<_4_string_list1
  <<" after appending \"first changed\" to it.\n";

  output <<"\nSecond string list is changed to: "<<_4_string_list2
  <<" after appending \"second changed\" to it.\n";

  input_string.close();
  }
  else
  {
    std::cerr <<"\nString file could not be opened.\n";

  }

  output << std::endl;
  output.close();
return 0;

}
//------------------------------------END-------------------------------------

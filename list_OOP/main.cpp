//
//  main.cpp
//  devoir3
//
//  Created by ZOUMA Adama on 10/23/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"
using namespace std;
int main(int argc, const char * argv[]) {

    ofstream output;
    ifstream input;
    output.open("RESULT", ios::out);
    input.open(argv[1], ios::in);
    if(!input.fail()){
    List first_list;// default constructor
    input >> first_list;
    input.close();
//----------------------------READ FILE----------------------------------------
    output<<"\nI. Read data from command line input file name.\n";
    output << "-----------------------------------------------\n";
    output << "First list read from input file: "<<first_list<<" .\n\n";
//----------------------------COPY A LIST--------------------------------------
    output<<"\nII. Three different ways of copying a List:\n";
    output << "--------------------------------------------\n";
    // First method
    output << "\n1. Copy the first list to another list using copy constructor.\n";
    output << "\tExample: List second_list(first_list) = ";
    List second_list(first_list);
    output << second_list<<" .\n";

    // Second method
    output << "\n2. Copy the first list to a new list using assignment operator.\n";
    output << "\tExample: List third_list = first_list = ";
    List third_list = first_list;
    output << third_list<<" .\n";

    // Third method
    output << "\n3. Copy the first list to a new list using customized constructor.\n";
    output << "\t-Create the customized list with  same length as the first list.\n";
    output << "\t-Then copy all elements in first list to the new using for loop.\n";
    output << "\tExample:\n\t\t\t\t\tList fourth_list(first_list.getLength());\n";
    output << "\t\t\t\t\tfor(int i = 0; i < fourth_list.getLength(); i++){\n";
    output << "\t\t\t\t\tfourth_list.setElement(i, first_list.getElement(i));}\n";


    List fourth_list(first_list.getLength());
    for(int i = 0; i < fourth_list.getLength(); i++){
      fourth_list.setElement(i, first_list.getElement(i));
    }

    output << "\tAfter copying all elements, fourth_list = "<<fourth_list<<" .\n";

  }else{// File can't be open
    input.close();
    output<<"\nI. Read data from command line input file name.\n";
    output << "-----------------------------------------------\n";
    output << "Can't read file.\n\n";
    output<<"\nII. Three different ways of copying a List:\n";
    output << "--------------------------------------------\n";
    output << "Skipped as file can't be read.\n";
  }
//----------------------------OPERATOR-------------------------------------------
    output<<"\n\nIII. Operator Overloading: +, +=, ++, --\n";
    output << "----------------------------------------\n";
    // Addition operator +
    output << "\n1. Addition operator: C = A + B.\n\tAdd element at index i in A to";
    output << " element at index i in B.\n\tIf list A length's is shorter than";
    output <<" list B length, it is extended to B length \n\tand the newly added";
    output << " cells are filled with zeros, vice versa.\n";
    List A(2), B(4);
    A.setElement(0,1);A.setElement(1,2);
    B.setElement(0,10);B.setElement(1,20);B.setElement(2,30);B.setElement(3,40);
    List C = A + B;
    output << "\tExample: A = "<<A<< ", B = "<<B<<", C = A + B = "<<C<<" .\n";
    // Addition operator +=
    output << "\n2. Addition operator: C += B .\n\tUpdate C with its old values ";
    output <<"increased by the corresponding values in B.\n\tThe missing ";
    output <<"values due to length shortage are  replaced by zeros.";
    C += B;
    output << "\n\tExample: C = "<<C<< ", B = "<<B;C += B;
    output <<", C += B = "<<C<<" .\n";
    // Pre-Increment operator ++
    output << "\n3. Pre-Increment operator: ++C .\n\tAdd one immediately to all list elements.";
    output << "\n\tExample: C = "<<C<< ", D = ++C .";
    List D = ++C;
    output << "\n\tDuring assignment C = "<<D<<", after assignment C = "<<C<<" .\n";

    // Post-Increment operator ++
    output << "\n4. Post-Increment operator: A++ .\n\tAdd one to all list elements";
    output <<" after assignment.";
    output << "\n\tExample: A = "<<A<< ", E = A++ .";
    List E = A++;
    output << "\n\tDuring assignment A = "<<E<<", after assignment A = "<<A<<" .\n";
    // Pre-Decrement operator --
    output << "\n5. Pre-Decrement operator: --B .\n\tSubtract one immediately to all list elements.";
    output << "\n\tExample: B = "<<B<< ", F = --B .";
    List F = --B;
    output << "\n\tDuring assignment B = "<<F<<", after assignment B = "<<B<<" .\n";

    // Post-Decrement operator --
    output << "\n6. Post-Decrement operator: C-- .\n\tSubtract one to all list elements";
    output <<" after assignment.";
    output << "\n\tExample: C = "<<C<< ", G = C-- .";
    List G = C--;
    output << "\n\tDuring assignment C = "<<G<<", after assignment C = "<<C<<" .\n";
    output<<"\n\n\nEnd of program.\n";



    input.close();
    output.close();


    return 0;
}

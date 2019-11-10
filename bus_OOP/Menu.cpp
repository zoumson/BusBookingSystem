//  Menu.cpp
//  Created by ZOUMA Adama on 10/31/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

#include <iostream>
#include "Bus.h"
#include "Function.h"
#include "Menu.h"
#include <string.h>
#include <vector>

using namespace std;



void run(const unsigned int total_bus){
  vector < Bus *> Buses;
  //for(int i = 0; i < total_bus; i++)Buses.push_back(Bus());
  unsigned int bus_active = 0;
  int w; //store the corresponding choice in integer
  string s;// string to store the choice

  int wrong_input = 0;
  while(true)

  {
      //system("cls");
    // Option
    cout << "\n\n\n\n\n";

    cout << "\t\t\t1.Deploy a new bus\n\t\t\t";

    cout << "2.Reservation\n\t\t\t";

    cout << "3.Show\n\t\t\t";

    cout << "4.Buses available\n\t\t\t";

    cout << "5.Exit";


  bool invalid = false;

  // Process user imput data
  do {

  cout << "\n\t\t\tEnter your choice:-> ";

    cin >> s; // input a string number

    try{ w = stoi(s);} // convert to a number
    catch(...)
      {
        // user insert a string, invalid input, should be a Number
        // restart the choice
        if(wrong_input < 5)
        {

        invalid = true;
        cout << "\n\t\t\tInvalid input, please try again\n";
      }
      else
      {
        invalid = false;
        wrong_input++;
      }
      }

      if(wrong_input == 5)
      {
        cout << "\nMaximum try reached, sorry, no more service\n";
        return ;// break the infinite loop

      }

    // if choice is valid continue
    if(!invalid){// Valid choice

    switch(w)

    {

      case 1:  design(bus_active, total_bus, Buses);

        break;

      case 2:  reservation(bus_active, Buses);

        break;

      case 3:  show(bus_active, Buses);

        break;

      case 4:  available(bus_active, Buses);

        break;

      case 5:  exit(0);

      default:
      // user insert a number not in the range
      cout <<"\n\t\t\tInvalid input, please try again\n";

      invalid = true;

      wrong_input++;


    }// switch
  }// if choice is not valid restart the choosing window

  }while(invalid);
  // As long as the imput is not coherent, exhort user to insert an option
  // Finish processing user imput option

  }
  // User quit the user interface but choosing exit
    return ;
}

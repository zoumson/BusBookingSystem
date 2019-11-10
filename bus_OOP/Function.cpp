//  Function.cpp
//  Created by ZOUMA Adama on 10/31/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

#include "Function.h"
#include "Bus.h"
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// 1. design
void design(unsigned int &bus_active, const unsigned int maxBus, vector< Bus *> &b)
{
  if(bus_active == maxBus)
  {// Total number of buses reached
    cout <<"\nNo more bus.\n";
    return;
  }
  cout << "\nEnter bus no: ";

  string num;

  cin >> num;

  //b[bus_active].setBusNum(num);
  bool wongSize = false;
  int wrong = 0;
  int siz;
do
  {

  cout << "\nEnter bus size: ";


  cin >> siz;
  wongSize = false;
  if( siz % 2 != 0)
  {
    cout << "\nWrong bus size\n";
    wrong++;
    wongSize = true;
    if(wrong == 5)
    {
      cout <<"\nMaximum try reached. Come back next time.\n";
      return;

    }
  }

}while(wongSize);


  cout << "\nEnter Driver's name: ";

  string nam;

  cin >> nam;

  cout << "\nDeparture time: ";

  string dep;

  cin >> dep;

  cout << "\nArrival time: ";

  string arr;

  cin >> arr;

  cout<<"\nFrom: \t\t\t";

  string from;

  cin >> from;

  cout << "\nTo: \t\t\t";

  string to;

  cin >> to;

  b.push_back(new Bus(num, nam, arr, dep, from, to, siz));

  cout << "\nBus no."<< num <<" is available now\n";

  bus_active++;// one bus active

}// End of design


// 2. reservation
void reservation(const unsigned int availBus, vector < Bus *> &b)
{
  if(availBus == 0)
  {// Total number of buses reached
    cout <<"\n\t\t\tNo bus available, please come back next time\n";
    return;
  }
  //

  unsigned int n;// bus index in bus array

 // repeat if bus is full and want to choose another bus
 unsigned int another = 0;// limit number of try
 bool anotherBus = false;
 do
 {
    cout << "\nBus no: ";
    n = findBus(availBus,b);
    if(n == 100) return;// 100 is end of process

    if(b.at(n)->isFull())
    {
      cout << "\nBus is full\n\nFind another bus?";
      bool invalid = false;
      int fail = 0;
      do
      {// choose another bus or give up
        cout <<"\n\t1. yes\n\t2. no\n";

        string op;

        cin >> op;


        if (op.compare("no") == 0 || op.compare("No") == 0||op.compare("NO") == 0)
        {
          cout << "\nSorry, see you next time\n";
          return;
        }
        else if(op.compare("yes") == 0 || op.compare("Yes") == 0||op.compare("YES") == 0)
        {
          cout <<"\nChoose another bus number\n";
          cout <<"\nReminder: bus number "<< b.at(n)->getBusNum()<<" is full\n";
          anotherBus = true;
          invalid = false;
          another++;
        }
        else
        {
          cerr << "\nInvalid Input\n";
          invalid = true;
          if(fail == 5)
          {
            cout <<"\nMaximum try reached, come back next time\n";
            return;
          }
          fail++;
        }
      }while(invalid);// if not insert yes or no


    }// end of if bus is full

if(another == 5)
{
  cout <<"\nMaximum try reached, come back next time\n";
  return;
}

}
while(anotherBus);//Choose another bus if bus is full

// n is the right bus number
int j = 0;
  while(j < 5)// infinite loop to prompt user to insert right seat number

  {

    int seat;

    cout<<"\nSeat Number: ";

    cin >> seat;

    if(seat > b.at(n)->getSize())// if 1

          {

            cout << "\nThere are only " <<b.at(n)->getSize();
            cout << " seats available in this bus\n";
            j++;

          }

    else// else of 1

          {// seat number in right range
                // seat is convert to 2D

                string tmp;

                tmp = b.at(n)->getPassenger(seat);

                if (tmp.compare("Empty") == 0)

                  {// seat insert is previously empty

                    cout << "\nEnter passenger's name: ";

                    string name;

                    cin >> name;

                    b.at(n)->setSeat(seat, name);

                    break;// No need to find other bus, already have a seat

                  }

                else// seat is taken
                  {
                    cout << "\nThe seat no." << seat <<" is already reserved\n";
                    j++;
                  }

            }

            if(j == 5)
            {
              cout <<"\nMaximum try reached, come back next time\n";
            }
            else
            {
              cout <<"\nTry again\n";
            }


      }// end of while, if not right seat number enter again

}// end of Reservation



// 3. show
void show(unsigned int &bus_active, vector < Bus *> &b)
{
  // added, if there is no bus installed
  if(bus_active == 0)
    {
      cout <<"\n\t\t\tNo bus available, please come back next time\n";

      return;
    }

  int n;

  string number;

  cout << "\nEnter bus no: ";

  n = findBus(bus_active, b);

  if(n == 100) return;

      b.at(n)->busInfo();
      b.at(n)->availableSeat();
      b.at(n)->reservedSeat();
}// End of show



// 4. available
void available(const unsigned int bus_active, vector < Bus *> &b)
{
  // added, if there is no bus installed
  if(bus_active == 0)
    {
      cout <<"\n\t\t\tNo bus available, please come back next time\n";

      return;
    }

  vline('-');
  // available buses
  for(int n = 0; n < bus_active; n++)
    {

    b.at(n)->busInfo();
      vline('-');
    }// end of for loop

}// End of available


// 5. vline
void vline(char ch)
{

    for (int i = 80; i>0; i--)cout<<ch;

}


// 6. findBus
unsigned int findBus(unsigned int availBus, vector <Bus *> &b)
{
  bool wrong_bus_no = true;

  string number;

  int n;

  int j = 0;

    do {
          cin >> number;

          // finding the right bus number
          for(n = 0; n < availBus; n++)

          {
            string tmp ;
            tmp = b.at(n)->getBusNum();
            if(tmp.compare(number) == 0)
            {
              wrong_bus_no = false;
              break;// for loop break
            }
          }// end of for loop

        if(wrong_bus_no == true)
        {
          j++;
          if (j == 5)
          {
            cout <<"\nMaximum try reached, come back next time\n";

            return 100;// No bus found end of process
          }
          cout << "\nIncorrect bus number\n";

          cout << "\nEnter correct bus no: ";
        }

      }while(wrong_bus_no);

return n;
}// End of findBus

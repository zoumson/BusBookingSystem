//  Bus.cpp
//  Created by ZOUMA Adama on 10/31/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

#include <iostream>
#include <string>
#include "Bus.h"

using namespace std;


// No bus created
unsigned int Bus::count = 0;

// 1. Default constructor
Bus::Bus()
{
  busNum = " ";

  driverName = " ";

  arrivalTime = " ";

  departTime = " ";

  provenance = " ";

  destination = " ";

  size = 0;

  passengers = 0;

  seats = 0;

  count++;
}// End of Default constructor

// 2. Customized constructor
Bus::Bus(string bN, string dN, string aT,string dT, string pro, string dest, unsigned int s)
          {
            busNum = bN;

            driverName = dN;

            arrivalTime = aT;

            departTime = dT;

            provenance = pro;

            destination = dest;

            size = s;

            passengers = new string[size];

            assert(passengers != 0);

            for(int i = 0; i < size; i++){passengers[i] = "Empty";}

            seats = new string*[size/2];

            for(int i = 0; i < size/2; ++i){seats[i] = new string[2];}

            for(int i = 0; i < size/2; i++)
            {
              for(int j = 0; j < 2; j++)
              {
                  seats[i][j] = "Empty";
              }
            }
            assert(seats != 0);

            //empty();

            count++;
          }// End of customized constructor

// 3. Copy constructor
Bus::Bus(const Bus & other)
{
  if(other.size != 0)
  {

    busNum = other.busNum;

    driverName = other.driverName;

    arrivalTime = other.arrivalTime;

    departTime = other.departTime;

    provenance = other.provenance;

    destination = other.destination;

    size = other.size;

    passengers = new string[size];

    assert(passengers != 0);

    for(int i = 0; i < size; i++) passengers[i] = other.passengers[i];

    seats = new string*[size/2];

    for(int i = 0; i < size/2; ++i)seats[i] = new string[2];

    assert(seats != 0);

    for(int i = 0; i < size/2; i++)
    {
      for(int j = 0; j < 2; j++) seats[i][j] = other.seats[i][j];
    }
}
else
{
  busNum = " ";

  driverName = " ";

  arrivalTime = " ";

  departTime = " ";

  provenance = " ";

  destination = " ";

  size = 0;

  passengers = 0;

  seats = 0;
}
}// End of copy constructor


//  4. Assignment operator
Bus& Bus::operator=(const Bus & other)
{
  if(other.size != 0)
  {

    busNum = other.busNum;

    driverName = other.driverName;

    arrivalTime = other.arrivalTime;

    departTime = other.departTime;

    provenance = other.provenance;

    destination = other.destination;

    size = other.size;

    passengers = new string[size];

    assert(passengers != 0);

    for(int i = 0; i < size; i++) passengers[i] = other.passengers[i];

    seats = new string*[size/2];

    for(int i = 0; i < size/2; ++i)seats[i] = new string[2];

    assert(seats != 0);

    for(int i = 0; i < size/2; i++)
    {
      for(int j = 0; j < 2; j++) seats[i][j] = other.seats[i][j];
    }
}
else
{
  busNum = " ";

  driverName = " ";

  arrivalTime = " ";

  departTime = " ";

  provenance = " ";

  destination = " ";

  size = 0;

  passengers = 0;

  seats = 0;
}
  return *this;

}// End of assignment operator


// 5. Deconstructor
Bus::~Bus()
{
  busNum = " ";

  driverName = " ";

  arrivalTime = " ";

  departTime = " ";

  provenance = " ";

  destination = " ";

  if(passengers != 0 )delete[] passengers;

  for(int i = 0; i < size/2; ++i)
  {
    if(seats[i] != 0)delete[] seats[i];
  }

  if(seats != 0)delete [] seats;

  size = 0;

  count--;
}// End of deconstructor

// 6. getBusNum
string Bus::getBusNum(){return busNum;}

// 7. getDriverName
string Bus::getDriverName(){return driverName;}

// 8. getArrivalTime
string Bus::getArrivalTime(){return arrivalTime;}

// 9. getDepartTime
string Bus::getDepartTime(){return departTime;}

// 10. getProvenance
string Bus::getProvenance(){return provenance;}

// 11. getDestination
string Bus::getDestination(){return destination;}

// 12. getSize
unsigned int Bus::getSize(){return size;}

// 13. getPassenger
string Bus::getPassenger(unsigned int _seat)
{
  try
  {
    if(_seat > size || _seat <= 0)throw _seat;

    else return passengers[_seat - 1];
  }
  catch(...)
  {
    cerr << "\nInexistent seat number\n";

    return "Error";
  }
}// End of getPassenger

// 14. getSeat, 1 base indexing
string Bus::getSeat(unsigned int row, unsigned int col)
{
  // 2D index to 1D
  // change to 0 base, compute 1D index then add 1 to 1 base indexing
  unsigned int _seat = 2*(row - 1) + (col - 1) + 1;

  return getPassenger(_seat);
}// End of getSeat

// 15. getTotalBuses
unsigned int Bus::getTotalBuses(){return count;}

// 16. setBusNum
bool Bus::setBusNum(string num)
{
  try
  {
    busNum = num;
  }
  catch(...)
  {
    cerr << "\nUnable to set bus number\n";

    return false;
  }
  return true;
}// End of setBusNum


// 17. setDriverName
bool Bus::setDriverName(string name)
{
  try
  {
    driverName = name;
  }
  catch(...)
  {
    cerr << "\nUnable to set driver name\n";

    return false;
  }
  return true;
}// End of setDriverName

// 18. setArrivalTime
bool Bus::setArrivalTime(string aTime)
{
  try
  {
    arrivalTime = aTime;
  }
  catch(...)
  {
    cerr << "\nUnable to set arrival time\n";

    return false;
  }
  return true;
}// End of setArrivalTime

// 19. setDepartTime
bool Bus::setDepartTime(string dTime)
{
  try
  {
    departTime = dTime;
  }
  catch(...)
  {
    cerr << "\nUnable to set departure time\n";

    return false;
  }
  return true;
}// End of setDepartTime

// 20. setProvenance
bool Bus::setProvenance(string prov)
{
  try
  {
    provenance = prov;
  }
  catch(...)
  {
    cerr << "\nUnable to set provenance\n";

    return false;
  }
  return true;
}// end of setProvenance

// 21. setDestination
bool Bus::setDestination(string dest)
{
  try
  {
    destination = dest;
  }
  catch(...)
  {
    cerr << "\nUnable to set destination\n";

    return false;
  }
  return true;
}// End of setDestination

//22. setSize
bool Bus::setSize(unsigned int siz)
{
  try
  {
    size = siz;
  }
  catch(...)
  {
    cerr << "\nUnable to set size\n";

    return false;
  }
  return true;
}// End of setSize

// 23. setSeat
//_seat 1 ...2 ..3..
bool Bus::setSeat(unsigned int _seat, string name)
{
  try
  {
    if(_seat > size || _seat <= 0)throw _seat;
    else
    {
      passengers[_seat - 1] = name;

      seats[_seat/2 + _seat%2 - 1][1 - _seat%2] = name;

      return true;
    }

  }

  catch(unsigned int e)
  {
    cerr << "\nInexistent seat number\n";

    return false;
  }

  catch(...)
  {
    cerr << "\nWrong seat number\n";

    return false;
  }
}// End of setSeat

// 24. isFull
bool Bus::isFull()
{
  for(int i = 1; i <= size; i++)
  {
    string tmp = getPassenger(i);

    if(tmp.compare("Empty") == 0) return false;
  }
  return true;
}// End of isFull

// 25. empty
void Bus::empty(){for(int i = 1; i <= size; i++)setSeat(i, "Empty");}

// 26. busInfo
void Bus::busInfo()
{
  vline('*');

  cout << "\nBus no:\t" << busNum;

  cout << "\n\nDriver:\t" << driverName;

  cout << "\n\nFrom:\t" << provenance;

  cout << "\t\t\tTo:\t" << destination;

  cout << "\n\nDeparture time:\t" << departTime;

  cout << "\t\tArrival time:\t" << arrivalTime << endl;

  vline('*');

}// End of businfo

// 27. availableSeat
void Bus::availableSeat()
{
  int s = 0;
  int p = 0;

  for (int i = 1; i <= size/2; i++)// row

    {
      cout<<"\n";

      for (int j = 1; j <= 2; j++)// column
        {
          s++;// seat number

          string tmp = getSeat(i,j);
          if(tmp.compare("Empty") == 0)// seat is empty
            {// empty seats
              cout.width(5);

              cout.fill(' ');

              cout<<s<<".";

              cout.width(10);

              cout.fill(' ');

              cout<<getSeat(i,j);

              p++;// number of empty seats
            }// end of  if

          else
            {// reserved seats
              cout.width(5);

              cout.fill(' ');

              cout<<s<<".";

              cout.width(10);

              cout.fill(' ');

              cout<<getSeat(i,j);
            }

        }// end of inner for loop, column

    }// end of outer for loop, row
      if(p == 1)
      {
        cout << "\n\nThere is " << p << " seat empty in Bus No. " << busNum <<" .\n";
      }
      else
      {
        cout << "\n\nThere are " << p << " seats empty in Bus No. " << busNum <<" .\n";

      }

}// End of availableSeat

// 27. reservedSeat
void Bus::reservedSeat()
{
  for(int i = 1; i <= size; i++)
  {
    string tmp = getPassenger(i);

    if (tmp.compare("Empty") != 0)
    {
      cout << "\nThe seat No. "<< i <<" is reserved for ";

      cout << getPassenger(i) << ".";
    }// end of if
  }// end of for loop
}// End of reservedSeat

// 28. vline
void Bus::vline(char ch){for (int i = 80; i > 0; i--)cout << ch;}

// 29. reSize
void Bus::reSize(unsigned int _size)
{
  size = _size;

  string *passenger = new string[size];

  assert(passenger != 0);

  passengers = passenger;

  string **seat = new string*[size/2];

  for(int i = 0; i < size/2; ++i)seat[i] = new string[2];

  assert(seat != 0);

  seats = seat;

  empty();
}

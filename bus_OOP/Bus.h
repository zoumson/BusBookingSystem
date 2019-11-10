//  Bus.h
//  Created by ZOUMA Adama on 10/31/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

#ifndef Bus_h
#define Bus_h
#include <iostream>
#include <string.h>

using namespace std;

class Bus {

private:
    string busNum, driverName, arrivalTime, departTime, provenance, destination;
    string ** seats;
    string * passengers;
    unsigned int size;//
public:


      // number of objects created
      static unsigned int count;

      //1
      Bus();

      //2
      Bus(string , string, string, string, string, string, unsigned int);

      //3
      Bus(const Bus &);

      //4
      Bus& operator=(const Bus &);

      //5
      ~Bus();

      //6
      string getBusNum();

      //7
      string getDriverName();

      //8
      string getArrivalTime();

      //9
      string getDepartTime();

      //10
      string getProvenance();

      //11
      string getDestination();

      //12
      unsigned int getSize();

      //13
      string getPassenger(unsigned int);

      //14
      string getSeat(unsigned int, unsigned int );

      //15
      unsigned int getTotalBuses();

      //16
      bool setBusNum(string);


      //17
      bool setDriverName(string);

      //18
      bool setArrivalTime(string);

      //19
      bool setDepartTime(string);

      //20
      bool setProvenance(string);

      //21
      bool setDestination(string);

      //22
      bool setSize(unsigned int);

      //23
      bool setSeat(unsigned int , string);
      //bool setPassengersList(unsigned int, string);

      //24
      bool isFull();

      //25
      void empty();

      //26
      void busInfo();

      //27
      void availableSeat();

      //28
      void reservedSeat();

      //29
      void vline(char );

      void reSize(unsigned int);


};




#endif /* Bus_h */

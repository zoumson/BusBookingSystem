//  Function.h
//  Created by ZOUMA Adama on 10/31/19.
//  Copyright © 2019 ZOUMA Adama. All rights reserved.

#ifndef Function_h
#define Function_h
#include "Bus.h"
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//1
void design(unsigned int &, const unsigned int, vector< Bus *> &);

//2
void reservation(const unsigned int, vector< Bus *> &);

//3
void show(unsigned int &, vector< Bus *> &);

//4
void available(const unsigned int , vector< Bus *> &);

//5
void vline(char);

//6
unsigned int findBus(unsigned int , vector< Bus *> &);

#endif

//  Using Xcode compiler
//  main.cpp
//  Created by ZOUMA Adama on 3/31/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
#include<iostream>
#include"Matrix.h"
using namespace std;

int main()
{
    cout << "<<Default Construstor>>\ntest1\n";
    Matrix test1;
    test1.displayData();
    cout << endl;
    
    cout << "\n<<Constructor>> (Only size, all cells are initialized to 0)" << endl;
    cout << "test2\n";
    Matrix test2(3, 4);
    test2.displayData();
    cout << endl;
    
    cout << "\n<<Constructor>>\ntest3a\n";
    double m2[6] = { 0,1,4,-7.2,8.1,2.6 };
    Matrix test3a(3, 2, m2, 6);
    test3a.displayData();
    cout << endl;
    
    cout << "test3b\n"; //for multiply
    double m1[6] = { 2.2,-1,6,4.3,8,-8.1 };
    Matrix test3b(2, 3, m1, 6);
    test3b.displayData();
    cout << endl;
    
    cout << "\n<<Copy constructor>>\ntest4\n";
    Matrix test4(test3a);
    test4.displayData();
    cout << endl;
    
    cout << "\n<<Set data>>\ntest4\n";
    test4.setData(0, 1,7.2);
    test4.displayData();
    cout << endl;
    
    cout << "\ntest4(row,col)=" << "(" << test4.getRow() << "," << test4.getCol() << ")" << endl;
    cout << endl;
    
    cout << "\ntest4(0,1)=";//Get data
    cout<<test4.getData(0, 1);
    cout << endl;
    
    cout << "\n\n<<Add>>" << endl;
    cout << "test3a + test4:" << endl;
    test3a.displayData();
    cout << " +\n";
    test4.displayData();
    cout << " =" << endl;
    test3a.add(test4).displayData();
    cout << endl;
    
    cout << "\n<<Multiply>>" << endl;
    cout << "test3a * test3b" << endl;
    test3a.displayData();
    cout << " *\n";
    test3b.displayData();
    cout << " =" << endl;
    test3a.multiply(test3b).displayData();
    cout << endl;
    
    cout << "\n<<Transpose>>\n";
    test4.displayData();
    cout << "transpose\n";
    test4.transpose().displayData();
    cout << endl;
    
    system("pause");
    return 0;
}


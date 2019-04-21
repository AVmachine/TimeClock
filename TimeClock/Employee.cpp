//
//  Employee.cpp
//  TimeClock
//
//  Created by Alex Anthony on 4/18/19.
//  Copyright © 2019 Alex Anthony. All rights reserved.
//

#include "Employee.hpp"
#include <iostream>
using namespace std;


string Employee::getfName()
{
    return fName;
}
string Employee::getlName(){
    return lName;
}
void Employee::getid()
{
    //best way to return an array to view?
    cout<<"ID#: ";
    for(int x = 0; x!=5; x++)
    {
        cout<<id[x]<<" ";
    }
    cout<<endl;
}
void Employee::setfName(string s)
{
    fName = s;
}
void Employee::setlName(string s)
{
    lName = s;
}

void Employee::setid(int arr[])
{
    for(int x = 0; x!= 5;x++)
    {
        id[x]=arr[x];
    }
}



//
//  Employee.hpp
//  TimeClock
//
//  Created by Alex Anthony on 4/18/19.
//  Copyright © 2019 Alex Anthony. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <string>
#include <stdio.h>

using std::string;

class Employee{
private:
    string fName;
    string lName;
    int id[];
public:
    string getfName();
    string getlName();
    void getid();
    void getInfo();
    void setfName(string s);
    void setlName(string s);
    void setid(int arr[]);
};
#endif /* Employee_hpp */

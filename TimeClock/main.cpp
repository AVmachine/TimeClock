//
//  main.cpp
//  TimeClock
//
//  Created by Alex Anthony on 4/18/19.
//  Copyright © 2019 Alex Anthony. All rights reserved.
//

#include <iostream>
#include "Employee.hpp"

using namespace std;


int main() {
    
    int dangArray[]={1,2,3,4,5};
    Employee alex;
    alex.setid(dangArray);
    alex.getid();
    
    return 0;
}

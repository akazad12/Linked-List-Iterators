//
//  Exceptions.h
//  Iterator project group 2
//
//  Created by Abul Azad on 12/23/17.
//  Copyright © 2017 Group 2. All rights reserved.
//

#ifndef Exceptions_h
#define Exceptions_h

#include <string>
using namespace std;

//EXCEPTION HANDLING CLASS
//constructor sets the error message
//getError() retrieves the error message
class Exceptions{
public:
    Exceptions(const string err)
    :errMsg(err){}
    string getError(){return errMsg;}
private:
    string errMsg;
    
};

#endif /* Exceptions_h */

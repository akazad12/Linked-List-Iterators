//
//  main.cpp
//  Iterator project group 2
//
//  Created by Abul Azad on 12/23/17.
//  Copyright © 2017 Group 2. All rights reserved.
//

#include <iostream>
using namespace std;

#include "listType.hpp"

//#include "GameEntry.hpp"


int maxSize;//Used to initialize the max size of the list

int main(int argc, const char * argv[]) {
    int action;
    cout<<"Enter the length of your list\n";//User input to find user action and set list sized
    cin>>maxSize;
    cout<<"What type of list are you creating?(int= 1,double=2\n";
    cin >>action;
    //User input(action) determines whether to run int, double or GameEntry type list
    //User input creates List type object and runs correlated function
    if (action == 1){
        ListType I;
        I.buildlist_int(maxSize);
    }
    else if(action == 2){
        ListType D;
        D.buildlist_double(maxSize);
    }
    /*else if(action == 3){
        ListType G;
        G.buildlistGameEntry(maxSize);
    }*/
    
    
}

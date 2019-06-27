//
//  gameEntry.hpp
//  Iterator project group 2
//
//  Created by Abul Azad on 12/23/17.
//  Copyright © 2017 Group 2. All rights reserved.
//

#ifndef gameEntry_hpp
#define gameEntry_hpp

#include <stdio.h>

#include <iostream>
using namespace std;

class gameEntry {				// a game score entry
private:
    string name;				// player's name
    int score;					// player's score
public:
    gameEntry(const string& n="", int s=0);	// constructor
    string getName() const;			// get player name
    int getScore() const;			// get score
    void setScore(int s);
    void setName(string n);
    
    //overloads < to find if user input is less than current node value
    bool operator<(const gameEntry &b)
    {
        return getScore() < b.getScore();
    }
    //Overloads the output operator to output values in a Game Entry node
    friend ostream& operator<<(ostream& os, gameEntry &x)
    {
        os << "Name: "<<x.getName() << "\tScore: " << x.getScore();
        return os;
    }
    //Overloads the = operator to assign user input to current node value
    gameEntry& operator=(const gameEntry &g){
        score = g.getScore();
        name = g.getName();
        return *this;
    }
    //Overloads comparison operator to find if user input is equal to the current node value
    bool operator==(const gameEntry& r)
    {
        return getScore() == r.getScore() && getName() == r.getName();
    }
    
};

#endif /* gameEntry_hpp */

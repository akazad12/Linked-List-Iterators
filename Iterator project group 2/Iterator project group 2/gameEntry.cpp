//
//  gameEntry.cpp
//  Iterator project group 2
//
//  Created by Abul Azad on 12/23/17.
//  Copyright © 2017 Group 2. All rights reserved.
//

#include "gameEntry.hpp"
gameEntry::gameEntry(const string& n, int s)	// constructor
: name(n), score(s) { } // accessors
string gameEntry::getName() const { return name; }
int gameEntry::getScore() const { return score; }

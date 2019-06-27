//
//  nodelist.hpp
//  Iterator project group 2
//
//  Created by Abul Azad on 12/23/17.
//  Copyright © 2017 Group 2. All rights reserved.
//

#ifndef nodelist_hpp
#define nodelist_hpp

#include <stdio.h>
#include "Exceptions.h"
#include "gameEntry.hpp"
#include "MNode.h"
template<typename Elem>
class NodeList { // doubly linked list
public:
    class Iterator {
    public:
        Elem& operator*();
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();
        Iterator& operator--();
        Iterator& operator+(int);
        Iterator& operator-(int);
        friend class NodeList;
    private:
        Node<Elem>* v;
        Iterator(Node<Elem>* u);
        
    };
    
public:
    NodeList(int); // constructor
    int size() const;   //List size
    bool empty() const; // is list empty?
    Iterator begin() const; //beginning positon
    Iterator end() const;   //(just beyond) last position
    void insertFront(const Elem& e) throw (Exceptions);
    void insertBack(const Elem& e);
    void insert(const Iterator& p, const Elem& e);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator& p);
    void output(const Iterator& p);
    void replaceMin(const Elem& e,const Iterator& p);
    double findMin(const Iterator& p);
    double findMax(const Iterator& p);
    double findAvg(const Iterator& p);
private: // local type definitions
    Node<Elem>* header; // list sentinels
    Node<Elem>* trailer;
    int n;
    int counter = 0;
    int maxSize;
    
    
};


#endif /* nodelist_hpp */

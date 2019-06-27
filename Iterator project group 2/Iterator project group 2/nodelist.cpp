//
//  nodelist.cpp
//  Iterator project group 2
//
//  Created by Abul Azad on 12/23/17.
//  Copyright © 2017 Group 2. All rights reserved.
//
#include <iostream>
#include "nodelist.hpp"

using namespace std;

template <typename Elem>
NodeList<Elem>::Iterator::Iterator(Node<Elem>* u)		// constructor from Node*
{ v = u; }

template <typename Elem>
Elem& NodeList<Elem>::Iterator::operator*()		// reference to the element
{ return v->elem; }

// compare positions
template <typename Elem>
bool NodeList<Elem>::Iterator::operator==(const Iterator& p) const
{ return v == p.v; }

template <typename Elem>
bool NodeList<Elem>::Iterator::operator!=(const Iterator& p) const
{ return v != p.v; }

// move to next position
template <typename Elem>
typename NodeList<Elem>::Iterator& NodeList<Elem>::Iterator::operator++()
{ v = v->next; return *this; }

// move to previous position
template <typename Elem>
typename NodeList<Elem>::Iterator& NodeList<Elem>::Iterator::operator--()
{ v = v->prev; return *this; }

// move up by some positions
template <typename Elem>
typename NodeList<Elem>::Iterator& NodeList<Elem>::Iterator::operator+(int n)
{ for (int i = 0; i < n ; i++) v = v->next; return *this; }

// move down by some positions
template <typename Elem>
typename NodeList<Elem>::Iterator& NodeList<Elem>::Iterator::operator-(int n)
{ for (int i = 0; i < n; i--) v = v->prev; return *this; }


template <typename Elem>
NodeList<Elem>::NodeList(int m)   //Constructor
: maxSize(m){
    n = 0;					// initially empty
    header = new Node<Elem>;				// create sentinels
    trailer = new Node<Elem>;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
}

template <typename Elem>
int NodeList<Elem>::size() const 			// list size
{ return n; }

template <typename Elem>
bool NodeList<Elem>::empty() const 			// is the list empty?
{ return (n == 0); }

template <typename Elem>
typename NodeList<Elem>::Iterator NodeList<Elem>::begin() const
{ return Iterator(header->next); }

template <typename Elem>
typename NodeList<Elem>::Iterator NodeList<Elem>::end() const
{ return Iterator(trailer); }

//modified insert front inserts value until list is full then runs exception
template <typename Elem>
void NodeList<Elem>::insertFront(const Elem& e) throw (Exceptions)	// insert at front
{
    if (counter == maxSize){
        throw Exceptions("The list is full\n");
    }
    insert(begin(), e);
    counter++;
}

template <typename Elem>
void NodeList<Elem>::insertBack(const Elem& e)	// insert at rear
{ insert(end(), e); }

// insert e before p
template <typename Elem>
void NodeList<Elem>::insert(const NodeList::Iterator& p, const Elem& e) {
    Node<Elem>* w = p.v;				// p's node
    Node<Elem>* u = w->prev;				// p's predecessor
    Node<Elem>* v = new Node<Elem>;				// new node to insert
    v->elem = e;
    v->next = w;  w->prev = v;			// link in v before w
    v->prev = u;  u->next = v;			// link in v after u
    n++;
}

//uses erase to erase the first value in the list
template <typename Elem>
void NodeList<Elem>::eraseFront()			// remove first
{ erase(begin()); }

//uses erase to erase last value in the list
template <typename Elem>
void NodeList<Elem>::eraseBack()			// remove last
{ erase(--end()); }

//erases current location of iterator
template <typename Elem>
void NodeList<Elem>::erase(const Iterator& p) {	// remove p
    Node<Elem>* v = p.v;				// node to remove
    Node<Elem>* w = v->next;				// successor
    Node<Elem>* u = v->prev;				// predecessor
    u->next = w;  w->prev = u;			// unlink p
    delete v;					// delete this node
    n--;					// one fewer element
}
//uses iterators to find and return minimum value in the list
template <typename Elem>
double NodeList<Elem>::findMin(const NodeList::Iterator& p){
    double min = 0;
    NodeList::Iterator i = p.begin();
    min = *i;
    for (NodeList::Iterator cursor = p.begin();cursor!=p.end();++cursor){
        if (*cursor<min){
            min = *cursor;
        }
    }
    
    return min;
}
//uses iterators to find and return the maximum value in the list
template <typename Elem>
double NodeList<Elem>::findMax(const Iterator& p){
    double max = 0;
    NodeList::Iterator i = p.begin();
    max = *i;
    for (NodeList::Iterator cursor = p.begin();cursor!=p.end();++cursor){
        if (*cursor>max){
            max = *cursor;
        }
    }
    return max;

}
//uses iterators to find and return the average of all values
template <typename Elem>
double NodeList<Elem>::findAvg(const Iterator& p){
    double total = 0;
    double size= 0;
    for (NodeList::Iterator cursor = p.begin();cursor!=p.end();++cursor){
        total+=*cursor;
        size++;
    }
    return (total/size);
    
}

//calls findmin to find the minimum value in the list and replaces minimum
//with new value if new value is greater then minimum,otherwise does nothing
template <typename Elem>
void NodeList<Elem>::replaceMin(const Elem& newinput,const Iterator& p) {
    double min = 0;
    min = findMin(p);
    if (newinput>min){
        for (NodeList::Iterator cursor = p.begin();cursor!=p.end();++cursor){
            if(*cursor == min){
                insert(cursor, newinput);
                erase(cursor);
                break;  //Allows only one replacement if two values are the same
            }
        }
    }
}
//outputs all the values in the list using iterators
template <typename Elem>
void NodeList<Elem>::output(const Iterator& p){
    cout<<"LIST VALUES:\n";
    for (NodeList::Iterator cursor = p.begin();cursor!=p.end();++cursor){
        cout<< *cursor<<endl;
    }
}


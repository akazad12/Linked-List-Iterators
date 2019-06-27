//
//  listType.cpp
//  Iterator project group 2
//
//  Created by Abul Azad on 12/23/17.
//  Copyright © 2017 Group 2. All rights reserved.
//
#include <iostream>
#include "listType.hpp"
//#include "nodelist.hpp"
#include "gameEntry.hpp"
#include "Exceptions.h"
using namespace std;

template <typename Elem>
class Node{
public:
    Elem elem;
    Node<Elem>* prev;
    Node<Elem>* next;
};


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

template <typename Elem>
void NodeList<Elem>::eraseFront()			// remove first
{ erase(begin()); }

template <typename Elem>
void NodeList<Elem>::eraseBack()			// remove last
{ erase(--end()); }

template <typename Elem>
void NodeList<Elem>::erase(const Iterator& p) {	// remove p
    Node<Elem>* v = p.v;				// node to remove
    Node<Elem>* w = v->next;				// successor
    Node<Elem>* u = v->prev;				// predecessor
    u->next = w;  w->prev = u;			// unlink p
    delete v;					// delete this node
    n--;					// one fewer element
}

template <typename Elem>
double NodeList<Elem>::findMin(const NodeList::Iterator& p){
    double min = 0;
    NodeList::Iterator i = begin();
    min = *i;
    for (NodeList::Iterator cursor = begin();cursor!=end();++cursor){
        if (*cursor<min){
            min = *cursor;
        }
    }
    return min;
    
}

template <typename Elem>
double NodeList<Elem>::findMax(const Iterator& p){
    double max = 0;
    NodeList::Iterator i = begin();
    max = *i;
    for (NodeList::Iterator cursor = begin();cursor!=end();++cursor){
        if (*cursor>max){
            max = *cursor;
        }
    }
    return max;
    
}

template <typename Elem>
double NodeList<Elem>::findAvg(const Iterator& p){
    double total = 0;
    double size= 0;
    for (NodeList::Iterator cursor = begin();cursor!=end();++cursor){
        total+=*cursor;
        size++;
    }
    return (total/size);
    
}


template <typename Elem>
void NodeList<Elem>::replaceMin(const Elem& newinput,const Iterator& p) {/*
    //double min = 0;
    NodeList<Elem>::Iterator min = begin();
    for (NodeList::Iterator cursor = begin();cursor!=end();++cursor){
        cout<<"hello";
        if (*cursor<*min){
            *min = *cursor;
        }
    }
//min = findMin(p);
if (*min<newinput){
        for (NodeList::Iterator cursor = begin();cursor!=end();++cursor){
            if(*cursor == *min){
                cout<<*cursor<<*min;
                insert(cursor, newinput);
                erase(cursor);
                break;  //Allows only one replacement if two values are the same
            }
        }
    }*/
    double min = 0;
    min = findMin(p);
    if (newinput>min){
        for (NodeList::Iterator cursor =begin();cursor!=end();++cursor){
            if(*cursor == min){
                insert(cursor, newinput);
                erase(cursor);
                break;  //Allows only one replacement if two values are the same
            }
        }
    }

}
        
template <typename Elem>
void NodeList<Elem>::output(const Iterator& p){
    cout<<"LIST VALUES:\n";
    for (NodeList::Iterator cursor = begin();cursor!=end();++cursor){
        cout<< *cursor<<endl;
    }
}



void ListType::buildlist_int(int m){
    int value=0;//initializing future user input
    NodeList<int> I(m);// initialing linked list object and setting max size of list
    cout<<"To exit enter -1 "<<endl;
    while (value!=-1){//if user input = -1, program ends
        cout<<"What is your value: "<<endl;
        cin>>value;
        //If List is not full, user input is added to list
        try{
            I.insertFront(value);
        }
        //exception is called when list is full
        
        catch(Exceptions e)
        //If list is full, user input can be added only if
        //input is higher than any values in the list
        {
            cout << "I had an exception: " << e.getError();
            cout<<"Modifying if input greater than minimum value in List"<<endl;
            I.replaceMin(value,I.begin());
        }
        
        I.output(I.begin()); //outputs values in the list
        cout<<"The minimum value is: "<<I.findMin(I.begin())<<endl;
        cout<<"The maximum value is: "<<I.findMax(I.begin())<<endl;
        cout<<"The average is: "<<I.findAvg(I.begin())<<endl;
    }
    
}
void ListType::buildlist_double(int m){
    double value=0;//initializing future user input
    NodeList<double> D(m);// initializing linked list object and setting max size of list
    cout<<"To exit enter -1 "<<endl;
    while (value!=-1){//if user input = -1, program ends
        cout<<"What is your value: "<<endl;
        cin>>value;
        //If List is not full, user input is added to list
        try{
            D.insertFront(value);
        }
        //exception is called when list is full
        
        catch(Exceptions e)
        //If list is full, user input can be added only if
        //input is higher than any values in the list
        {
            cout << "I had an exception: " << e.getError();
            cout<<"Modifying if input greater than minimum value in List"<<endl;
            D.replaceMin(value,D.begin());
        }
        
        D.output(D.begin()); //outputs values in the list
        cout<<"The minimum value is: "<<D.findMin(D.begin())<<endl;
        cout<<"The maximum value is: "<<D.findMax(D.begin())<<endl;
        cout<<"The average is: "<<D.findAvg(D.begin())<<endl;
    }
    
}

/*void ListType::buildlist_gameEntry(int m){
    string username;int score=0;    //initializing future user input
    NodeList<gameEntry> G(m);// initializing linked list object and setting max size of list
    cout<<"To exit enter -1 for both Score and Username"<<endl;
    while (username!="-1"){//if user input = -1, program ends
        cout<<"What is the username: "<<endl;
        cin>>username;
        cout<<"What is the score: "<<endl;
        cin >> score;
        //If List is not full, user input is added to list
        try{
            G.insertFront(gameEntry(username,score));
        }
        //exception is called when list is full
        
        catch(Exceptions e)
        //If list is full, user input can be added only if
        //input is higher than any values in the list
        {
            cout << "I had an exception: " << e.getError();
            cout<<"Modifying if input greater than minimum value in List"<<endl;
            G.replaceMin(gameEntry(username,score),G.begin());
        }
        
        G.output(G.begin()); //outputs values in the list
    }
    
}*/


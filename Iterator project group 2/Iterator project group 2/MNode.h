//
//  MNode.h
//  Iterator project group 2
//
//  Created by Abul Azad on 12/24/17.
//  Copyright © 2017 Group 2. All rights reserved.
//

#ifndef MNode_h
#define MNode_h
template <typename Elem>
class Node{
public:
    Elem elem;
    Node<Elem>* prev;
    Node<Elem>* next;
};

#endif /* MNode_h */

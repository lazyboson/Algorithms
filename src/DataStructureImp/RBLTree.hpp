//
//  RBLtree.hpp
//  CompetitiveProgramming
//
//  Created by Ashutosh Pandey on 11/04/20.
//  Copyright © 2020 Ashutosh Pandey. All rights reserved.
//

#ifndef RBLtree_hpp
#define RBLtree_hpp

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

//a RBT tree have data,color, left, right and parent pointer;
/*Properties of RBL kept in mind -
    1. Every node is either red or black.
    2. The root is black.
    3. Every leaf (NIL) is black.
    4. If a node is red, then both its children are black.
    5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
 */
struct RBTnode{
    int key;
    bool color;
    RBTnode *left, *right, *parent;
};

class RBT{
public:
    //all varibales are public since i am accessing them from main else can be used as private data member
    bool RED, BLACK;
     RBTnode *root;
    //constructor initialize root to nullptr
    RBT(){
        root= nullptr;
        RED = 0;
        BLACK = 1;
    }
    void InorderTraversal(RBTnode*);
    void RBTInsertFixup(RBTnode*);
    void Insertion(RBTnode*);
    void LeftRotate(RBTnode*);
    void RightRotate(RBTnode*);
};


#endif /* RBLtree_hpp */
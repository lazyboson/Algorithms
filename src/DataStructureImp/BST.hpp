//
//  BST.hpp
//  CompetitiveProgramming
//
//  Created by Ashutosh Pandey on 11/04/21.
//  Copyright © 2021 Ashutosh Pandey. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>


//a binary tree have data, left, right pointer;
struct BSTnode{
    int data;
    BSTnode *left;
    BSTnode *right;
    BSTnode *parent;
};

class BST{
    BSTnode *head;
public:
    //constructor initialize all the essential nodes to null
    BST(){
        head = nullptr;
    }
    
    void Insert(BSTnode*);
    BSTnode* TreeSearch(int key);
    BSTnode* TreeMin();
    BSTnode* TreeMax();
    BSTnode* TreeSuccessor(BSTnode*);
};


#endif /* BST_hpp */
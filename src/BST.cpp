//
//  BST.cpp
//  CompetitiveProgramming
//
//  Created by Ashutosh Pandey on 11/04/21.
//  Copyright © 2021 Ashutosh Pandey. All rights reserved.
//

#include "BST.hpp"


//treeminimum
BSTnode* BST::TreeMin(){
    BSTnode *temp = head;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

//tree maxkey
BSTnode* BST::TreeMax(){
    BSTnode *temp = head;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}


//search a key in the tree
BSTnode* BST::TreeSearch(int key){
    BSTnode *temp = head;
    while (temp != nullptr && key != temp->data) {
        if (key < temp->data) {
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    return temp;
}


//insertion function in the BST

void BST::Insert(BSTnode * node){
    BSTnode * y = nullptr;
    BSTnode* x = head;
    while (x != nullptr){
        y = x;
        if (node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    node->parent = y;
    if (y==nullptr)
        head = node; //tree T was the empty
    else if(node->data < y->data)
        y->left = node;
    else
        y->right = node;
}
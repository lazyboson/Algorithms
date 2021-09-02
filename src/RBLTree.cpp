//
//  RBLtree.cpp
//  CompetitiveProgramming
//
//  Created by Ashutosh Pandey on 11/04/20.
//  Copyright © 2020 Ashutosh Pandey. All rights reserved.
//

#include "RBLtree.hpp"


//print the keys of Red Black Tree
void RBT::InorderTraversal(RBTnode* node){
    if (node == nullptr) {
        return;
    }
    InorderTraversal(node->left);
    cout << node->key << "\n";
    InorderTraversal(node->right);
}


void RBT::LeftRotate(RBTnode * node){
    RBTnode * y = node->right; //set y
    node->right = y->left;  //turn y's left subtree into x's rigth subtree
    if (y->left != nullptr) {
        y->left->parent = nullptr;
    }
    y->parent = node->parent;
    if (node->parent == nullptr) {
        root = y;
    }
    else if(node == node->parent->left){
        node->parent->left = y;
    }
    else
        node->parent->right = y;
    y->left = node;
    node->parent = y;
}



void RBT::RightRotate(RBTnode * node){
    RBTnode * y = node->left; //set y
    node->left = y->right;  //turn y's right subtree into x's left subtree
    if (y->right != nullptr) {
        y->right->parent = nullptr;
    }
    y->parent = node->parent;
    if (node->parent == nullptr) {
        root = y;
    }
    else if(node == node->parent->right){
        node->parent->right = y;
    }
    else
        node->parent->left = y;
    y->right = node;
    node->parent = y;
    
}

void RBT::Insertion(RBTnode * node){
    RBTnode * y = nullptr; //this pointer keeps track of the appropriate place of insertion node parent
    RBTnode* x = root;
    while (x != nullptr) {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    node->parent = y;
    if (y== nullptr) {
        root = node;
    }
    else if(node->key < y->key){
        y->left = node;
    }
    else
        y->right = node;
    //set the inserted node colour to RED
    node->left = nullptr;
    node->right = nullptr;
    node->color = RED;
    //passing parent node and it's child to fix RBT property
    RBTInsertFixup(node);
}

void RBT::RBTInsertFixup(RBTnode* node){
  
    //what about the root case simply return or single level of tree no violation of nay property root is BLACK and children is RED at first level
    if (node->parent == nullptr || node->parent->parent == nullptr) {
        return;
    }
    
    while (node->parent->color == RED) {
        RBTnode* y = nullptr;
        if (node->parent== node->parent->parent->left) {
            y =node->parent->parent->right;
            if (y->color == RED) {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else if (node == node->parent->right){
                node = node->parent;
                LeftRotate(node);
            }
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            RightRotate(node->parent->parent);
        }
        else{
            y = node->parent->parent->left;
            if (y->color == RED) {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else if (node == node->parent->left){
                node = node->parent;
                RightRotate(node);
            }
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            LeftRotate(node->parent->parent);
        }
    }
    root->color = BLACK;
}
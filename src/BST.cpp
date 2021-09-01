#include <iostream>

struct Node {
    int key;
    Node *parent;
    Node *left, *right;
};

class BSTNode {
    //root node parents must be nil
    public:
    Node *root;

    BSTNode(){
        root = nullptr;
    }

    void Insert(int _key){
        Node* z = new Node;
        z->key = _key;
        z->parent = z->right = z->left = nullptr;
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            /* code */
            y = x;
            if(_key < x->key){
                x = x->left;
            }
            else {
                x = x->right;
            }
        }
        z->parent = y;
        if(y==nullptr)
            root = z;
        else if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
        
    }

    void InorderTreeWalk(Node *start) {
        if(start !=nullptr){
            InorderTreeWalk(start->left);
            std::cout << start->key <<" ";
            InorderTreeWalk(start->right);
        }
    }

    Node *KeySearch(Node *start, int _key) {
        if( start == nullptr || start->key == _key)
            return start;
        if(start->key > _key)
            return KeySearch(start->left, _key);
        else
            return KeySearch(start->right, _key);
    }

    Node* TreeMinimum(Node *start) {
        while(start->left != nullptr){
            start = start->left;
        }
        return start;
    }

    Node* TreeMaximum(Node *start){
        while(start->right != nullptr) {
            start = start->right;
        }
        return start;
    }

    Node *TreeSuccessor(Node *start) {
        if(start->right != nullptr){
            return TreeMinimum(start->right);
        }
        Node *y = start->parent;
        while(y != nullptr && start == y->right){
            start = y;
            y = y->parent;
        }
        return y;
    }

};

int main(){
    BSTNode _bst;
    _bst.Insert(5);
    _bst.Insert(2);
    _bst.Insert(1);
    _bst.Insert(7);
    _bst.InorderTreeWalk(_bst.root);
    return 0;
}

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

    void Insert(int _key) {
        //create a new node to insert the data
        Node* z = new Node;
        z->key = _key;
        z->parent = z->right = z->left = nullptr;
        //create a dummmy node for updation
        Node* y = nullptr;
        
        //searching for appropriate place to insert
        Node* x = root;
        while (x != nullptr) {
            y = x;
            if(_key < x->key){
                x = x->left;
            }
            else {
                x = x->right;
            }
        }
        //
        z->parent = y;
        if(y==nullptr)
            root = z;
        else if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
        
    }
    
    void TreeDelete(Node* start){
        if(z->left == nullptr){
            Transplant(start, start->right);
        }
        else if (z->right == nullptr){
            Transplant(z, z->left);
        }
        else{
            Node *y = TreeMinimum(z->right);
            if(y->parent != z){
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }

    void Transplant(Node *u, Node *v){
        if(u->parent == nullptr)
            root = v;
        else if (u==u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if( v != nullptr)
            v->parent = u->parent;
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

    Node* TreeMaximum(Node *start) {
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
    _bst.Insert(2000);
    _bst.InorderTreeWalk(_bst.root);
    Node* isFound = _bst.KeySearch(_bst.root,0);
    if(isFound != nullptr)
        std::cout << isFound->key <<std::endl;
    else
        std::cout << "Key Not Found !" <<std::endl;
    Node *maxValue = _bst.TreeMaximum(_bst.root);
    Node *minValue = _bst.TreeMinimum(_bst.root);

    std::cout <<" The Maximum Key Value in the Tree: " << maxValue->key << std::endl;
    std::cout <<" The Minimum Key Value in the Tree: " << minValue->key << std::endl;


    return 0;

}

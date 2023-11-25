#include <iostream>
#include "tree.h"
using namespace std;

binTree::binTree(){
    root = nullptr;
}

void binTree::insert(int data){
    if(!root){
        root = new node{data, nullptr, nullptr};
        return;
    }

    node *curr = root, *prev;
    while(curr){
        prev = curr;
        if(curr->data < data) {
            curr = curr->right;
        } else if(curr->data > data) {
            curr = curr->left;
        } else return;
    }

    if(prev->data < data) {
        prev->right = new node{data, nullptr, nullptr};
    } else if(prev->data > data) {
        prev->left = new node{data, nullptr, nullptr};
    }
}

node* binTree::searchBranch(node* Node, int data){
    if(!Node || Node->data == data) return Node;

    node *left, *right;
    left = searchBranch(root->left, data);
    right = searchBranch(root->right, data);
    if(left){
        return left;
    } else{
        return right;
    }
}

node* binTree::search(int data){
    return searchBranch(root, data);
}

void binTree::print(){
    printBranch(root, 0);
    cout << "\n";
}

void binTree::printBranch(node* Node, int level){
    if(Node){
        printBranch(Node->right, level + 1);
        for(int i = 0; i < level; i++) cout << "   ";
        cout << Node->data << endl;

        printBranch(Node->left, level + 1);
    }
}

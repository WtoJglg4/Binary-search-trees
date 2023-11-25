#include <iostream>
#include <math.h>
#include <map>
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

bool binTree::deleteNode(int data){
    node *search = preOrderSearch(data); //поиск элемента в дереве
    if(!search || !root) return false;   //элемента в дереве нет

    node *curr = root, *prev;   //curr - элемент, который будем удалять, prev - перед ним
    while(curr){
        prev = curr;
        if(curr->data < data){ 
            curr = curr->right;
        } else if(curr->data > data){
            curr = curr->left;
        } 

        if(curr->data == data) break;
    }

    if(!curr->left && !curr->right){    //curr - лист дерева
        if(prev == curr) root = nullptr; //удаляем root

        if(prev->right == curr){
            prev->right = nullptr;
        } else{
            prev->left = nullptr;
        }
        delete curr;

    } else if(!curr->left && curr->right){ //справа есть ветка
        if(prev == curr) root = curr->right;    //удаляем root

        if(prev->right == curr){
            prev->right = curr->right;
        } else{
            prev->left = curr->right;
        }
        delete curr;
        
    } else if(curr->left && !curr->right){ //слева есть ветка
        if(prev == curr) root = curr->left;    //удаляем root

        if(prev->right == curr){
            prev->right = curr->left;
        } else{
            prev->left = curr->left;
        }
        delete curr;
    } else {    //у удаляемого элемента две ветки
       
        //найдем потомка слева
        node* leftChild = curr->left, *leftPred = curr; //левый потомок и предшествующий левого потомка
        while(leftChild->right){
            leftPred = leftChild;
            leftChild = leftChild->right;
        }
        
        //найдем потомка справа
        node* rightChild = curr->right, *rightPrev = curr;  //правый потомок и предшествующий правого потомка
        while(rightChild->left){
            rightPrev = rightChild;
            rightChild = rightChild->left;
        }
        
        //какой ближе к удаляемому по модулю
        if(abs(rightChild->data - curr->data) < abs(leftChild->data - curr->data)){ //если правый
            if(rightPrev->left == rightChild) rightPrev->left = rightChild->right;  //если заходили в цикл, соединим нужные ветки

            if(rightChild == curr->right) curr->right = rightChild->right;  //если не заходили в цикл(поток непосредственно справа от curr)
            curr->data = rightChild->data;  //переставили
            delete rightChild;
            
        } else {    //если левый
            if(leftPred->right == leftChild) leftPred->right = leftChild->left; //если заходили в цикл, соединим нужные ветки
            
            if(leftChild == curr->left) curr->left = leftChild->left;   //если не заходили в цикл(поток непосредственно слева от curr)
            curr->data = leftChild->data;   //переставили
            delete leftChild;
        }
    }
    return true;
}

node* binTree::searchFromNode(node* Node, int data){
    if(!Node || Node->data == data) return Node;

    node *left, *right;
    left = searchFromNode(Node->left, data);
    right = searchFromNode(Node->right, data);
    
    //если не null 
    if(left){
        return left;
    } else {
        return right;
    }
}

//preorder(прямой обход)
node* binTree::preOrderSearch(int data){
    return searchFromNode(root, data);
}

void binTree::print(){
    if(!root){
        cerr << "tree is empty\n";
        return;
    } else printf("Tree:\nNodes: %d\tHigh: %d\n", nodesQuantity(), high());
    printFromNode(root, 0);
    cout << "\n";
}

void binTree::printFromNode(node* Node, int level){
    if(Node){
       if(Node->right) printFromNode(Node->right, level + 1);
        for(int i = 0; i < level; i++) cout << "   ";
        cout << Node->data << endl;

        if(Node->left) printFromNode(Node->left, level + 1);
    }
}

int binTree::nodesQuantity(){
    return nodesQuantityFromNode(root);
}

int binTree::nodesQuantityFromNode(node* Node){
    if(!Node) return 0;
    return 1 + nodesQuantityFromNode(Node->left) + nodesQuantityFromNode(Node->right);
}

int binTree::high(){
    return highFromNode(root) - 1;
}

int binTree::highFromNode(node* Node){
    if(!Node) return 0;
    return 1 + max(highFromNode(Node->left), highFromNode(Node->right));
}

map<int, int>* binTree::getEvenLevels(){
    map<int, int>* evenLevels = new map<int, int>;
    getEvenLevelsFromNode(root, 0, *evenLevels);
    return evenLevels;
}

void binTree::getEvenLevelsFromNode(node* Node, int level, map<int, int> &evenLevels){
    if(!Node) return;

    if(Node->data % 2 == 0) evenLevels[Node->data] = level;
    getEvenLevelsFromNode(Node->left, level+1, evenLevels);
    getEvenLevelsFromNode(Node->right, level+1, evenLevels);
}

void binTree::printLevelMap(map<int, int>* evenLevels){
    cout << "evenLevels:\n[";
    for(auto it = evenLevels->begin(); it != evenLevels->end(); it++){
        printf("{%d, %d} ", it->first, it->second);
    }    
    cout << "]\n";
}

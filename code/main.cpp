#include <iostream>
#include <map>
#include "tree.h"
using namespace std;

//g++ main.cpp tree.cpp -o output
int main(){
    
    binTree tree;
    tree.insert(10);
    tree.insert(6);
    tree.insert(1);
    tree.insert(8);
    tree.insert(25);
    tree.insert(30);
    tree.insert(20);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.print();
    map<int, int>* evenLevels = tree.getEvenLevels();
    tree.printLevelMap(evenLevels);

    node* Node = tree.preOrderSearch(30);

    tree.insert(7);
    tree.print();
   
    tree.deleteNode(10);
    tree.print();
    tree.deleteNode(6);
    tree.print();
    tree.deleteNode(1);
    tree.print();
    tree.deleteNode(8);
    tree.print();
    tree.deleteNode(25);
    tree.print();
    tree.deleteNode(30);
    tree.print();
    tree.deleteNode(20);
    tree.print();
    tree.deleteNode(12);
    tree.print();
    tree.deleteNode(7);
    tree.print();
    

    char a;
    cin >> a;
}
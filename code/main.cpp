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
    tree.insert(7);
    tree.print();
    map<int, int>* evenLevels = tree.getEvenLevels();
    tree.printLevelMap(evenLevels);

    node* Node = tree.preOrderSearch(30);
    if(Node) {
        cout << 30 << " in tree\n" << endl;
    } else cout << 30 << " not in tree\n" << endl;
    
    Node = tree.preOrderSearch(100);
    if(Node) {
        cout << 100 << " in tree\n" << endl;
    } else cout << 100 << " not in tree\n" << endl;

    bool deleted = tree.deleteNode(10);
    if(deleted) cout << "Deleted: " << 10 << endl;
    tree.print();

    deleted = tree.deleteNode(6);
    if(deleted) cout << "Deleted: " << 6 << endl;
    tree.print();

    deleted = tree.deleteNode(25);
    if(deleted) cout << "Deleted: " << 25 << endl;
    tree.print();
    
    char a;
    cin >> a;
}
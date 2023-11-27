#include <iostream>
#include <map>
#include "tree.h"
using namespace std;

//g++ main.cpp tree.cpp -o output
int main(){
    
    int V[]{10, 6, 1, 8, 25, 30, 20, 12, 13, 14, 7};
    binTree tree;

    for(int i = 0; i < size(V); i++) tree.insert(V[i]);
    tree.print();

    //обходы
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();

    map<int, int>* evenLevels = tree.getEvenLevels();
    tree.printLevelMap(evenLevels);

    node* Node = tree.search(30);
    if(Node) {
        cout << 30 << " in tree\n" << endl;
    } else cout << 30 << " not in tree\n" << endl;
    
    Node = tree.search(100);
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
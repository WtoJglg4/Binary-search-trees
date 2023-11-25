#ifndef TREE_H
#define TREE_H
#include <map>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

class binTree{
    private:
        void printFromNode(node* node , int level);
        node* searchFromNode(node* node, int data);
        int nodesQuantityFromNode(node* node);
        int highFromNode(node* node);
        void getEvenLevelsFromNode(node* Node, int level, map<int, int> &evenLevels);
    public:
        node* root;
        binTree();
        void insert(int data);
        bool deleteNode(int data);
        node* preOrderSearch(int data);
        void print();
        int nodesQuantity();
        int high();
        map<int, int>* getEvenLevels();
        void printLevelMap(map<int, int>* evenLevels);

};

#endif
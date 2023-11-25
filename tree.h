#ifndef TREE_H
#define TREE_H

struct node{
    int data;
    node *left, *right;
};

class binTree{
    private:
        void printBranch(node* node , int level);
        node* searchBranch(node* node, int data);
    public:
        node* root;
        binTree();
        void insert(int data);
        node* search(int data);
        void print();

};

#endif
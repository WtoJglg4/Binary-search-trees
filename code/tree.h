#ifndef TREE_H
#define TREE_H
#include <map>
using namespace std;

//узел дерева
struct node{
    int data;           //ключ
    node *left, *right; //левый, правый узел
};

//бинарное дерево
class binTree{
    private:
        void printFromNode(node* node , int level); //рекурсивная печать начиная с узла
        void getEvenLevelsFromNode(node* Node, int level, map<int, int> &evenLevels);   //рекурсивное заполнение мапы
        int nodesQuantityFromNode(node* node);      //рекурсивный подсчет узлов-потомков
        int highFromNode(node* node);               //рекурсивный подсчет высоты
        node* searchFromNode(node* node, int data); //рекурсивный поиск начиная с узла

        void inOrderFromNode(node* node);      
        void preOrderFromNode(node* node);   
        void postOrderFromNode(node* node);   

    public:
        node* root; //корень

        binTree();  //конструктор

        void insert(int data);                          //вставка элемента
        bool deleteNode(int data);                      //удаление эелемента
        int nodesQuantity();                            //количество узлов
        int high();                                     //высота дерева
        
        node* search(int data);                         //поиск по дереву

        void inOrder();                                 //симметричный обход
        void preOrder();                                //прямой обход
        void postOrder();                               //обратный обход
        
        map<int, int>* getEvenLevels();                 //мапа: {четный ключ: длина пути от корня}
        
        void print();                                   //печать дерева
        void printLevelMap(map<int, int>* evenLevels);  //печать мапы
};

#endif
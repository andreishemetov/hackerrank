//
//  tree_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 25.12.22.
//

#include "tree_ex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <new>

using namespace std;


class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void printNode(Node *node){
    cout<<node->data<<" ";
    if (node->left) printNode(node->left);
    if (node->right) printNode(node->right);
}

void preOrder(Node *root) {
    printNode(root);
    cout<<endl;
}

void tree_ex(){
    Node *node = new Node(1);
    node->right = new Node(2);
    Node *nodeRight = node->right;
    nodeRight->right = new Node(5);
    nodeRight = nodeRight->right;
    nodeRight->right = new Node(6);
    nodeRight->left = new Node(3);
    Node *nodeLeft = nodeRight->left;
    nodeLeft->right = new Node(4);
    
    preOrder(node);
}



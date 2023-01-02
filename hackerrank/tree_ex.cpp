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
#include <queue>

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

void prePrintNode(Node *node){
    cout<<node->data<<" ";
    if (node->left) prePrintNode(node->left);
    if (node->right) prePrintNode(node->right);
}

void postPrintNode(Node *node){
    if (node->left) postPrintNode(node->left);
    if (node->right) postPrintNode(node->right);
    cout<<node->data<<" ";
}

void inPrintNode(Node *node){
    if (node->left) inPrintNode(node->left);
    cout<<node->data<<" ";
    if (node->right) inPrintNode(node->right);
}

void preOrder(Node *root) {
    prePrintNode(root);
    cout<<endl;
}

void postOrder(Node *root) {
    postPrintNode(root);
    cout<<endl;
}

void inOrder(Node *root) {
    inPrintNode(root);
    cout<<endl;
}

void height_calculate(Node *node, int *height) {
    int left = *height;
    int right = *height;
    if (node->right) {
        right +=1;
        height_calculate(node->right, &right);
    }
    if (node->left) {
        left += 1;
        height_calculate(node->left, &left);
    };
    *height = max(left, right);
}

int height(Node* node) {
    //    int height = 0;
    //    height_calculate(node, &height);
    //    return height;
    
    if (!node || (!node->left && !node->right)){
        return 0;
    } else {
        return 1+max(height(node->left), height(node->right));
    }
}

void printLevelOrder(Node* node){
    vector<vector<int>> data = {{node->data}};
    cout<<node->data<<" ";
    vector<Node*> nodes = {node};
    while (!nodes.empty()) {
        vector<Node*> newNodes;
        vector<int> newData;
        for (int i=0; i<nodes.size(); i++){
            if (nodes[i]->left) {
                newNodes.push_back(nodes[i]->left);
                newData.push_back(nodes[i]->left->data);
                cout<<nodes[i]->left->data<<" ";
            }
            if (nodes[i]->right) {
                newNodes.push_back(nodes[i]->right);
                newData.push_back(nodes[i]->right->data);
                cout<<nodes[i]->right->data<<" ";
            }
        }
        nodes = newNodes;
        data.push_back(newData);
    }
    cout<<endl;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        root->left = insert(root->left, data);
    }
    return root;
}

void tree_ex(){
    Node *node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(7);
    Node *nodeLeft = node->left;
    nodeLeft->right = new Node(3);
    nodeLeft->left = new Node(1);
    
    //    inOrder(node);
    //    int h = height(node);
    printLevelOrder(node);
    insert(node, 6);
    
}



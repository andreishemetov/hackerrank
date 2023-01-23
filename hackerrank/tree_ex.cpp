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

void inPrintNode(Node *node, vector<int> *values){
    if (node->left) inPrintNode(node->left, values);
    values->push_back(node->data);
    cout<<node->data<<" ";
    if (node->right) inPrintNode(node->right, values);
}

void preOrder(Node *root) {
    prePrintNode(root);
    cout<<endl;
}

void postOrder(Node *root) {
    postPrintNode(root);
    cout<<endl;
}

vector<int>* inOrder(Node *root) {
    vector<int> *values = new vector<int>();
    inPrintNode(root, values);
    cout<<endl;
    return values;
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

Node *lca(Node *root, int v1, int v2) {
    
    // best solution (recurcive)
    if (root == NULL)
        return NULL;
    
    // If both n1 and n2 are smaller
    // than root, then LCA lies in left
    if (root->data > v1 && root->data > v2)
        return lca(root->left, v1, v2);
    
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (root->data < v1 && root->data < v2)
        return lca(root->right, v1, v2);
    
    return root;
    
    /* my solution
     Node *node = root;
     while (node) {
     if (node->data > v1 && node->data > v2 && node->left != NULL) {
     node = node->left;
     } else if (node->data < v1 && node->data < v2 && node->right != NULL) {
     node = node->right;
     } else {
     return node;
     }
     
     }
     return root;
     */
}

Node* buildTree(vector<vector<int>> indexes){
    Node *root = new Node(1);
    vector<Node*> levelNodes = {root};
    
    vector<Node*> newLevelNodes = vector<Node*>();
    for (int i=0; i<indexes.size(); i++){
        if (levelNodes.empty() && !newLevelNodes.empty()) {
            levelNodes = newLevelNodes;
            newLevelNodes = vector<Node*>();
        }
        Node* node = levelNodes[0];
        levelNodes.erase(levelNodes.begin());
        if (indexes[i][0] != -1) {
            Node* left = new Node(indexes[i][0]);
            node->left = left;
            newLevelNodes.push_back(left);
        }
        if (indexes[i][1] != -1) {
            Node* right = new Node(indexes[i][1]);
            node->right = right;
            newLevelNodes.push_back(right);
        }
    }
    
    return root;
}

void swap(Node *node) {
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void swapChildsAndGo(Node *node, int level, int query) {
    if (level % query == 0) {
        swap(node);
    }
    if (node->left != NULL) {
        swapChildsAndGo(node->left, level+1, query);
    }
    if (node->right != NULL) {
        swapChildsAndGo(node->right, level+1, query);
    }
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    Node *root = buildTree(indexes);
    vector<vector<int>> result = {};
    for (int i=0; i<queries.size(); i++) {
        swapChildsAndGo(root, 1, queries[i]);
        result.push_back(*inOrder(root));
    }
    return result;
}

void swapNodes_ex() {
    vector<vector<int>> indexes = {
        {2,3},
        {4,-1}, {5,-1},
        {6,-1}, {7,8},
        {-1,9}, {-1,-1}, {10,11},
        {-1,-1}, {-1,-1}, {-1,-1}
    };
    vector<int> queries = {2,4};
    
    vector<vector<int>> calcResult = swapNodes(indexes, queries);
    vector<vector<int>> expResult = {
        {2,9,6,4,1,3,7,5,11,8,10},
        {2,6,9,4,1,3,7,5,10,8,11}
    };
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<">> Test "<<result<<endl;
    cout<<endl;
}

void tree_ex(){
    Node *node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(7);
    node->right->left = new Node(6);
    Node *nodeLeft = node->left;
    nodeLeft->right = new Node(3);
    nodeLeft->left = new Node(1);
    
    //    inOrder(node);
    //    int h = height(node);
    //    printLevelOrder(node);
    //    insert(node, 6);
//  Node* reuslt = lca(node, 1, 7);
    
    swapNodes_ex();
    
    
}


class CharNode {
public:
    int freq;
    char data;
    CharNode *left;
    CharNode *right;
    CharNode(char d, int f) {
        data = d;
        freq = f;
        left = NULL;
        right = NULL;
    }
};


string huffman_decode_huff(CharNode *root, string s) {
    string result = "";
    CharNode *node = root;
    for (int i=0; i<s.length(); i++){
        char c = s[i];
        if (c == '0' && node->left) {
            node = node->left;
        } else if (node->right) {
            node = node->right;
        }
        if (node->data){
            result += node->data;
            node = root;
        }
    }
    return result;
}

void tree_huffman_decoding_ex(){
    cout << "tree_huffman_decoding_ex\n";
    
    CharNode *node = new CharNode(NULL, 5);
    node->left = new CharNode(NULL, 2);
    node->right = new CharNode('A', 3);
    CharNode *nodeLeft = node->left;
    nodeLeft->right = new CharNode('C', 1);
    nodeLeft->left = new CharNode('B', 1);
    
    string input = "1001011";
    string calcResult = huffman_decode_huff(node, input);
    string expResult = "ABACA";
    string result = calcResult == expResult ? "SUCCESS" : "FAILURE";
    cout <<"calcResult:"<<calcResult<<" expResult:"<<expResult<<" >> Test "<<result<<endl;
    cout<<endl;
}


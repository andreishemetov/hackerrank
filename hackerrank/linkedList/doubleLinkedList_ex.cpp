//
//  doubleLinkedList_ex.cpp
//  hackerrank
//
//  Created by Andrei Shemetov on 25.12.22.
//

#include "linkedList_ex.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <new>

using namespace std;

class DoubleLinkedListNode {
public:
    int data;
    DoubleLinkedListNode* next = NULL;
    DoubleLinkedListNode* prev = NULL;
    
    DoubleLinkedListNode(int data) {
        this->data = data;
    }
    
    DoubleLinkedListNode(int data, DoubleLinkedListNode* next, DoubleLinkedListNode* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    
};

DoubleLinkedListNode* sortedInsert(DoubleLinkedListNode* llist, int data) {
    if (llist->data > data) {
        DoubleLinkedListNode *root = new DoubleLinkedListNode(data, llist, NULL);
        llist->prev = root;
        return root;
    }
    
    DoubleLinkedListNode *node = llist;
    while (node->next != NULL && node->next->data < data) {
        node = node->next;
    }
    
    DoubleLinkedListNode *newNode = new DoubleLinkedListNode(data, node->next, node);
    if (node->next != NULL){
        node->next->prev = newNode;
    }    
    node->next = newNode;
    
    return llist;
}

DoubleLinkedListNode* reverse(DoubleLinkedListNode* llist) {
    DoubleLinkedListNode *node = llist;
    while (1) {
        DoubleLinkedListNode *temp = node->next;
        node->next = node->prev;
        node->prev = temp;
        if (temp == NULL){
            break;
        }
        node = temp;
    }
    return node;
}


void doubleLinkedList_ex(){
    DoubleLinkedListNode *sortedList = new DoubleLinkedListNode(1);
    DoubleLinkedListNode *node = sortedList;
    DoubleLinkedListNode *nextNode = new DoubleLinkedListNode(3, NULL, node);
    node->next = nextNode;
    node = nextNode;
    nextNode = new DoubleLinkedListNode(4, NULL, node);
    node->next = nextNode;
    node = nextNode;
    nextNode = new DoubleLinkedListNode(10, NULL, node);
    node->next = nextNode;
    
//    sortedList = sortedInsert(sortedList, 11);
    DoubleLinkedListNode *reversedList = reverse(sortedList);
}

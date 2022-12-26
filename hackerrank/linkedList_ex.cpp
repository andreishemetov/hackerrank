//
//  linkedList_ex.cpp
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


class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next = NULL;
    
    SinglyLinkedListNode(int data) {
        this->data = data;
    }
};

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if (head == nullptr) {
        return new SinglyLinkedListNode(data);
    }
    SinglyLinkedListNode* node = head;
    while (node->next) {
        node = node->next;
    }
    node->next = new SinglyLinkedListNode(data);
    return head;
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    if (llist == nullptr) {
        return new SinglyLinkedListNode(data);
    }
    SinglyLinkedListNode *head = new SinglyLinkedListNode(data);
    head->next = llist;
    return head;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if (position == 0) {
            newNode->next = llist;
            return newNode;
        }
            
        SinglyLinkedListNode* node = llist;
        int pos = 0;
        while (node->next) {
            pos++;
            if (pos == position){
                SinglyLinkedListNode* nextNode = node->next;
                node->next = newNode;
                newNode->next = nextNode;
                break;
            }
            node = node->next;
        }
        return llist;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
        if (position == 0) {
            return llist->next;
        }
            
        SinglyLinkedListNode* node = llist;
        int pos = 0;
        while (node->next) {
            pos++;
            if (pos == position){
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return llist;
}

void linkedList_ex(){
    SinglyLinkedListNode *list = NULL;
    list = insertNodeAtTail(list, 1);
    list = insertNodeAtTail(list, 2);
    list = insertNodeAtTail(list, 3);
    list = insertNodeAtTail(list, 4);
    list = insertNodeAtTail(list, 5);
    list = insertNodeAtHead(list, 0);
}



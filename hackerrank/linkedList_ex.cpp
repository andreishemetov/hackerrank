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

void printList(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *node = llist;
    while (node) {
        cout<< node->data <<endl;
        node = node->next;
    }
}

SinglyLinkedListNode* reverseList(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *current = llist;
    SinglyLinkedListNode *prev = nullptr;
    while (current) {
        SinglyLinkedListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    llist = prev;
    return llist;
}


bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* node1 = head1;
    SinglyLinkedListNode* node2 = head2;
     while (node1 && node2) {
            if (node1->data != node2->data) {
                return false;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
    return !node1 && !node2;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1) {
        return head2;
    } else if (!head2){
        return head1;
    }
    
    SinglyLinkedListNode* node1 = head1;
    SinglyLinkedListNode* node2 = head2;
    SinglyLinkedListNode *head = nullptr;
    SinglyLinkedListNode *tail = nullptr;
    while (node1 && node2) {
        SinglyLinkedListNode *node;
        if (node1->data < node2->data){
            node = node1;
            node1 = node1->next;
        } else {
            node = node2;
            node2 = node2->next;
        }
        if (tail == nullptr) {
            tail = node;
            head = tail;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }
    tail->next = node1 ? node1 : node2;
    return head;
}

void linkedList_ex(){
    SinglyLinkedListNode *list = NULL;
    list = insertNodeAtTail(list, 1);
    list = insertNodeAtTail(list, 2);
    list = insertNodeAtTail(list, 3);
    list = insertNodeAtTail(list, 4);
    list = insertNodeAtTail(list, 5);
    list = insertNodeAtTail(list, 6);
    list = insertNodeAtTail(list, 16);
    list = insertNodeAtTail(list, 26);
    list = insertNodeAtHead(list, 0);
//    list = reverseList(list);
//    printList(list);
    
    SinglyLinkedListNode *list2 = NULL;
    list2 = insertNodeAtTail(list2, 1);
    list2 = insertNodeAtTail(list2, 2);
    list2 = insertNodeAtTail(list2, 5);
    
    mergeLists(list, list2);
}



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

int getNodeFromTailPosition(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode *node = llist;
    SinglyLinkedListNode *temp = llist;
    
    int dist = 0;
    
    while (temp->next) {
        temp = temp->next;
        dist++;
        if (dist>=positionFromTail+1){
            node = node->next;
        }
    }
    return  node->data;
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *node = llist;
    SinglyLinkedListNode *head = node;
    SinglyLinkedListNode *temp = node;
    while (temp) {
        if (node->data != temp->data){
            node->next = temp;
            node = node->next;
        }
        temp = temp->next;
    }
    node->next = nullptr;
    return head;
}

bool has_cycle(SinglyLinkedListNode* head) {
    if (head == nullptr) return false;
    SinglyLinkedListNode *pointer = head;
    SinglyLinkedListNode *fastPointer = head;
    while (fastPointer != nullptr && fastPointer->next != nullptr) {
        pointer = pointer->next;
        fastPointer = fastPointer->next->next;
        if (pointer == fastPointer) return true;
    }
    return false;
}
/*
 https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150
2. Add Two Numbers
 You are given two non-empty linked lists representing two non-negative integers.
 The digits are stored in reverse order, and each of their nodes contains a single digit.
 Add the two numbers and return the sum as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Example 1:
 Input: l1 = [2,4,3], l2 = [5,6,4]
 Output: [7,0,8]
 Explanation: 342 + 465 = 807. 
*/

SinglyLinkedListNode* addTwoNumbers(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2) {
    SinglyLinkedListNode *result = nullptr;
    SinglyLinkedListNode *pr = nullptr;
    SinglyLinkedListNode *pl1 = l1;
    SinglyLinkedListNode *pl2 = l2;
    int added = 0;
    while (pl1 != nullptr || pl2 != nullptr) {
        int n1 = pl1 == nullptr ? 0 : pl1->data;
        int n2 = pl2 == nullptr ? 0 : pl2->data;
        int summ = n1 + n2 + added;
        int n = summ % 10;
        added = summ / 10;
        if (pr == nullptr){
            pr = new SinglyLinkedListNode(n);
            result = pr;
        } else {
            pr->next = new SinglyLinkedListNode(n);
            pr = pr->next;
        }
        if (pl1 != nullptr) pl1 = pl1->next;
        if (pl2 != nullptr) pl2 = pl2->next;
    }
    if (added > 0){
        pr->next = new SinglyLinkedListNode(added);
    }
    return result;
}


void linkedList_ex(){
    SinglyLinkedListNode *list = NULL;
    list = insertNodeAtTail(list, 1);
    list = insertNodeAtTail(list, 2);
    list = insertNodeAtTail(list, 3);
    list = insertNodeAtTail(list, 4);
    list = insertNodeAtTail(list, 5);
    list = insertNodeAtTail(list, 6);
    list = insertNodeAtHead(list, 0);
    //    list = reverseList(list);
    //    printList(list);
    
    SinglyLinkedListNode *list2 = NULL;
    list2 = insertNodeAtTail(list2, 1);
    list2 = insertNodeAtTail(list2, 2);
    list2 = insertNodeAtTail(list2, 5);
    
//    int v = getNodeFromTailPosition(list, 2);
    
    SinglyLinkedListNode *list3 = NULL;
    list3 = insertNodeAtTail(list3, 2);
    list3 = insertNodeAtTail(list3, 4);
    list3 = insertNodeAtTail(list3, 3);
    
    SinglyLinkedListNode *list4 = NULL;
    list4 = insertNodeAtTail(list4, 5);
    list4 = insertNodeAtTail(list4, 6);
    list4 = insertNodeAtTail(list4, 4);
    
    SinglyLinkedListNode *list5 = addTwoNumbers(list3, list4);
    printf("asda");
}



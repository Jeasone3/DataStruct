//
// Created by Jesone on 2026/8/27.
//

#include "DLKlist.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static DLKNode* BuyListNode(DLKDataType data) {
    DLKNode* newNode = (DLKNode*)malloc(sizeof(DLKNode));
    newNode->data = data;
    newNode->pre = NULL;
    newNode->next = NULL;
    return newNode;
}

DLKNode* DLKlistInit() {
    DLKNode* phead = BuyListNode(0);
    phead->next = phead;
    phead->pre = phead;
    return phead;
}

void DLKlistDestroy(DLKNode *plist) {
    assert(plist);
    DLKNode* current = plist->next;
    while(current != plist) {
        DLKNode* next = current->next;
        free(current);
        current = next;
    }
    free(plist);
    plist = NULL;
}

void DLKlistPushBack(DLKNode *head, DLKDataType data) {
    assert(head);
    DLKNode* tail = head->pre;
    DLKNode* newNode = BuyListNode(data);
    tail->next = newNode;
    newNode->pre = tail;

    newNode->next = head;
    head->pre = newNode;
}

void DLKlistPrint(DLKNode *head) {
    DLKNode* current = head->next;
    while(current != head) {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\r\n");
}

void DLKlsitPushFount(DLKNode *head, DLKDataType data) {
    assert(head);
    DLKNode* first = head->next;
    DLKNode* newNode = BuyListNode(data);
    newNode->next = first;
    first->pre = newNode;

    newNode->pre = head;
    head->next = newNode;

    // DLKNode* present = BuyListNode(data);
    // present->next = head->next;
    // head->next->pre = present;
    //
    // present->pre = head;
    // head->next = present;
}

void DLKlistPopBack(DLKNode *head) {
    assert(head);
    DLKNode* tail = head->pre;
    DLKNode* current = tail->pre;
    current->next = head;
    head->pre = current;
    free(tail);
    tail = NULL;
}

void DLKlistPopFront(DLKNode *head) {
    assert(head);
    assert(head->next != head);
    DLKNode* sec = head->next->next;
    free(head->next);
    head->next = NULL;

    sec->pre = head;
    head->next = sec;
}

DLKNode * ListFind(DLKNode *head, DLKDataType data) {
    assert(head);
    DLKNode* current = head->next;
    while(current != head) {
        if(current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void DLKlistInsert(DLKNode *pos, DLKDataType data) {
    assert(pos);
    DLKNode* newNode = BuyListNode(data);
    DLKNode* prev = pos->pre;
    newNode->next = pos;
    pos->pre = newNode;
    newNode->pre = prev;
    prev->next = newNode;
}

void DLKlistErase(DLKNode *pos) {
    assert(pos);
    DLKNode* prev = pos->pre;
    DLKNode* tail = pos->next;
    prev->next = tail;
    tail->pre = prev;
    free(pos);
    pos = NULL;
}

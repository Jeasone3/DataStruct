//
// Created by Jesone on 2026/8/24.
//

#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

static LKNode* LKNodeCreate(LKDataType data) {
    LKNode *newcode = (LKNode *)malloc(sizeof(LKNode));
    newcode->data = data;
    newcode->next = NULL;
    return newcode;
}

void LKprint(LKNode *phead) {
    LKNode *current = phead;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void LKListPushBack(LKNode **phead, LKDataType data) {
    LKNode* newcode =  LKNodeCreate(data);
    LKNode *tail = *phead;
    if (*phead == NULL) {
        *phead = newcode;

    }else {
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newcode;
    }

}

void LKistPushFront(LKNode **phead, LKDataType data) {
    LKNode* newcode = LKNodeCreate(data);
    newcode->next = *phead;
    *phead = newcode;
}

void LKlistPopBack(LKNode **phead) {
    //空表
    if (*phead == NULL) {
        return;
    }
    //一个节点
    if ((*phead)->next == NULL) {
        free(*phead);
        *phead = NULL;
        return;
    }
    //一个以上节点
    LKNode *pre = NULL;
    LKNode* tail = *phead;
    while (tail->next != NULL) {
        pre = tail;
        tail = tail->next;
    }
    free(tail);
    pre->next = NULL;

}

void LKlistPopFront(LKNode **phead) {
    LKNode *next = (*phead)->next;
    free(*phead);
    *phead = next;
}

LKNode * LKlistFind(LKNode *phead, LKDataType data) {
    LKNode *current = phead;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void LKlistInsert(LKNode **phead, LKNode *pos, LKDataType data) {
    if (pos == *phead) {
        LKistPushFront(phead,data);
    }else {
        LKNode* newNode = LKNodeCreate(data);
        LKNode *current = *phead;
        while (current->next != pos) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = pos;
    }

}

void LKlistErase(LKNode **phead, LKNode* pos) {
    if (pos == *phead) {
        LKlistPopFront(phead);
    }else {
        LKNode *current = *phead;
        while (current->next != pos) {
            current = current->next;
        }
        current->next = pos->next;
        free(pos);
    }
}
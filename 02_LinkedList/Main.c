#include <stdio.h>

#include "LinkedList.h"
//
// Created by Jesone on 2026/8/24.
//

void SLTest1() {
    LKNode* plist = NULL;
    LKListPushBack(&plist,1);
    LKListPushBack(&plist,2);
    LKListPushBack(&plist,3);
    LKListPushBack(&plist,4);
    LKistPushFront(&plist,5);
    LKprint(plist);
}

void SLTest2() {
    LKNode* plist = NULL;
    LKListPushBack(&plist,1);
    LKListPushBack(&plist,2);
    LKListPushBack(&plist,3);
    LKListPushBack(&plist,4);
    LKNode* cur = LKlistFind(plist,3);
    printf("\n %d \n",cur->data);
    LKlistInsert(&plist,cur,40);
    LKprint(plist);
    LKlistErase(&plist,cur);
    printf("\n");
    LKprint(plist);
}

int main() {
    SLTest1();
    SLTest2();
    return 0;
}
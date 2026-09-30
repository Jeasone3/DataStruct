//
// Created by Jesone on 2026/8/22.
//
#include "SeqList.h"
void TestSeqList1() {
    SL sl;
    SeqListInit(&sl);
    SeqListPushFront(&sl,1);
    SeqListPushFront(&sl,2);
    SeqListPushFront(&sl,3);
    SeqListPushFront(&sl,4);
}

int main() {
    TestSeqList1();
    return 0;
}

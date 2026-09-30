//
// Created by Jesone on 2026/8/27.
//


#include "DLKlist.h"

static void TestList1() {
    DLKNode* plist = DLKlistInit();
    DLKlistInit();
    DLKlistPushBack(plist,1);
    DLKlistPushBack(plist,2);
    DLKlistPushBack(plist,3);
    DLKlistPrint(plist);
    DLKlsitPushFount(plist,0);
    DLKlistPrint(plist);
    DLKlistPopFront(plist);
    DLKlistPrint(plist);
    DLKlistPopBack(plist);
    DLKlistPrint(plist);
    DLKNode* pos = ListFind(plist,1);
    DLKlistInsert(pos,400);
    DLKlistPrint(plist);
    DLKlistDestroy(plist);
}

int main() {
    TestList1();
    return 0;
}

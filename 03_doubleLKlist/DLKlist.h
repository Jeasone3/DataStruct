//
// Created by Jesone on 2026/8/27.
//

#ifndef DATASTRUCT_DLKLIST_H
#define DATASTRUCT_DLKLIST_H
//带头，双向循环链表
typedef int DLKDataType;

typedef struct DLKlist {
    struct DLKlist *pre;
    struct DLKlist *next;
    DLKDataType data;
}DLKNode;


DLKNode * DLKlistInit();
void DLKlistDestroy(DLKNode *plist);
void DLKlistPushBack(DLKNode *head, DLKDataType data);
void DLKlistPrint(DLKNode *head);
void DLKlsitPushFount(DLKNode *head, DLKDataType data);
void DLKlistPopBack(DLKNode *head);
void DLKlistPopFront(DLKNode *head);
DLKNode* ListFind(DLKNode * head, DLKDataType data);
void DLKlistInsert(DLKNode * pos, DLKDataType data);
void DLKlistErase(DLKNode * pos);
#endif //DATASTRUCT_DLKLIST_H

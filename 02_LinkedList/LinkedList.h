//
// Created by Jesone on 2026/8/24.
//

#ifndef DATASTRUCT_LINKEDLIST_H
#define DATASTRUCT_LINKEDLIST_H

typedef int LKDataType;
typedef struct LinkedNode {
    LKDataType data;
    struct LinkedNode *next;
}LKNode;

void LKprint(LKNode* phead);
void LKListPushBack(LKNode** phead, LKDataType data);
void LKistPushFront(LKNode** phead, LKDataType data);
void LKlistPopBack(LKNode** phead);
void LKlistPopFront(LKNode** phead);

LKNode* LKlistFind(LKNode* phead, LKDataType data);
//在pos前插入data
void LKlistInsert(LKNode** phead,LKNode* pos,LKDataType data);
//删除pos位置的值
void LKlistErase(LKNode** phead,LKNode* pos);

#endif //DATASTRUCT_LINKEDLIST_H

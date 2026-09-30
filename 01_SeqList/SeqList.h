//
// Created by Jesone on 2026/8/22.
//

#ifndef DATASTRUCT_SEQLIST_H
#define DATASTRUCT_SEQLIST_H

typedef int ElementType;

typedef struct SeqList {
    ElementType* ArrayList;
    int size;//数据个数
    int capacity;//容量
}SL;

void SeqListInit(SL *sl);

void SeqListPushBack(SL *sl, ElementType data);
void SeqListPushFront(SL *sl, ElementType data);
void SeqListPopBack(SL *sl);
void SeqListPopFront(SL *sl);
void SeqListInsert(SL *sl, int index, ElementType data);
void SeqListErase(SL *sl, int index);
void SeqListDestory(SL *sl);
int SeqListFind(SL *sl, ElementType data);
void SeqListModify(SL *sl, int index, ElementType data);
void SeqListPrint(SL *sl);
#endif //DATASTRUCT_SEQLIST_H

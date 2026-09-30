//
// Created by Jesone on 2026/8/22.
//

#include "SeqList.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void SeqListInit(SL *sl) {
    sl->ArrayList = NULL;
    sl->size = 0;
    sl->capacity = 0;
}

static void SeqListCheckCapacity(SL *sl) {
    if (sl->size == sl->capacity) {
        int newCapacity = sl->capacity == 0 ? 4: sl->capacity * 2;
        ElementType* newArray = (ElementType*)realloc(sl->ArrayList, newCapacity * sizeof(ElementType));
        if (newArray == NULL) {
            printf("realloc failed");
            exit(1);
        }
        sl->ArrayList = newArray;
        sl->capacity = sl->capacity * 2;
    }
}

void SeqListPushBack(SL *sl, ElementType data) {
    SeqListCheckCapacity(sl);
    sl->ArrayList[sl->size++] = data;
}
void SeqListPushFront(SL *sl, ElementType data) {
    SeqListCheckCapacity(sl);
    int end = sl->size - 1;
    while (end >=0) {
        sl->ArrayList[end + 1] = sl->ArrayList[end];
        end--;
    }
    sl->ArrayList[0] = data;
    sl->size++;
}
void SeqListPopBack(SL *sl) {
    assert(sl->size > 0);
    sl->size--;
}

void SeqListPopFront(SL *sl) {
    assert(sl->size > 0);
    int start = 1;
    while (start < sl->size) {
        sl->ArrayList[start - 1] = sl->ArrayList[start];
        start++;
    }
    sl->size--;
}

void SeqListInsert(SL *sl, int index, ElementType data) {
    assert(index >= 0 && index < sl->size);
    SeqListCheckCapacity(sl);
    int end = sl->size - 1;
    while (end >= index) {
        sl->ArrayList[end + 1] = sl->ArrayList[end];
        end--;
    }
    sl->ArrayList[index] = data;
    sl->size++;
}

void SeqListErase(SL *sl, int index) {
    assert(index >= 0 && index < sl->size);
    int start = index + 1;
    while (start < sl->size) {
        sl->ArrayList[start - 1] = sl->ArrayList[start];
        start++;
    }
    sl->size--;
}

void SeqListDestory(SL *sl) {
    free(sl->ArrayList);
    sl->ArrayList = NULL;
    sl->size =  sl->capacity = 0;
}

int SeqListFind(SL *sl, ElementType data) {
    for (int i = 0; i < sl->size; i++) {
        if (sl->ArrayList[i] == data) {
            return i;
        }
    }
    return -1;
}

void SeqListModify(SL *sl, int index, ElementType data) {
    assert(index >= 0 && index < sl->size);
    sl->ArrayList[index] = data;
}

void SeqListPrint(SL *sl) {
    for (int i = 0; i < sl->size; i++) {
        printf("%d ", sl->ArrayList[i]);
    }
}



cmake_minimum_required(VERSION 4.2)
project(DataStruct C)

set(CMAKE_C_STANDARD 99)

# 顺序表
add_executable(SeqList 01_SeqList/SeqList.c
        01_SeqList/SeqList.h
        01_SeqList/main.c)


# 链表程序，目标名 02_LinkedList
add_executable(LinkedList
        02_LinkedList/LinkedList.c
        02_LinkedList/LinkedList.h
        02_LinkedList/Main.c
)
add_executable(DloubleLKlist 03_doubleLKlist/DLKlist.c 03_doubleLKlist/DLKlist.h
        03_doubleLKlist/Main.c)

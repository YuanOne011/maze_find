// PointNode.h
#ifndef POINTNODE_H
#define POINTNODE_H

struct Point {
    int row;
    int line;
    int dir;
    Point* next;
};

//#define PointNode Point*
using PointNode = Point*;

// 创建一个新的Point节点
PointNode InitPoint();

// 检查PointNode是否为空
bool IsEmpty(PointNode S);

// 入栈操作
void Push(PointNode& S, int row, int line,int dir);

// 出栈操作
bool Pop(PointNode& S);

#endif

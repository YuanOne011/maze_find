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

// ����һ���µ�Point�ڵ�
PointNode InitPoint();

// ���PointNode�Ƿ�Ϊ��
bool IsEmpty(PointNode S);

// ��ջ����
void Push(PointNode& S, int row, int line,int dir);

// ��ջ����
bool Pop(PointNode& S);

#endif

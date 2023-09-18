// PointNode.cpp
#include "PointNode.h"

PointNode InitPoint() {
    PointNode S = new Point;
    S->next = nullptr;
    return S;
}

bool IsEmpty(PointNode S) {
  return S->next == nullptr;
}

void Push(PointNode& S, int row, int line,int dir) {
    PointNode p = new Point;
    p->row = row;
    p->line = line;
    p->dir = dir;
    p->next = S;  // ���½ڵ��nextָ��ǰջ���ڵ�
    S = p;        // ����ջ��ָ��
}

bool Pop(PointNode& S) {
    if (!IsEmpty(S)) {
        PointNode p = S;
        S = S->next;
        delete p;
        return true;
    }
    return false;
}

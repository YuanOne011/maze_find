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
    p->next = S;  // 将新节点的next指向当前栈顶节点
    S = p;        // 更新栈顶指针
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

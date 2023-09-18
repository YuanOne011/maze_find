// maze.h
#ifndef MAZE_H
#define MAZE_H

#include <iostream>

using namespace std;

const int M = 5;
const int N = 5;
const int X = 4;

using Mazemap=int;
// �����ͼ�ṹ��
struct Maze {
    Mazemap maze_map[M][N];
    struct Point* start;
    struct Point* end;
};

// ���ɵ�ͼ
bool InitMaze(Maze& maze);

// Ѱ�ҵ�ͼ�Ŀ�ͨ·��
int FindMaze(const Maze& maze, struct Point** solution, bool visited[M][N]);

//what i need do is to make the int_num to be my want string
/*
see how I solve in MAZE_main.cpp
*/
#endif

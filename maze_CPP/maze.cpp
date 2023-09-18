//maze.cpp
#include "maze.h"
#include "PointNode.h"

//建立迷宫
bool InitMaze(Maze& maze) {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || j == 0 || i == M - 1 || j == N - 1) {
                maze.maze_map[i][j] = 1;
            }
            else {
                int tmp = rand() % X;
                if (tmp == 0) {
                    maze.maze_map[i][j] = 1;
                }
                else {
                    maze.maze_map[i][j] = 0;
                }
            }
        }
    }

    maze.start = InitPoint();
    maze.start->row = 1;
    maze.start->line = 0;
    maze.start->dir = 0;

    maze.end = InitPoint();
    maze.end->row = M - 2;
    maze.end->line = N - 1;
    maze.end->dir = 0;

    maze.maze_map[1][0] = maze.maze_map[M - 2][N - 1] = 0;
    maze.maze_map[1][1] = maze.maze_map[M - 2][N - 2] = 0;

    return true;
}


//单独的数据结构来跟踪迷宫中访问过的单元格
int FindMaze(const Maze& maze, struct Point** solution,bool visited[M][N]) {
    //检查是否为墙或障碍
    auto isValid = [&](int row, int line) {
        return row >= 0 && row < M&& line >= 0 && line < N&& maze.maze_map[row][line] == 0;
    };

    //找到终点为真
    if (maze.start->row == maze.end->row && maze.start->line == maze.end->line) {
        Push(*solution, maze.start->row, maze.start->line, maze.start->dir);
        return 1;
    }

    //定义四个方向：上、右、下、左
    int dr[4] = { -1, 0, 1, 0 };
    int dl[4] = { 0, 1, 0, -1 };

    //0:left;1:right;2:down;3:up
    for (int i = 0; i < 4; ++i) {
        int newR = maze.start->row + dr[i];
        int newL = maze.start->line + dl[i];
        maze.start->dir = i;

        // 如果新位置有效，则移至该位置
        if (isValid(newR, newL) && !visited[newR][newL]) {
            Push(*solution, maze.start->row, maze.start->line,maze.start->dir);
            visited[maze.start->row][maze.start->line] = true; // 标记已经访问

            // 更新迷宫的起始点
            maze.start->row = newR;
            maze.start->line = newL;

            // 从新位置开始递归搜索
            if (FindMaze(maze, solution, visited)) {
                return 1; // 成功
            }

            // 如果递归调用没有找到路径，则回溯
            Pop(*solution);
            visited[newR][newL] = false; // 标记为未访问
        }
    }

    return 0; // 失败
}
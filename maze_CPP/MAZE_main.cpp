//MAZE_main.cpp
#include "maze.h"
#include "PointNode.h"
#include <stack>
#include<vector>

string Dir_path(const PointNode point) {
    vector<string> ans = { "left", "right", "down", "up" };
    return ans[point->dir];
}

int main() {
    Maze maze;
    if (!InitMaze(maze)) {
        cout << "地图生成错误！" << endl;
        return 1;
    }

    struct Point* solution = InitPoint();
    bool visited[M][N] = { {false} };

    cout << "迷宫地图如下：\n**********************************" << endl;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << maze.maze_map[i][j];
        }
        cout << endl;
    }
    /*
    * 
    //关于输出部分，
    //因为栈的先进后出之特性，导致输出结果不直观符合人类理解
    if (FindMaze(maze, &solution, visited)) {
        cout << "Solution path:" << endl;
        while (!IsEmpty(solution)) {
            struct Point* point = solution;
            solution = solution->next;
            cout << "(" << point->row << ", " << point->line << ") ";
            delete point;
        }
        cout << endl;
    }
    else {
        cout << "No path found." << std::endl;
    }
    */
    //所以在 FindMaze 函数中修改输出路径的部分
    if (FindMaze(maze, &solution,visited)) {
        cout << "**********************************" << endl;
        cout << "找到路径，接下来将为您生成：" << endl;
        stack<struct Point*> pathStack; // 使用栈来反向存储路径

        while (!IsEmpty(solution)) {
            struct Point* point = solution;
            solution = solution->next;
            pathStack.push(point); // 将路径节点推入栈中
        }

        while (!pathStack.empty()) {
            struct Point* point = pathStack.top();
            pathStack.pop();
            cout << "(" << point->row << "," << point->line <<","
            /*
                string Dir_path(const PointNode point){
                vector<string> ans={"right","left","down","up"};
                return ans[point->dir];
                }
                指明方向
            }*/ 
                << Dir_path(point)        
                << ") ";
            if (!pathStack.empty())  cout << "->";
            delete point;
        }

        cout << endl;
    }
    else cout << "没有找到路径！";

    //clean up the solution you created
    while (!IsEmpty(solution)) {
        struct Point* point = solution;
        solution = solution->next;
        delete point;
    }

    return 0;
}

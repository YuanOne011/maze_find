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
        cout << "��ͼ���ɴ���" << endl;
        return 1;
    }

    struct Point* solution = InitPoint();
    bool visited[M][N] = { {false} };

    cout << "�Թ���ͼ���£�\n**********************************" << endl;

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
    //����������֣�
    //��Ϊջ���Ƚ����֮���ԣ�������������ֱ�۷����������
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
    //������ FindMaze �������޸����·���Ĳ���
    if (FindMaze(maze, &solution,visited)) {
        cout << "**********************************" << endl;
        cout << "�ҵ�·������������Ϊ�����ɣ�" << endl;
        stack<struct Point*> pathStack; // ʹ��ջ������洢·��

        while (!IsEmpty(solution)) {
            struct Point* point = solution;
            solution = solution->next;
            pathStack.push(point); // ��·���ڵ�����ջ��
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
                ָ������
            }*/ 
                << Dir_path(point)        
                << ") ";
            if (!pathStack.empty())  cout << "->";
            delete point;
        }

        cout << endl;
    }
    else cout << "û���ҵ�·����";

    //clean up the solution you created
    while (!IsEmpty(solution)) {
        struct Point* point = solution;
        solution = solution->next;
        delete point;
    }

    return 0;
}

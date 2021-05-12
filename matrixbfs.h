#include <iostream>
#include <queue>

namespace matrixbfs{

    void bfs(int a[8][8], int start)
    {
        int i = start;
        int visited[7] = { 0 };
        visited[i] = 1;
        cout << i << " " << endl;
        std::queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (int j = 1; j <= 7; j++)
            {
                if (a[front][j] == 1 && visited[j] == 0)
                {
                    cout << j << " ";
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }

    }

	void matrixbfstest()
	{
        int A[8][8] = { 
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0} 
        };
        bfs(A, 1);

	}
}
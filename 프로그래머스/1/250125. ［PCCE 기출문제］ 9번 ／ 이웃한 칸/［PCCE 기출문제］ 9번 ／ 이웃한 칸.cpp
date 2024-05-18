#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    //BFS 이용해서 상하좌우 인접한 같은 칸 개수 탐색하면 됨.
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    queue<pair<int, int>> q;
    q.push(make_pair(h, w));
    string color = board[h][w];
    
    int count = 0;
    while(!q.empty())
    {
        int nx = q.front().second;
        int ny = q.front().first;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nextX = nx + dx[i];
            int nextY = ny + dy[i];
            if(nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board.size())
            {
                if(board[nextY][nextX] == color)
                {
                    count++;
                }
            }
        }
    }
    answer = count;
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int size = board.size();
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(board[i][j] == 1)
            {
                for(int k = 0; k < 8; k++)
                {
                    if(j + dx[k] >= 0 && j + dx[k] < size && i + dy[k] >= 0 && i + dy[k] < size)
                    {
                        if(board[i+dy[k]][j+dx[k]] != 1)
                        {
                            board[i+dy[k]][j+dx[k]] = 2;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(board[i][j] == 0) answer++;
        }
    }
    
    
    
    return answer;
}
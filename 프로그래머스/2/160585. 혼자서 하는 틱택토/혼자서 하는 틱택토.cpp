#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    
    // 규칙을 어겼을 경우
    // O >= x + 2 / O < X -> 공격 순서를 틀려서 생기는 경우
    // O 빙고가 완성됐을 때, X가 O와 갯수가 같은 경우
    // X 빙고가 완성됐을 때, O 갯수가 X 보다 많은 경우
    // 둘 다 빙고일 경우
    
    int O = 0;
    int X = 0;
    int dy[4] = {0, 1, 1, 1};
    int dx[4] = {1, 0, 1, -1};
    bool Obinggo = false;
    bool Xbinggo = false;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 'O')
            {
                O++;
                if(!Obinggo)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        int count = 1;
                        while(ny < 3 && nx < 3 && nx >= 0)
                        {
                            if(board[ny][nx] == 'O')
                            {
                                ny += dy[k];
                                nx += dx[k];
                                count++;
                            }
                            else break;
                        }
                        if(count == 3) Obinggo = true;
                    }
                }
            }
            else if(board[i][j] == 'X')
            {
                X++;
                if(!Xbinggo)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        int count = 1;
                        while(ny < 3 && nx < 3 && nx >= 0)
                        {
                            if(board[ny][nx] == 'X')
                            {
                                ny += dy[k];
                                nx += dx[k];
                                count++;
                            }
                            else break;
                        }
                        if(count == 3) Xbinggo = true;
                    }
                }
            }
        }
    }
    // 빙고 탐색 방법 -> 빙고판의 좌측 상단부터 우측 하단으로 순차적으로 이동하며 탐색함
    // O나 X가 탐색된 위치에서 우측, 하단, 우측하단, 좌측하단을 탐색함
    // (좌측 상단부터 탐색하므로 좌측과 상단, 상단 대각선의 정보는 필요가 없음)
    // 우측, 하단, 우측하단, 좌측하단 중 같은 모양이 발견된다면 발견한 방향으로 한칸씩 전진하면서 검사
    // 연속된 세칸이 같을 경우 빙고
    
    if(O < X)
    {
        return 0;
    }
    if(O >= X + 2)
    {
        return 0;
    }
    if(Obinggo && Xbinggo) // 둘다 빙고일 경우
    {
        return 0;
    }
    if(Obinggo) // O가 빙고일 경우
    {
        if(O > X) return 1;
        else return 0;
    }
    if(Xbinggo)
    {
        if(O == X) return 1;
        else return 0;
    }
    return 1;
}
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};//북동남서(시계 방향)

int solution(vector<string> board)
{
    int n = board.size(), m = board[0].size();
    int vis[100][100]; memset(vis,-1,sizeof(vis));// 방문배열 -1 로 초기화
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(board[i][j] == 'R') q.push({i,j});// 시작지점 큐에 추가
    vis[q.front().first][q.front().second] = 0;// 시작지점 방문 체크(이동 횟수)
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int dir=0;dir<4;dir++)
        {
            int nx = cur.first, ny = cur.second;
            while (1)
            {
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;//벽을 만나면
                if (board[nx][ny] == 'D') break;// 장애물이면
                nx += dx[dir];// 한칸씩
                ny += dy[dir];// 전진
            }
            nx -= dx[dir];// 벽 또는 장애물일때까지 전진했기 때문에
            ny -= dy[dir];// 바로 이전 좌표에 멈추어야 한다.
            if (board[nx][ny] == 'G') return (vis[cur.first][cur.second] + 1);// 조건에 만족하면
            if (vis[nx][ny]>=0) continue;// 방문한 적 있다면
            vis[nx][ny] = vis[cur.first][cur.second] + 1;//방문체크(이전 방문값 + 1)
            q.push({nx,ny});
        }
    }
    return (-1);//탈출을 못하는 경우
}
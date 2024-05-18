#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<string> maps) {
    int answer = 0;
    
    // 레버까지 최단거리로 이동한 후, 레버부터 출구까지 최단거리로 이동하면 최소시간
    // BFS 사용해서 S -> L 이동, L -> E 이동 시키는 동안 시간 구하면 됨.
    pair<int, int> s = make_pair(-1, -1);
    
    // 맵, 방문 기록 배열 생성
    vector<vector<int>> isV(maps.size(), vector<int>(maps[0].size(), 0));
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].length(); j++)
        {
            if(maps[i][j] == 'S')
            {
                s = make_pair(i, j);
                break;
            }
        }
        if(s.first != -1 && s.second != -1) break;
    }    
    
    queue<pair<int, int>> q;
    q.push(make_pair(s.first, s.second));
    //isV[s.first][s.second] = 1;
    
    bool lever = false;
    
    while(!q.empty())
    {
        int nx = q.front().second;
        int ny = q.front().first;

        q.pop();
        
        if(lever && maps[ny][nx] == 'E')
        {
            return isV[ny][nx];
        }
        
        if(!lever && maps[ny][nx] == 'L')
        {
            lever = true;
            q = queue<pair<int, int>>();
            int time = isV[ny][nx];
            fill(isV.begin(), isV.end(), vector(isV[0].size(), 0));
            isV[ny][nx] = time;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nextX = nx + dx[i];
            int nextY = ny + dy[i];
            
            //좌표 범위 확인
            if(nextX >= 0 && nextX < maps[0].size() && nextY >= 0 && nextY < maps.size())
            {
                if(maps[nextY][nextX] != 'X' && isV[nextY][nextX] == 0) // 길이고 방문한적 없을 경우
                {
                    isV[nextY][nextX] = isV[ny][nx] + 1;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }
    
    return -1;
}
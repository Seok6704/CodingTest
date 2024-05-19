#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
    
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    // BFS로 모든 섬과 각 섬의 식량 양 탐색 후 기록
    vector<vector<bool>> isV(maps.size(), vector<bool>(maps[0].size(), false)); // 방문 배열
    queue<pair<int, int>> q;
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[0].size(); j++)
        {
            if(maps[i][j] != 'X' && !isV[i][j])
            {
                //BFS 진행
                q.push(make_pair(i, j));
                isV[i][j] = true;
                
                int day = maps[i][j] - '0'; //머무를 수 있는 시간
                while(!q.empty())
                {
                    int nx = q.front().second;
                    int ny = q.front().first;
                    q.pop();
                    
                    //상하좌우 탐색
                    for(int k = 0; k < 4; k++)
                    {
                        int nextX = nx + dx[k];
                        int nextY = ny + dy[k];
                        
                        //범위를 벗어나지 않았을 경우
                        if(nextX >= 0 && nextX < maps[0].size() && nextY >= 0 && nextY < maps.size())
                        {
                            if(maps[nextY][nextX] != 'X' && !isV[nextY][nextX]) // 방문한적 없을 경우
                            {
                                q.push(make_pair(nextY, nextX));
                                isV[nextY][nextX] = true;
                                day += maps[nextY][nextX] - '0';
                            }
                        }
                    }
                }
                answer.push_back(day);
            }
        }
    }
    
    if(answer.empty()) answer.push_back(-1); // 지낼 수 있는 무인도가 없는 경우
    else
    {
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}
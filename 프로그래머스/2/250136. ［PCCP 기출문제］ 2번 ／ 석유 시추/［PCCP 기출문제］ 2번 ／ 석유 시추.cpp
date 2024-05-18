#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<vector<int>> land;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int y, int x, int num)
{
    int count = 0; // 석유 덩어리 크기
    queue<pair<int, int>> q;
    q.push(make_pair(y, x)); // 시작점 삽입
    
    while(!q.empty()) // 탐색할 것이 남지 않을 때 까지
    {
        int ny = q.front().first; // 현재 y 좌표
        int nx = q.front().second; // 현재 x 좌표
        q.pop(); // q 삭제
        
        if(land[ny][nx] != 1) continue; // 석유칸이 아니거나, 이미 체크한 땅일 경우
        
        land[ny][nx] = num; // 현재 석유 덩어리 넘버링
        count++; //현재 덩어리 크기 증가
        
        for(int i = 0; i < 4; i++) // 현재 칸의 상하좌우 탐색
        {
            int nextY = ny + dy[i]; // 다음 Y 좌표
            int nextX = nx + dx[i]; // 다음 X 좌표
            // X 좌표 최대, 최소값을 벗어나지 않고, Y 좌표 최대, 최소값을 벗어나지 않아야함
            if(nextX >= 0 && nextX < land[0].size() && nextY >= 0 && nextY < land.size())
            {
                if(land[nextY][nextX] == 1) // 방문하지 않은 석유칸일 경우
                {
                    q.push(make_pair(nextY, nextX)); // q 삽입
                }
            }
        }
    }
    
    return count;
}

int solution(vector<vector<int>> lands) {
    int answer = 0;
    
    // 각 석유 덩어리들에 넘버링을 한 후, 시추기가 넘버링을 지나가면 해당 넘버 석유 덩어리 갯수만큼 증가시킴
    // 각 석유 덩어리는 BFS를 이용해서 넘버링 하면 됨
    // 시추관을 1열부터 마지막 열까지 모두 투입 시키고 가장 수가 높은 값을 리턴시키면 끝
    
    map<int, int> oilSize; // 석유 덩어리 별 크기 저장용 맵
    
    land = lands;
    
    // // 석유 덩어리 방문 배열 초기화
    // for(int i = 0; i < isV.size(); i++)
    // {
    //     isV[i].resize(land[0].size(), false);
    // }
    // 석유가 있는 땅을 만나면 넘버링을 새로하는데 방문 배열이 필요한가? 방문한적 없을 경우 1일거고 방문한적 있을 경우 1이 아닌 다른 수일 것임
    
    // 석유 덩어리 넘버링
    int num = 2; // 석유가 있는 땅의 값이 1이므로 넘버링을 1부터 할 수 없음
    
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[i].size(); j++)
        {
            if(land[i][j] == 1) // 석유가 있고, 방문한적 없을 경우
            {
                int size = BFS(i, j, num); // BFS 실행 y, x, 넘버
                oilSize.insert(make_pair(num, size)); // 현재 덩어리 번호와 크기 삽입
                num++;
            }
        }
    }
    vector<bool> isV; // 석유 덩어리 방문 배열
    isV.resize(num, false);
    // 넘버링 완료
    
    // 시추기 삽입 도중, 이미 만난 덩어리를 다시 만날 경우 카운트 하면 안됨
    // 덩어리 방문 배열 생성 필요
    
    int max = -1;
    for(int i = 0; i < land[0].size(); i++) // 시추기 수직으로 삽입
    {
        int count = 0;
        fill(isV.begin(), isV.end(), false); // 방문 배열 초기화
        for(int j = 0; j < land.size(); j++)
        {
            if(land[j][i] != 0 && !isV[land[j][i]]) // 만난적 없는 석유 덩어리를 만날 경우
            {
                count += oilSize[land[j][i]];
                isV[land[j][i]] = true;
            }
        }
        if(count > max) max = count;
    }
    answer = max;
    
    return answer;
}
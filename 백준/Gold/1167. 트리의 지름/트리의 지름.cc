#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<pair<int, int>>> n;
static vector<bool> isV;
static vector<int> tDis;
void BFS(int s);

int main()
{
    int v;
    cin >> v;

    n.resize(v + 1);
    isV.resize(v + 1, false);
    tDis.resize(v + 1, 0);

    //입력이 정점 - 거리 - 도착점 순서로 입력됨 -1 입력받으면 다음 정점 정보로 이동
    // -1 입력 될 때 까지 반복해서 입력받기
    // 거리 정보를 담은채로 각 정점 경로 정보 만들기
    // BFS 사용해서 가장 거리 가중치가 큰 값 리턴
    // 양방향 연결이라 두 번씩 호출되므로 한번만 담아둬도 됨
    // 모든 정점을 시작지점으로 했더니 시간초과 발생

    for(int i = 0; i < v; i++)
    {
        int s;
        vector<int> tmp;
        while(true)
        {
            int a;
            cin >> a;
            if(a == -1) break;
            tmp.push_back(a);
        }
        for(int j = 1; j < tmp.size() - 1; j += 2)
        {
            n[tmp[0]].push_back(make_pair(tmp[j], tmp[j + 1]));
        }
    }

    BFS(1);

    int max = 1;

    for(int i = 1; i < tDis.size(); i++)
    {
        if(tDis[i] > tDis[max]) max = i;
    }

    fill(isV.begin(), isV.end(), false);
    fill(tDis.begin(), tDis.end(), 0);
    
    BFS(max);

    sort(tDis.begin(), tDis.end(), greater<int>());

    cout << tDis[0];
    
}

void BFS(int s)
{
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        if(isV[s]) continue;
        isV[s] = true;
        for(auto j : n[s])
        {
            if(!isV[j.first])
            {
                q.push(j.first);
                tDis[j.first] = tDis[s] + j.second;
            }
        }
    }
}
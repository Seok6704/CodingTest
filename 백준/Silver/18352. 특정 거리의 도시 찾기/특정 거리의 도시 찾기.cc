#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> r;
static vector<int> result;
static vector<bool> isV;
static int n, m, k, x;
void DFS(int s, int c);

int main()
{
    // 가중치 1
    // 깊이 우선 완전 탐색 DFS 사용
    cin >> n >> m >> k >> x;

    r.resize(n + 1);
    isV.resize(n + 1, false);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        r[a].push_back(b);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(x, 0));
    while(!q.empty())
    {
        int s = q.front().first;
        int c = q.front().second;
        q.pop();

        if(isV[s]) continue;

        isV[s] = true;

        if(c == k) result.push_back(s);
        else if(c > k) continue;
        
        c += 1;
        for(int i = 0; i < r[s].size(); i++)
        {
            q.push(make_pair(r[s][i], c));
        }
        
    }

    if(result.empty()) cout << -1 << "\n";
    else
    {
        sort(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++)
        {
            cout << result[i] << "\n";
        }
    }
}
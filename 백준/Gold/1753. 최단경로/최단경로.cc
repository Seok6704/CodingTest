#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

void Dik(int K);

static vector<vector<pair<int,int>>> A;
static vector<bool> visited;
static vector<int> dis;

int main()
{
    int V, E;
    cin >> V >> E;

    int K;
    cin >> K;

    A.resize(V + 1);
    visited.resize(V + 1, false);
    dis.resize(V + 1, INF);

    for(int i = 1; i <= E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        A[u].push_back(make_pair(v, w));
    }

    Dik(K);

    for(int i = 1; i <= V; i++)
    {
        if(visited[i])
            cout << dis[i] << "\n";
        else
            cout << "INF" << "\n";
    }

}

void Dik(int K)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[K] = 0;
    q.push(make_pair(0, K));

    while(!q.empty())
    {
        pair<int, int> current = q.top();
        q.pop();
        int now = current.second;
        if(visited[now]) continue;

        visited[now] = true;

        for(int i = 0; i < A[now].size(); i++)
        {
            int next = A[now][i].first;
            int ndis = A[now][i].second;

            if(dis[next] > dis[now] + ndis)
            {
                dis[next] = dis[now] + ndis;
                q.push(make_pair(dis[next], next));
            }
        }
        
    }
}
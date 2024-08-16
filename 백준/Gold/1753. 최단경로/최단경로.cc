#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

#define INF 1234567890

int main()
{
    int V, E;
    cin >> V >> E;

    int K;
    cin >> K;

    vector<vector<pair<int, int>>> Node;
    vector<int> W;
    vector<bool> Visit;
    Visit.resize(V + 1, false);
    W.resize(V + 1, INF);
    Node.resize(V + 1);

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        Node[u].push_back(make_pair(v, w));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, K));
    W[K] = 0;

    while(!q.empty())
    {
        int n = q.top().second; // 다음 노드
        int w = q.top().first; // 다음 노드까지의 가중치
        q.pop();

        if(Visit[n]) continue;
        Visit[n] = true;

        for(int i = 0; i < Node[n].size(); i++)
        {
            // 다음 노드에서 이동할 목적지 중 현재까지의 가중치가 더 가벼울 경우
            if(W[Node[n][i].first] > W[n] + Node[n][i].second)
            {
                W[Node[n][i].first] = W[n] + Node[n][i].second;
                q.push(make_pair(W[Node[n][i].first], Node[n][i].first));
            }
        }
    }

    for(int i = 1; i <= V; i++)
    {
        if(Visit[i]) cout << W[i] << "\n";
        else
        {
            cout << "INF" << "\n";
        }
    }
}
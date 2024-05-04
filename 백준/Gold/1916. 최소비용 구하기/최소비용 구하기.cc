#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int main()
{
    int N, M;
    cin >> N;
    cin >> M;

    vector<vector<pair<int, int>>> bus;
    vector<bool> visited;
    vector<int> money;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    bus.resize(N + 1);
    visited.resize(N + 1, false);
    money.resize(N + 1, INF);

    for(int i = 1; i <= M; i++)
    {
        int s, e, m;
        cin >> s >> e >> m;

        bus[s].push_back(make_pair(e, m));
    }

    int start, end;
    cin >> start >> end;

    pq.push(make_pair(0, start));
    money[start] = pq.top().first;

    while(!pq.empty())
    {
        int now = pq.top().second;

        pq.pop();

        if(!visited[now])
        {
            visited[now] = true;

            for(int i = 0; i < bus[now].size(); i++)
            {
                int next = bus[now][i].first;
                if(money[next] > money[now] + bus[now][i].second)
                {
                    money[next] = money[now] + bus[now][i].second;
                }

                pq.push(make_pair(money[next], bus[now][i].first));
            }
        }
        
    }

    cout << money[end];


}
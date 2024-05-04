#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;


typedef tuple<int, int, int> edge;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<edge> city;
    vector<long> dis;

    dis.resize(N + 1, LONG_MAX);

    for(int i = 1; i <= M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;

        city.push_back(make_tuple(s, e, t));
    }

    dis[1] = 0;

    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            edge medge = city[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);

            if(dis[start] != LONG_MAX && dis[end] > dis[start] + time)
            {
                dis[end] = dis[start] + time;
            }
        }
    }

    bool cycle = false;
    for(int j = 0; j < M; j++)
    {
        edge medge = city[j];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);

        if(dis[start] != LONG_MAX && dis[end] > dis[start] + time)
        {
            cycle = true;
            break;
        }
    }

    if(!cycle)
    {
        for(int i = 2; i <= N; i++)
        {
            if(dis[i] == LONG_MAX) cout << -1 << "\n";
            else cout << dis[i] << "\n";
        }
    }
    else cout << -1 << "\n";

}
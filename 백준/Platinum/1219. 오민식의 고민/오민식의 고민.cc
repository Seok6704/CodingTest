#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;
typedef tuple<int, int, int> t;

int main()
{
    // 교통수단에 방향이 있고 돈이 음수가 가능하며 여러번 이용 가능 = 벨만 포드

    int N, S, E, M;
    cin >> N >> S >> E >> M;

    vector<t> city;
    vector<long> money;
    vector<int> maxM;
    money.resize(N, LONG_MIN);
    maxM.resize(N, 0);

    for(int i = 0; i < M; i++)
    {
        int s, e, m;
        cin >> s >> e >> m;
        city.push_back(make_tuple(s, e, m));
    }

    for(int i = 0; i < N; i++)
    {
        cin >> maxM[i];
    }

    money[S] = maxM[S];
    for(int i = 0; i <= N + 50; i++)
    {
        for(int j = 0; j < city.size(); j++)
        {
            int s = get<0>(city[j]);
            int e = get<1>(city[j]);
            int m = get<2>(city[j]);
            int pm = maxM[e];

            if(money[s] == LONG_MIN) continue;
            else if(money[s] == LONG_MAX) money[e] = LONG_MAX;
            else if(money[e] < money[s] + pm - m)
            {
                money[e] = money[s] + pm - m;
                if(i >= N - 1) money[e] = LONG_MAX;
            }
        }
    }

    if(money[E] == LONG_MIN) cout << "gg" << "\n";
    else if(money[E] == LONG_MAX) cout << "Gee" << "\n";
    else cout << money[E] << "\n";

}
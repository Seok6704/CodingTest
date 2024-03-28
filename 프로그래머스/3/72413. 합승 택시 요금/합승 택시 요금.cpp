#include <string>
#include <vector>

using namespace std;

#define INF 40000000

int Dist[200][200]; // 최대 지점 갯수

void floyd(int n)
{
    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(Dist[i][k] + Dist[k][j] < Dist[i][j])
                {
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i == j)
                Dist[i][j] = 0;
            else
                Dist[i][j] = INF;
        }
    }
    
    for(auto edge : fares)
    {
        Dist[edge[0] - 1][edge[1] - 1] = edge[2];
        Dist[edge[1] - 1][edge[0] - 1] = edge[2];
    }
    
    floyd(n);
    
    --s;
    --a;
    --b;
    int answer = INF;
    for(int i = 0; i < n; ++i)
    {
        answer = min(answer, Dist[s][i] + Dist[i][a] + Dist[i][b]);
    }
    
    return answer;
}
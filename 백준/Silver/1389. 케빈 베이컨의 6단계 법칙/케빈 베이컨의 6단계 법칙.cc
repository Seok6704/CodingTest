#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 한 정점에서 모든 다른 정점까지의 최소 거리를 합한게 케빈 베이컨의 수 -> 플로이드 워샬
    // 친구 관계는 양방향

    int N, M;
    cin >> N >> M;

    vector<vector<int>> K;
    K.resize(N + 1);
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            if(i != j) K[i].push_back(5000);
            else K[i].push_back(0);
        }
    }

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        K[a][b] = 1;
        K[b][a] = 1;
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            for(int k = 1; k <= N; k++)
            {
                if(K[j][k] > K[j][i] + K[k][i]) K[j][k] = K[j][i] + K[i][k];
            }
        }
    }

    vector<int> result;
    result.resize(N + 1);
    for(int i = 1; i <= N; i++)
    {
        int sum = 0;
        for(int j = 1; j <= N; j++)
        {
            sum += K[i][j];
        }
        result[i] = sum;
    }

    int min = 5000;
    int answer = 0;
    for(int i = 1; i < result.size(); i++)
    {
        if(result[i] < min)
        {
            min = result[i];
            answer = i;
        }
    }
    cout << answer;
}
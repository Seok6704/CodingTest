#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 가중치 X 길이가 양수 -> 가는 길이 있다?
    // 모든 종류 그래프 탐색 사용 가능 -> 각 경로에서 모든 경우를 봐야하니 플로이드 위샬이 적합할듯함

    int N;
    cin >> N;

    vector<vector<int>> n;
    n.resize(N + 1);

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            n[i].push_back(0);
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            if(a == 1) n[i][j] = 1;
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            for(int k = 1; k <= N; k++)
            {
                if(n[j][i] == 1 && n[i][k] == 1)
                {
                    n[j][k] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << n[i][j] << " ";
        }
        cout << "\n";
    }
}
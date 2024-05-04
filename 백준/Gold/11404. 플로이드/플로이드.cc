#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    // 모든 도시의 최소 비용을 구해야 하므로 플로이드 워샬 알고리즘 사용

    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> money;
    money.resize(n + 1);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == j) money[i].push_back(0);
            else money[i].push_back(INT_MAX / 2);
        }
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(money[a][b] > c) money[a][b] = c;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(money[i][j] > money[i][k] + money[k][j])
                {
                    money[i][j] = money[i][k] + money[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(money[i][j] != INT_MAX / 2) cout << money[i][j] << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }
}
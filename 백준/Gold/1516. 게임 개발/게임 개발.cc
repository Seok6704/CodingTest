#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> B;
    vector<int> degree;
    vector<int> build;

    B.resize(N + 1);
    degree.resize(N + 1);
    build.resize(N + 1);

    for(int i = 1; i <= N; i++)
    {
        cin >> build[i];
        while(true)
        {
            int temp;
            cin >> temp;
            if(temp == -1) break;
            B[temp].push_back(i);
            degree[i]++;
        }
    }
    queue<int> q;

    for(int i = 1; i <= N; i++)
    {
        if(degree[i] == 0) q.push(i);
    }

    vector<int> result;
    result.resize(N + 1);

    while(!q.empty())
    {
        int n = q.front();
        q.pop();

        for(auto next : B[n])
        {
            degree[next]--;
            result[next] = max(result[next], result[n] + build[n]);
            if(degree[next] == 0) q.push(next);
        }
    }

    for(int i = 1; i <= N; i++)
    {
        cout << result[i] + build[i] << "\n";
    }


}
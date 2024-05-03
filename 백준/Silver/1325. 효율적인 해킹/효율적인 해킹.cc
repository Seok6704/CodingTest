#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> com;
    vector<bool> visited;
    queue<int> q;
    vector<int> answer;
    int num = 0;

    com.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 0; i < M; i++)
    {
        int s, e;
        cin >> e >> s;
        com[s].push_back(e);
    }

    for(int i = 1; i <= N; i++)
    {
        q.push(i);
        visited[i] = true;
        int count = 1;
        while(!q.empty())
        {
            int c = q.front();
            q.pop();

            for(int j = 0; j < com[c].size(); j++)
            {
                if(visited[com[c][j]]) continue;

                visited[com[c][j]] = true;
                count++;

                q.push(com[c][j]);
            }
        }
        if(num < count)
        {
            num = count;
            answer.clear();
            answer.push_back(i);
        }
        else if(num == count)
        {
            answer.push_back(i);
        }
        fill(visited.begin(), visited.end(), false);
    }

    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}
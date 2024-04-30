#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
    int N, M;
    int count = 0;
    vector<vector<int>> miro;
    queue<pair<int, int>> q;
    bool visited[101][101] = {false};

    cin >> N >> M;

    string push;
    
    miro.resize(N);

    for(int i = 0; i < N; ++i)
    {
        cin >> push;
        for(int j = 0; j < M; ++j)
        {
            miro[i].push_back(push[j] - '0');
        }
    }

    q.push(make_pair(0, 0));
    
    while(!q.empty())
    {
        visited[q.front().first][q.front().second] = true;
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();

        for(int k = 0; k < 4; ++k)
        {
            int x = tx + dx[k];
            int y = ty + dy[k];
            if(x >= 0 && x < M && y >= 0 && y < N && miro[y][x] != 0 && !visited[y][x])
            {
                miro[y][x] = miro[ty][tx] + 1;
                visited[y][x] = true;
                q.push(make_pair(y, x));
            }
        }
    }
    cout << miro[N-1][M-1];

    return 0;
}
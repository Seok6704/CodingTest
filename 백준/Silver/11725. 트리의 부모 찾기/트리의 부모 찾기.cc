#include <iostream>
#include <vector>

using namespace std;
void DFS(int s);
static vector<vector<int>> t;
static vector<bool> isV;
static vector<int> answer;

int main()
{
    int N;
    cin >> N;

    t.resize(N + 1);
    isV.resize(N + 1, false);
    answer.resize(N + 1);

    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        t[a].push_back(b);
        t[b].push_back(a);
    }

    DFS(1);
    
    for(int i = 2; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }
}

void DFS(int s)
{
    if(isV[s]) return;
    isV[s] = true;

    for(int i = 0; i < t[s].size(); i++)
    {
        if(!isV[t[s][i]])
        {
            answer[t[s][i]] = s;
            DFS(t[s][i]);
        }
    }
}
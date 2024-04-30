#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> f;
static vector<bool> isF;
void DFS(int s, int d);
static bool clear;


int main()
{
    int n, m;
    cin >> n >> m;

    f.resize(n);
    isF.resize(n, false);

    for(int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        f[s].push_back(e);
        f[e].push_back(s);
    }
    clear = false;

    for(int i = 0; i < f.size(); i++)
    {
        if(!isF[i])
        {
            DFS(i, 1);
        }
    }

    if(clear) cout << 1;
    else cout << 0;
}

void DFS(int s, int d)
{
    if(d == 5 || clear)
    {
        clear = true;
        return;
    }
    isF[s] = true;

    for(int i : f[s])
    {
        if(!isF[i]) DFS(i, d + 1);
    }
    isF[s] = false;
}
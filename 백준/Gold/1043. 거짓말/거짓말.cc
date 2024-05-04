#include <iostream>
#include <vector>

using namespace std;

static vector<int> truth;
static vector<int> knowTruth;
void Union(int a, int b);
int Find(int a);

int main()
{
    int n, m;
    cin >> n >> m;

    int tn;
    cin >> tn;

    vector<vector<int>> party;
    party.resize(m);

    for(int i = 0; i < tn; i++)
    {
        int a;
        cin >> a;
        knowTruth.push_back(a);
    }

    for(int i = 0; i <= n; i++)
    {
        truth.push_back(i);
    }

    for(int i = 0; i < m; i++)
    {
        int c, s;
        cin >> c;
        
        for(int j = 0; j < c; j++)
        {
            int b;
            cin >> b;
            party[i].push_back(b);
        }
    }

    for(int i = 0; i < m; i++)
    {
        int s = party[i][0];
        for(int j = 1; j < party[i].size(); j++)
        {
            Union(s, party[i][j]);
        }
    }

    int count = 0;
    for(int i = 0; i < m; i++)
    {
        bool isT = false;
        int now = party[i][0];
        for(int j = 0; j < tn; j++)
        {
            if(Find(now) == Find(knowTruth[j]))
            {
                isT = true;
                break;
            }
        }
        if(!isT) count++;
    }

    cout << count << "\n";
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a != b) truth[b] = a;
}

int Find(int a)
{
    if(truth[a] == a) return a;
    else return truth[a] = Find(truth[a]);
}
#include <iostream>
#include <vector>

using namespace std;

static vector<int> U;
void Union(int a, int b);
int Find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
    {
        U.push_back(i);
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 0)
        {
            Union(b, c);
        }
        else
        {
            int rb = Find(b);
            int rc = Find(c);
            if(rb == rc) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    
    if(a != b) U[b] = a;
}

int Find(int a)
{
    if(a == U[a])
    {
        return a;
    }
    else
    {
        return U[a] = Find(U[a]);
    }
}
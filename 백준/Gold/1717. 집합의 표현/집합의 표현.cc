#include <iostream>
#include <vector>

using namespace std;

void Union(int a, int b);
int Find(int a);
void CheckSame(int a, int b);
static vector<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;


    for(int i = 0; i <= n; i++)
    {
        s.push_back(i);
    }

    for(int i = 0; i < m; i++)
    {
        int c, a, b;
        cin >> c >> a >> b;

        if(c == 0)
        {
            Union(a, b);
        }
        else
        {   
            CheckSame(a, b);
        }
    }

}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a != b) s[b] = a;
}

int Find(int a)
{
    if(a == s[a]) return a;
    else
        return s[a] = Find(s[a]);
}

void CheckSame(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a == b) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
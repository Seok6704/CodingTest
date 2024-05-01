#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<bool> v;
    v.resize(n + 1, true);
    v[0] = false;
    v[1] = false;

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(v[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                v[j] = false;
            }
        }
    }

    for(int i = m; i <= n; i++)
    {
        if(v[i]) cout << i << "\n";
    }

}
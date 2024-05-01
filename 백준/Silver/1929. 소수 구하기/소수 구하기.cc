#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> a;
    a.resize(n + 1, 0);

    for(int i = 2; i <= n; i++)
    {
        a[i] = i;
    }

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(a[i] != 0)
        {
            for(int j = i + i; j <= n; j += i)
            {
                a[j] = 0;
            }
        }
    }

    for(int i = m; i <= n; i++)
    {
        if(a[i] != 0) cout << a[i] << "\n";
    }

}
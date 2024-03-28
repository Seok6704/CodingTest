#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    int num[100001] = {};

    for(int a = 1; a <= n; ++a)
    {
        int k;
        cin >> k;
        num[a] = num[a-1] + k;
    }

    for(int a = 0; a < m; ++a)
    {
        int i, j;
        cin >> i >> j;

        cout << num[j] - num[i-1] << "\n";
    }

    return 0;
}
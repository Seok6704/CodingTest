#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a;
    a.resize(10001, 0);

    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[k]++;
    }

    for(int i = 1; i < a.size(); i++)
    {
        while(a[i] != 0)
        {
            cout << i << "\n";
            a[i]--;
        }
    }
}
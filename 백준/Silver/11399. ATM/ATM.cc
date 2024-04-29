#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> p;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        p.push_back(a);
    }

    sort(p.begin(), p.end());

    int sum = 0;
    for(int i = 0; i < p.size(); i++)
    {
        sum += p[i];
        p[i] = sum;
    }
    sum = 0;
    for(int i = 0; i < p.size(); i++)
    {
        sum += p[i];
    }

    cout << sum;
}
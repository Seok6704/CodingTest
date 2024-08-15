#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 구간합 구하는 문제

    int n;
    cin >> n;

    int MAX;

    vector<int> P;
    P.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> P[i];
    }

    vector<int> L;
    L.resize(n);
    L[0] = P[0];
    MAX = L[0];
    for(int i = 1; i < n; i++)
    {
        L[i] = max(P[i], L[i - 1] + P[i]);
        MAX = max(MAX, L[i]);
    }

    vector<int> R;
    R.resize(n);
    R[n - 1] = P[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        R[i] = max(P[i], R[i + 1] + P[i]);
    }

    for(int i = 1; i < n - 1; i++)
    {
        MAX = max(MAX, R[i + 1] + L[i - 1]);
    }

    cout << MAX;
}
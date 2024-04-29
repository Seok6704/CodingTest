#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> answer;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        answer.push_back(a);
    }

    sort(answer.begin(), answer.end());

    cout << answer[k - 1];
}
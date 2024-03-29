#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        pq.push(a);
    }

    while(!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
}
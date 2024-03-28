#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;

    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a > 0) pq.push(make_pair(a, a));
        else if(a < 0) pq.push(make_pair(a * -1 , a));
        else
        {
            if(pq.empty()) cout << 0 << "\n";
            else
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }
}
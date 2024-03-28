#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, l;

    cin >> n >> l;

    deque<pair<int, int>> deq;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        
        while(deq.size() && deq.back().first > a)
        {
            deq.pop_back();
        }
        deq.push_back(make_pair(a, i));

        if(deq.front().second <= i - l)
        {
            deq.pop_front();
        }
        cout << deq.front().first << ' ';

    }

    


}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    
    cin >> N;

    vector<pair<int, int>> A;

    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(make_pair(a, i));
    }

    sort(A.begin(), A.end());

    int count = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i].second - i > count)
        {
            count = A[i].second - i;
        }
    }

    cout << count + 1;
}
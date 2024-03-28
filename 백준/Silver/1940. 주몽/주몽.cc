#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> num;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }
    //sort(num.begin(), num.end());

    int count = 0;
    for(int i = 0; i < num.size() - 1; i++)
    {
        for(int j = num.size() - 1; j > i; j--)
        {
            if(num[i] + num[j] == m) count++;
        }
    }

    cout << count << "\n";
}
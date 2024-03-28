#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> num;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());

    int count = 0;

    for(int i = 0; i < num.size(); i++)
    {
        int j = 0, k = num.size() - 1;
        int m = num[i];
        while(j < k)
        {
            if(j == i) j++;
            else if(k == i) k--;
            else if(num[j] + num[k] == m)
            {
                count++;
                break;
            }
            else if(num[j] + num[k] < m) j++;
            else if(num[j] + num[k] > m) k--;
        }

    }

    cout << count << "\n";
    
}
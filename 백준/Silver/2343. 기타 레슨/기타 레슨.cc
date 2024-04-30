#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> l;
    int s = 0;
    int e = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        l.push_back(a);
        if(a > s) s = a;
        e += a;
    }

    while(s <= e)
    {   
        int t = 0;
        int mid = (s + e) / 2;
        int bluelay = 0;
        for(int i = 0; i < l.size(); i++)
        {
            if(t + l[i] > mid)
            {
                bluelay++;
                t = l[i];
            }
            else
            {
                t += l[i];
            }
        }
        if(t != 0) bluelay++;
        if(bluelay > m)
        {
            s = mid + 1;
        }
        else e = mid - 1;
    }
    cout << s;
}
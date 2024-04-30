#include <iostream>

using namespace std;

int main()
{
    long n, k;
    cin >> n >> k;

    long s = 1, e = k;
    long ans;
    while(s <= e)
    {
        long mid = (s + e) / 2;
        long c = 0;
        for(int i = 1; i <= n; i++)
        {
            c += min(mid / i, n);
        }
        if(c < k)
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    cout << ans;
}

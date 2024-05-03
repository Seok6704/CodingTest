#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll min, max;
    cin >> min >> max;

    vector<bool> p;
    p.resize(max - min + 1, true);

    for(ll i = 2; i * i <= max; i++)
    {
        ll pow = i * i;
        ll s = min / pow;

        if(min % pow != 0) s++;
        for(ll j = s; pow * j <= max; j++)
        {
            p[j * pow - min] = false;
        }
    }

    ll count = 0;
    for(ll i = 0; i <= max - min; i++)
    {
        if(p[i])
        {
            count++;
        }
    }

    cout << count << "\n";
}
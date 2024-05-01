#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long prime(long long e, long double a);

int main()
{
    long long a, b;
    cin >> a >> b;

    // long long m = 2;

    // while(pow(b, 1.0/m) >= 2)
    // {
    //     m++;
    // }
    // m -= 1;

    // long long result = 0;
    // for(long long i = m; i >= 2; i--)
    // {
    //     result += prime((long long)pow(b, 1.0/i), pow(a, 1.0/i));
    // }

    // cout << result << "\n";

    vector<bool> p;
    p.resize(10000001, true);
    p[0] = false;
    p[1] = false;

    for(long long i = 2; i < 10000001; i++)
    {
        if(p[i])
        {
            for(long long j = i * i; j < 10000001; j += i)
            {
                p[j] = false;
            }
        }
    }

    int count = 0;
    for(long long i = 2; i < 10000001; i++)
    {
        if(p[i])
        {
            long long temp = i;
            while((double)i <= (double)b / (double)temp)
            {
                if((double)i >= (double) a / (double)temp) count++;
                temp = temp * i;
            }
        }
    }

    cout << count << "\n";
}
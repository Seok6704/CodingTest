#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int count = 1;

    for(int i = 1; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j <= n / 2 + 1; j++)
        {
            sum += j;
            if(sum == n)
            {
                count++;
                break;
            }
            else if(sum > n) break;
        }
    }
    cout << count << "\n";
}

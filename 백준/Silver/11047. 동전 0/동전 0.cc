#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 동전의 가치가 오름차순으로 주어짐
    // 동전이 최소로 필요함
    // 가장 목표 값에 근접한 수를 하나 고름
    // 그 수를 목표 값에 최대한 근사할때까지 더함
    // 이후 그 밑에 수를 똑같은 방법을 반복하여 최소 개수를 찾음

    int n, k;
    cin >> n >> k;

    vector<int> c;

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if(a < k) c.push_back(a);
        else if(a == k) result = 1;
    }

    if(result == 1) 
    {
        cout << 1;
        return 0;
    }

    int sum = 0;
    for(int i = c.size() - 1; i >= 0; i--)
    {
        while(sum < k)
        {
            sum += c[i];
            result++;
        }
        if(sum > k)
        {
            result--;
            sum -= c[i];
        }
        else
        {
            cout << result;
            break;
        }
    }
}
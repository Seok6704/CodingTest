#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    // 범위는 int 안으로 들어옴
    // 음수, 0을 제외한 나머지 수를 큰 수부터 차례대로 한 번씩 곱하면 가장 크게 더할 수 있음
    // 1은 곱하지 않고 무조건 더해야 이득임
    // 음수가 두 개 이상일 경우 음수끼리 곱하면 큰 수가 됨
    // 0이 하나 이상 존재할 경우, 마지막 남은 음수랑 곱하면 더 큰 수로 만들 수 있음
    // 입력 받을 때, 음수, 양수, 0 따로 받기

    int n;
    cin >> n;

    priority_queue<int> plus;
    priority_queue<int, vector<int>, greater<int>> minus;
    queue<int> zero;
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a > 1) plus.push(a);
        else if(a < 0) minus.push(a);
        else if(a == 1) result++;
        else zero.push(a);
    }

    while(!plus.empty())
    {
        int a = plus.top();
        plus.pop();

        if(plus.empty())
        {
            result += a;
            break;
        }

        int b = plus.top();
        plus.pop();

        result += a * b;
    }

    while(!minus.empty())
    {
        int a = minus.top();
        minus.pop();

        if(minus.empty())
        {
            if(zero.empty())
            {
                result += a; 
                break;
            }
            else break;
        }

        int b = minus.top();
        minus.pop();

        result += a * b;
    }

    cout << result << "\n";


    
}
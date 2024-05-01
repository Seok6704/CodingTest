#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // 수가 적은 카드팩부터 비교하면서 더해나가면 최선임
    // 단 더해서 새로 나온 카드팩도 다시 정렬해야함
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        q.push(a);
    }

    int sum = 0;
    while(q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        sum += a + b;

        q.push(a + b);
    }

    cout << sum;
}
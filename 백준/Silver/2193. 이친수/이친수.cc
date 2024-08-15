#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 0으로 시작 X
    // 1이 두번 연속 X
    // 이전 이친수가 0으로 끝나면 0과 1을 붙이면 새로운 이친수
    // 이전 이친수가 1로 끝나면 0을 붙이면 새로운 이친수

    int n;
    cin >> n;

    long D[n + 1][2];
    D[1][0] = 0;
    D[1][1] = 1;

    for(int i = 2; i <= n; i++)
    {
        D[i][0] = D[i-1][0] + D[i-1][1];
        D[i][1] = D[i-1][0];
    }

    cout << D[n][0] + D[n][1];
}
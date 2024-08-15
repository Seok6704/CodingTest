#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 2 * n 크기의 직사각형을 채우는 방식의 수
    // 2 * 1 = 1 -> 2 * 1 타일 하나
    // 2 * 2 = 2 -> 2 * 1 타일 두 개, 1 * 2 타일 두 개
    // 2 * 3 = 3
    // 2 * 4 = 5
    // 2 * 5 = 8

    // D[i] = D[i - 1] + D[i - 2];

    int n;
    cin >> n;

    vector<long> D;
    D.resize(n + 1);
    D[1] = 1;
    D[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        D[i] = (D[i - 1] + D[i - 2]) % 10007;
    }

    cout << D[n];
}
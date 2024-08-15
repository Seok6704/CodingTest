#include <iostream>
#include <cmath>

#define Mod 1000000000

using namespace std;

int main()
{
    // 정답 / 10억 값 출력
    // 계단수는 인접한 모든 자리의 차이가 1인 수
    // 한자릿수는 인접한 수가 없으므로 9개의 수 모두 계단수
    // 두자릿수는 1의 계단수의 + 1 or - 1 값을 가진 수가 계단수가 됨
    // 9와 0을 제외한 나머지 수는 2개씩, 9와 0은 1개의 계단수를 가짐
    // 일의 자리가 0일 경우 + 1 갯수 증가, 9일 경우 -1 갯수 증가, 나머지는 +1 -1 둘 다 증가


    int N;
    cin >> N;

    long D[101][11];

    D[1][0] = 0; // 한자릿수 0은 계단수가 아님

    for(int i = 1; i <= 9; i++)
    {
        D[1][i] = 1; // 한자릿수는 모두가 계단수
    }
    // D[i][j] = D[i - 1][j + 1] -> 0일 경우
    // D[i][j] = D[i - 1][j - 1] + D[i - 1][j + 1] -> 1~8일 경우
    // D[i][j] = D[i - 1][j - 1] -> 9일 경우
    for(int i = 2; i <= N; i++)
    {
        D[i][0] = D[i - 1][1] % Mod;
        D[i][9] = D[i - 1][8] % Mod;
        for(int j = 1; j <= 8; j++)
        {
            D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % Mod;
        }
    }

    long sum = 0;
    for(int i = 0; i <= 9; i++)
    {
        sum = (sum + D[N][i]) % Mod;
    }

    cout << sum;
}
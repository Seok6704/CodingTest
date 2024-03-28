#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<long> A;
    vector<long> C;
    A.resize(n + 1, 0);
    C.resize(m, 0);

    long answer = 0;

    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;

        A[i] = A[i-1] + a;
    }

    for(int i = 1; i <= n; i++)
    {
        int remain = A[i] % m;
        if(remain == 0)
        {
            answer++;
        }
        C[remain]++;
    }

    for(int i = 0; i < m; i++)
    {
        if(C[i] >= 2)
        {
            answer += C[i] * (C[i] - 1) / 2;
        }
    }

    cout << answer << "\n";
}
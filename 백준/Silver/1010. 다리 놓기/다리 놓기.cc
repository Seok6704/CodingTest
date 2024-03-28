#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N >> M;

        long long result = 1;
        int r = 1;
        for(int j = (M-N) + 1; j <= M; j++)
        {
            result = result * j;
            result = result / r;
            r++;
        }
        cout << result << "\n";


    }
    return 0;
}
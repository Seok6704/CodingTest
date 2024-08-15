#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 부분 수열 문제
    string A, B;

    cin >> A >> B;

    vector<vector<int>> DP(1001, vector<int>(1001, 0));

    for(int i = 1; i <= A.size(); i++)
    {
        for(int j = 1; j <= B.size(); j++)
        {
            if(A[i - 1] == B[j - 1]) // 두 문자열 값이 같을 경우
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[A.size()][B.size()] << "\n"; // LCS 길이 출력

    int i = A.size();
    int j = B.size();
    vector<char> LCS;
    while(true)
    {
        if(i == 0 || j == 0) break;

        if(A[i - 1] == B[j - 1])
        {
            LCS.push_back(A[i - 1]);
            i--;
            j--;
        }
        else
        {
            if(DP[i - 1][j] > DP[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    for(int i = LCS.size() - 1; i >= 0; i--)
    {
        cout << LCS[i];
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 모든 상담을 다 할 수는 없음
    // 상담 종료 날짜가 퇴사 날짜를 넘어서도 상담을 할 수 없음
    // 최대한 많은 금액을 받게 상담을 하려면 비싸고 짧은 상담 위주로 진행하면 됨

    int N;
    cin >> N;

    vector<pair<int, int>>  T;

    for(int i = 0; i < N; i++)
    {
        int t, p;
        cin >> t >> p;

        T.push_back(make_pair(t, p));
    }

    vector<int> D;
    D.resize(N + 1);

    for(int i = N - 1; i >= 0; i--)
    {
        if(i + T[i].first <= N)
        {
            // 오늘 일해서 얻을 앞으로의 수익과 오늘 일을 안해서 얻을 앞으로의 수익을 비교해서 더 큰걸 선택하면 됨
            D[i] = max(D[i + 1], T[i].second + D[i + T[i].first]);
        }
        else // 퇴사 전에 할 수 없는 일일 경우
        {
            D[i] = D[i + 1];
        }
    }

    sort(D.begin(), D.end(), greater<>());

    cout << D[0] << "\n";
}
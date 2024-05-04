#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 키 비교이므로 순환이 생길 수 없음
    // 답이 여러개인 경우 아무거나 출력 -> 위상 정렬 사용 가능

    int n, m;
    cin >> n >> m;

    vector<vector<int>> s;
    vector<int> c;
    vector<int> sortS;
    s.resize(n + 1);
    c.resize(n + 1, 0);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        s[a].push_back(b);
        c[b]++;
    }

    while(sortS.size() < n)
    {
        int now = find(c.begin() + 1, c.end(), 0) - c.begin();
        c[now] = -1;
        sortS.push_back(now);

        for(int i = 0; i < s[now].size(); i++)
        {
            c[s[now][i]]--;
        }
    }

    for(int i = 0; i < sortS.size(); i++)
    {
        cout << sortS[i] << " ";
    }

}
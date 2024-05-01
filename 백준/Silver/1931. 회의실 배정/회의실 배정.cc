#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
bool compare(p v1, p v2);
static vector<p> t;

int main()
{
    // 회의의 종료 시간이 빠를 수록 많은 회의를 할 수 있음
    // 회의의 종료 시간이 같을 경우, 시작 시간이 빠른 순서로 배치
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;

        t.push_back(make_pair(e, s));
    }

    sort(t.begin(), t.end(), compare);

    int end = t[0].first;
    int count = 1;
    for(int i = 1; i < t.size(); i++)
    {
        if(end <= t[i].second)
        {
            end = t[i].first;
            count++;
        }
    }
    cout << count << "\n";


}

bool compare(p v1, p v2)
{
    if(v1.first == v2.first) return v1.second < v2.second;
    else return v1.first < v2.first;
}
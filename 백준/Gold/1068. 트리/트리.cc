#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    // 부모 노드가 사라지면 그 부모 밑에 있는 모든 자식 노드는 사라짐
    // 노드를 지우고 배열에서 지운 노드를 부모로 가진 노드를 연속으로 지워나갔을 때, 자식이 없는 노드의 수를 세면 됨
    vector<int> t;
    t.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> t[i];    
    }

    int r;
    cin >> r;

    queue<int> q;

    q.push(r);
    t[r] = -2;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        for(int i = 0; i < N; i++)
        {
            if(t[i] == p)
            {
                q.push(i);
                t[i] = -2;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < N; i++)
    {
        bool isP = false;

        for(int j = 0; j < N; j++)
        {
            if(t[j] == i)//자식 존재
            {
                isP = true;
                break;
            }
        }
        if(!isP && t[i] != -2) count++;
    }
    cout << count << "\n";
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    vector<int> cup;
    cup.resize(3);
    cin >> cup[0] >> cup[1] >> cup[2];
    // A = 0 B = 1 C = 2
    // 주기 C -> A C - > B, A -> B, A -> C, B -> A, B -> C (2 2 0 0 1 1)
    // 받기 A, B, B, C, A, C (0 1 1 2 0 2)
    int send[] = {0, 0, 1, 1, 2, 2};
    int recive[] = {1, 2, 0, 2, 0, 1};

    bool isV[201][201];
    bool answer[201];

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    isV[0][0] = true;
    answer[cup[2]] = true;;

    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        int c = cup[2] - (a + b);
        q.pop();

        for(int i = 0; i < 6; i++)
        {
            int next[] = {a, b, c};
            next[recive[i]] += next[send[i]];
            next[send[i]] = 0;

            if(next[recive[i]] > cup[recive[i]])
            {
                next[send[i]] = next[recive[i]] - cup[recive[i]];
                next[recive[i]] = cup[recive[i]];
            }

            if(!isV[next[0]][next[1]])
            {
                isV[next[0]][next[1]] = true;
                q.push(make_pair(next[0], next[1]));
                if(next[0] == 0) answer[next[2]] = true;
            }
        }
    }

    for(int i = 0; i < 201; i++)
    {
        if(answer[i]) cout << i << " ";
    }
}

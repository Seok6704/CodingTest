#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 1000001;
    
    //BFS로 풀 수 있음
    vector<int> isV(1000001, 1000001);
    queue<pair<int, int>> q;
    q.push(make_pair(x, 0));
    int d[3] = {2, 3, n};
    
    while(!q.empty())
    {
        int now = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if(now == y && count <= isV[now])
        {
            isV[now] = count;
            answer = count;
            continue;
        }
        
        count++;
        for(int i = 0; i < 3; i++)
        {
            int next = 0;
            if(i == 2) next = now + d[2];
            else next = now * d[i];
            
            if(next > 1000000) continue;
            
            if(count < isV[next])
            {
                isV[next] = count;
                q.push(make_pair(next, count));
            }
        }
    }
    if(answer == 1000001) return -1;
    
    return answer;
}
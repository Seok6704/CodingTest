#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    // 진행이 가능한 도중에 만나는 가장 큰 값을 무적권으로 제거해 나가면 됨
    // enemy를 순회하면서 마주치는 값을 내림차순으로 저장해둠
    // enemy를 막을 수 없는 라운드를 마주하면 이전에 마주쳤던 값들과 현재 값 중 가장 큰 값을 제거하고 진행함
    // 값을 매번 내림차순 정렬할 순 없으니 우선순위 큐를 사용하여 자동 정렬되도록 함
    priority_queue<int> pq;
    
    for(int i = 0; i < enemy.size(); i++)
    {
        // 막을 수 있을 경우
        if(enemy[i] <= n)
        {
            pq.push(enemy[i]);
            n -= enemy[i];
            answer++;
        }
        else if(k > 0) // 막을 수 없고, 무적권이 남은 경우
        {
            //현재 적의 수가 저장된 최고 값보다 클 경우
            if(pq.empty() || enemy[i] > pq.top())
            {
                k--;
                answer++;
            }
            else
            {
                int temp = pq.top();
                n += temp - enemy[i];
                pq.pop();
                pq.push(enemy[i]);
                answer++;
                k--;
            }
        }
        else
        {
            break;
        }
    }
    
    return answer;
}
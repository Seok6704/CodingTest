#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    // 배열의 길이가 1000000이므로 하나씩 다 검사하면 너무 오래걸림
    // for(int i = 0; i < numbers.size() - 1; i++)
    // {
    //     bool flag = false;
    //     for(int j = i + 1; j < numbers.size(); j++)
    //     {
    //         if(numbers[i] < numbers[j])
    //         {
    //             answer.push_back(numbers[j]);
    //             flag = true;
    //             break;
    //         }
    //     }
    //     if(!flag) answer.push_back(-1);
    // }
    // answer.push_back(-1);
    answer.resize(numbers.size(), -1);
    
    // 오름차순 큐에 수를 순서대로 위치와 함께 삽입
    // 현재 큐의 맨 앞 수보다 큰 수가 나오면 큐 맨 앞의 수가 현재 수보다 클 때 까지 큐 삭제
    // 삭제 한 큐의 위치 값에 현재 수를 삽입
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        if(q.empty())
        {
            q.push(make_pair(numbers[i], i));
        }
        else
        {
            while(q.top().first < numbers[i] && !q.empty())
            {
                answer[q.top().second] = numbers[i];
                q.pop();
            }
            q.push(make_pair(numbers[i], i));
        }
    }
    
    
    return answer;
}
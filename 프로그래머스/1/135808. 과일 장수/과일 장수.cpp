#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    stack<int> s;
    
    sort(score.begin(), score.end(), greater<int>());
    
    for(int i = 0; i < (score.size() / m) * m; ++i)
    {
        s.push(score[i]);
        if(s.size() >= m)
        {
            answer += s.top() * m;
            while(!s.empty())
            {
                s.pop();
            }
        }
    }
    
    return answer;
}
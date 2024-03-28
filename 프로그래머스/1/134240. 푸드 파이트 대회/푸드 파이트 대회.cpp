#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int total = 0;
    queue<int> q;
    stack<int> s;
    
    for(int i = 1; i < food.size(); ++i)
    {
        if(food[i] % 2 != 0) food[i]--;

        if(food[i] != 0)
        {
            int num = i;
            for(int j = 1; j <= food[i] / 2; ++j)
            {
                q.push(num);
                s.push(num);
            }
        }
    }
    
    bool flag = false;
    while(!s.empty())
    {
        if(!q.empty())
        {
            answer += to_string(q.front());
            q.pop();
        }
        else if(q.empty() && !flag)
        {
            answer += "0";
            flag = true;
        }
        else
        {
            answer += to_string(s.top());
            s.pop();
        }
    }
    
    return answer;
}
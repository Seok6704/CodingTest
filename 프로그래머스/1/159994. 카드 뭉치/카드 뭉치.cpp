#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> c1, c2, g;
    
    for(int i = 0; i < cards1.size(); i++)
    {
        c1.push(cards1[i]);
    }
    for(int i = 0; i < cards2.size(); i++)
    {
        c2.push(cards2[i]);
    }
    for(int i = 0; i < goal.size(); i++)
    {
        g.push(goal[i]);
    }
    
    while(!g.empty())
    {
        if(g.front() == c1.front())
        {
            g.pop();
            c1.pop();
        }
        else if(g.front() == c2.front())
        {
            g.pop();
            c2.pop();
        }
        else
        {
            answer = "No";
            break;
        }
    }
    if(answer != "No") answer = "Yes";
    
    return answer;
}
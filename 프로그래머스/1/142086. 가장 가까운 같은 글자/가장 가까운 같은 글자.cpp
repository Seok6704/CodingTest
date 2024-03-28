#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> pos;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(pos.find(s[i]) == pos.end())
        {
            pos[s[i]] = i;
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - pos[s[i]]);
            pos[s[i]] = i;
        }
    }
    
    
    return answer;
}
#include <string>
#include <vector>
#include <map>

using namespace std;




int solution(string s) {
    int answer = 0;
    string result = "";
    string now = "";
    map<string, char> m;
    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';
    
    for(int i = 0; i < s.length(); ++i)
    {
        if(isdigit(s[i])) result += s[i];
        else now += s[i];
        
        if(m.find(now) != m.end())
        {
            result += m[now];
            now = "";
        }
    }
    answer = stoi(result);
    
    return answer;
}
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<char, int> m;
    int cx = 0;
    int cnx = 0;
    char x = s[0];
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == x) cx++;
        else
        {
            cnx++;
        }
        if(cx == cnx)
        {
            answer++;
            cnx = 0;
            cx = 0;
            if(i + 1 != s.length()) x = s[i+1];
        }
    }
    if(cx != 0 || cnx != 0) answer++;
    
    return answer;
}
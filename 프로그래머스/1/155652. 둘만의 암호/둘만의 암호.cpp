#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    int count = 0;
    char n;
    
    for(int i = 0; i < s.length(); i++)
    {
        n = s[i];
        while(count < index)
        {
            n += 1;
            if(n > 'z') n = 'a';
            if(skip.find(n) == string::npos)
            {
                count++;
            }
        }
        count = 0;
        answer += n;
    }
    
    return answer;
}
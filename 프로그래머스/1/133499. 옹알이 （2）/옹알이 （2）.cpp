#include <string>
#include <vector>

using namespace std;

int solution(vector<string> bab) {
    int answer = 0;
    
    for(auto s : bab)
    {
        int flag = 0;
        bool isBab = true;
        
        for(int i = 0; i < s.length(); ++i)
        {
            if(s.substr(i, 3) == "aya" && flag != 1) {flag = 1; i += 2;}
            else if(s.substr(i, 3) == "woo" && flag != 2) {flag = 2; i += 2;}
            else if(s.substr(i, 2) == "ye" && flag != 3) {flag = 3; i += 1;}
            else if(s.substr(i, 2) == "ma" && flag != 4) {flag = 4; i += 1;}
            else
            {
                isBab = false;
                break;
            }
        }
        if(isBab) answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    bool mode = true;
    
    for(int a = 0; a < code.length(); a++)
    {
        if(mode)
        {
            if(code[a] == '1') mode = false;
            else
            {
                if(a % 2 == 0)answer += code[a];
            }
        }
        else
        {
            if(code[a] == '1') mode = true;
            else
            {
                if(a % 2 != 0) answer += code[a];
            }
        }
    }
    if(answer == "") answer = "EMPTY";
    
    return answer;
}
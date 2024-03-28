#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    bool isExist = false;
    
    for(int i = 0; i < dic.size(); i++)
    {
        isExist = false;
        for(int j = 0; j < spell.size(); j++)
        {
            if(dic[i].find(spell[j]) == string::npos)
            {
                isExist = true;
                break;
            }
        }
        if(!isExist) return answer = 1;
    }
    
    return answer = 2;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i = l; i <= r; i++)
    {
        int temp = i;
        bool isFive = true;
        while(temp > 0)
        {
            if(temp % 10 != 5 && temp % 10 != 0)
            {
                isFive = false;
                break;
            }
            else temp /= 10;
        }
        if(isFive) answer.push_back(i);
    }
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}
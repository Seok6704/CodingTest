#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int sIndex = 0, lIndex = 0;
    int sum = 0;
    int s, l;
    int length = 1000000;
    
    while(sIndex <= sequence.size()-1)
    {
        if(sum < k) 
        {
            sum += sequence[lIndex];
            lIndex++;
            if(lIndex > sequence.size()) break;
        }
        else
        {
            if(sum == k)
            {
                if((lIndex-1) - sIndex < length)
                {
                    s = sIndex;
                    l = lIndex-1;
                    length = l - s;
                    if(length == 0) break;
                }
                sum -= sequence[sIndex];
                sIndex++;
            }
            else if(sum > k)
            {
                sum -= sequence[sIndex];
                sIndex++;
            }
        }
    }
    answer.push_back(s);
    answer.push_back(l);
    
    
    return answer;
}
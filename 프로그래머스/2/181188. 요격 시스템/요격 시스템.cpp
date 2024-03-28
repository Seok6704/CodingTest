#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    bool isFirst = true;
    bool isAccept = true;
    vector<vector<int>> result;
    
    sort(targets.begin(), targets.end());
    
    for(int i = 0; i < targets.size(); i++)
    {
        if(isFirst)
        {
            result.push_back(targets[i]);
            isFirst = false;
        }
        else
        {
            for(int j = 0; j < result.size(); j++)
            {
                if(result[j][0] >= targets[i][1] || result[j][1] <= targets[i][0])
                {
                    isAccept = true;
                }
                else 
                {
                    isAccept = false;
                    if(result[j][0] <= targets[i][0] && result[j][1] >= targets[i][1])
                    {
                        result.erase(result.begin() + j);
                        result.push_back(targets[i]);
                    }
                    break;
                }
            }
            if(isAccept) result.push_back(targets[i]);
        }
    }
    answer = result.size();
    
    return answer;
}
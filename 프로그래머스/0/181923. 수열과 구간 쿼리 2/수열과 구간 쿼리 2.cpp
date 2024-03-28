#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i = 0; i < queries.size(); i++)
    {
        answer.push_back(-1);
        for(int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            if(arr[j] > queries[i][2])
            {
                if(answer[i] == -1)
                {
                    answer[i] = arr[j];
                }
                else
                {
                    if(answer[i] > arr[j]) answer[i] = arr[j];
                }
            }
        }
    }

    
    return answer;
}
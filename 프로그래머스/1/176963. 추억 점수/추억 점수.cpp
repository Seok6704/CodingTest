#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int sum = 0;
    
    map<string, int> m;
    
    for(int i = 0; i < name.size(); i++)
    {
        m[name[i]] = yearning[i];
    }
    
    for(int i = 0; i < photo.size(); i++)
    {
        for(int j = 0; j < photo[i].size(); j++)
        {
            if(m[photo[i][j]] != NULL)
            {
                sum += m[photo[i][j]];
            }
        }
        answer.push_back(sum);
        sum = 0;
    }
    
    return answer;
}
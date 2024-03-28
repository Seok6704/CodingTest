#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int rank[] = {6, 6, 5, 4, 3, 2, 1};
    
    int count = 0;
    int crt = 0;
    for(int i = 0; i < lottos.size(); ++i)
    {
        if(lottos[i] == 0) count++;
        if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
        {
            crt++;    
        }
    }
    int up = crt + count;
    int down = crt;
    answer.push_back(rank[up]);
    answer.push_back(rank[down]);
    
    return answer;
}
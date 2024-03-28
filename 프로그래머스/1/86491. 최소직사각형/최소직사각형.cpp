#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> row;
    vector<int> cul;
    
    for(int i = 0; i < sizes.size(); ++i)
    {
        if(sizes[i][0] < sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
        row.push_back(sizes[i][0]);
        cul.push_back(sizes[i][1]);
    }
    
    sort(row.begin(), row.end(), greater<int>());
    sort(cul.begin(), cul.end(), greater<int>());
    
    answer = row.front() * cul.front();
        
    return answer;
}
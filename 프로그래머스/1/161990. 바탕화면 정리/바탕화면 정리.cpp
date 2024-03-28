#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> sx, sy;
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].length(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                sx.push_back(i);
                sy.push_back(j);
            }
        }
    }
    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end());
    
    answer.push_back(sx.front());
    answer.push_back(sy.front());
    answer.push_back(sx.back() + 1);
    answer.push_back(sy.back() + 1);
    
    return answer;
}
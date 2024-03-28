#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int count = 0;
    int total = 0;
    vector<int> energy;
    
    int totalP = accumulate(picks.begin(), picks.end(), 0);
    
    for(int i = 0; i < minerals.size(); i++)
    {
        if(minerals[i] == "diamond")
        {
            total += 100;
            count++;
        }
        else if(minerals[i] == "iron")
        {
            total += 10;
            count++;
        }
        else
        {
            total += 1;
            count++;
        }
        if(count == 5)
        {
            energy.push_back(total);
            count = 0;
            total = 0;
        }
    }
    if(total >= 0) energy.push_back(total);
    
    if(totalP < energy.size())
    {
        energy.erase(energy.begin() + totalP, energy.end());
        sort(energy.begin(), energy.end(), greater<int>());
    }
    else sort(energy.begin(), energy.end(), greater<int>());
    
    for(int i = 0; i < energy.size(); i++)
    {
        int dia = energy[i] / 100;
        int iron = energy[i] % 100 / 10;
        int stone = energy[i] % 100 % 10;
        if(picks[0] > 0)
        {
            answer += dia + iron + stone;
            picks[0]--;
        }
        else if(picks[1] > 0)
        {
            answer += dia * 5 + iron + stone;
            picks[1]--;
        }
        else if(picks[2] > 0)
        {
            answer += dia * 25 + iron * 5 + stone;
            picks[2]--;
        }
        else if(picks[0] <= 0 && picks[1] <= 0 && picks[2] <= 0) break;
    }
    
    return answer;
}
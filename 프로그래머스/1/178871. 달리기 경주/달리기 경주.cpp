#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    string backPlayer;
    int number = 0;
    map<string, int> m;
    
    for(int i = 0; i < players.size(); i++)
    {
        m[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++)
    {
        number = m[callings[i]];
        m[players[number - 1]] += 1;
        m[callings[i]] -= 1;
        
        backPlayer = players[number];
        players[number] = players[number - 1];
        players[number - 1] = backPlayer;
    }
    
    
    return players;
}
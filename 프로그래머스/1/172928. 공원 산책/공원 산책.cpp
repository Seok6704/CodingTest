#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isX(int x, int y, vector<pair<int, int>> xp)
{
    for(int i = 0; i < xp.size(); ++i)
    {
        if(x == xp[i].second && y == xp[i].first)
            return true;
    }
    return false;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<pair<int, int>> xp;
    int sx;
    int sy;
    int dx = 0;
    int dy = 0;
    int tmpX = 0;
    int tmpY = 0;
    bool isbreak;
    
    for(int i = 0; i < park.size(); ++i)
    {
        for(int j = 0; j < park[i].length(); ++j)
        {
            if(park[i][j] == 'S')
            {
                sx = j;
                sy = i;
            }
            else if(park[i][j] == 'X')
            {
                xp.push_back(make_pair(i, j));
            }
        }
    }
    
    for(int i = 0; i < routes.size(); ++i)
    {
        switch (routes[i][0])
        {
            case 'E':
                isbreak = false;
                tmpX = sx;
                dx = routes[i][2] - '0';
                if(sx + dx >= park[0].length()) break;
                else
                {
                    for(int j = 1; j <= dx; ++j)
                    {
                        tmpX++;
                        if(isX(tmpX, sy, xp))
                        {
                            isbreak = true;
                            break;
                        }
                    }
                    if(!isbreak) sx += dx;
                }
                break;
            case 'S':
                isbreak = false;
                tmpY = sy;
                dy = routes[i][2] - '0';
                if(sy + dy >= park.size()) break;
                else
                {
                    for(int j = 1; j <= dy; ++j)
                    {
                        tmpY++;
                        if(isX(sx, tmpY, xp)) 
                        {
                            isbreak = true;
                            break;
                        }
                    }
                    if(!isbreak) sy += dy;
                }
                break;
            case 'W':
                isbreak = false;
                tmpX = sx;
                dx = routes[i][2] - '0';
                if(sx - dx < 0) break;
                else
                {
                    for(int j = 1; j <= dx; ++j)
                    {
                        tmpX--;
                        if(isX(tmpX, sy, xp)) 
                        {
                            isbreak = true;
                            break;
                        }
                    }
                    if(!isbreak) sx -= dx;
                }
                break;
            case 'N':
                isbreak = false;
                tmpY = sy;
                dy = routes[i][2] - '0';
                if(sy - dy < 0) break;
                else
                {
                    for(int j = 1; j <= dy; ++j)
                    {
                        tmpY--;
                        if(isX(sx, tmpY, xp)) 
                        {
                            isbreak = true;
                            break;
                        }
                    }
                    if(!isbreak) sy -= dy;
                }
                break;
        }
    }
    answer.push_back(sy);
    answer.push_back(sx);
    
    return answer;
}
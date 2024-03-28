#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> bg;
    
    int s = find(ingredient.begin(), ingredient.end(), 1) - ingredient.begin();
    if(find(ingredient.begin(), ingredient.end(), 1) == ingredient.end()) return 0;
    
    bg.push(1);
    
    for(int i = s+1; i < ingredient.size(); ++i)
    {
        if(!bg.empty())
        {
            switch (ingredient[i])
            {
                case 1:
                    if(bg.top() == 1 || bg.top() == 2)
                        bg.push(1);
                    if(bg.top() == 3)
                    {
                        int count = 3;
                        while(count != 0)
                        {
                            count--;
                            bg.pop();
                        }
                        answer++;
                    }
                    break;
                case 2:
                    if(bg.top() == 1)
                        bg.push(2);
                    else
                    {
                        while(!bg.empty())
                            bg.pop();
                    }
                    break;
                case 3:
                    if(bg.top() == 2)
                        bg.push(3);
                    else
                    {
                        while(!bg.empty())
                            bg.pop();
                    }
                    break;
            }            
        }
        else
        {
            if(ingredient[i] == 1) bg.push(1);
        }
    }
    
    return answer;
}
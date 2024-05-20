#include <string>
#include <vector>

using namespace std;

int discount[4] = {10, 20, 30, 40}; // 할인율
vector<pair<int, int>> price(7, make_pair(0, 0));
vector<int> answer(2, 0);

void DFS(int count, vector<vector<int>> users, vector<int> emoticons)
{
    if(count == emoticons.size()) // 모든 이모티콘 할인 적용 완료
    {
        int sub = 0;
        int total = 0;
        for(int i = 0; i < users.size(); i++)
        {
            int temp = 0;
            for(int j = 0; j < emoticons.size(); j++)
            {
                if(users[i][0] <= price[j].second) temp += price[j].first; // 이모티콘 구매
            }
            if(temp >= users[i][1]) // 이모티콘 플러스 가입
            {
                sub++;
            }
            else // 총 판매액 추가
            {
                total += temp;
            }
        }
        if(sub > answer[0]) // 현재 최대 가입자 수보다 클 경우
        {
            answer[0] = sub;
            answer[1] = total;
        }
        else if(sub == answer[0] && total > answer[1]) // 가입자수는 같은데 판매액이 더 많을 경우
        {
            answer[1] = total;
        }
    }
    else // 이모티콘 할인 적용이 될 됐을 경우
    {
        for(int i = 0; i < 4; i++)
        {
            price[count].first = (emoticons[count] / 100) * (100 - discount[i]);
            price[count].second = discount[i];
            DFS(count + 1, users, emoticons);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {   
    // 할인율 10, 20, 30, 40, 이모티콘 수 7, 이용자 수 100 = O(4^7 * 100) 약 160만의 시간 복잡도
    // DFS 사용 가능
    // 모든 할인율 경우의 수에서 나오는 이모티콘 플러스 가입자 수와 이모티콘 판매액을 기록
    // 가장 많은 가입자 수와 가장 큰 이모티콘 판매액을 택하면 됨

    DFS(0, users, emoticons);
    
    
    
    
    return answer;
}
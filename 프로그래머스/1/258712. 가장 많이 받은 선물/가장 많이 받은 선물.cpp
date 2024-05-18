#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string s)
{
    bool isA = true;
    vector<string> result;
    string A = "";
    string B = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            isA = false;
            continue;
        }
        
        if(isA)
        {
            A += s[i];
        }
        else
        {
            B += s[i];
        }
    }
    
    result.push_back(A);
    result.push_back(B);
    
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    // 본인이 선물을 줄 경우 선물지수 +1
    // 남에게 선물을 받을 경우 선물지수 -1
    // 누가 선물을 받는지는 필요 없음, 가장 많이 받는 사람의 받은 선물의 수를 리턴
    // 2차원 배열을 이용해서 선물 준사람과 받은 사람으로 기록함
    // 배열의 넘버는 map을 이용해서 friends를 순서대로 넘버로 변환
    int answer = 0;
    
    map<string, int> fnum;
    for(int i = 0; i < friends.size(); i++)
    {
        fnum.insert(make_pair(friends[i], i));
    }
    vector<int> giftP; // 선물 지수
    giftP.resize(friends.size(), 0);
    vector<vector<int>> giftC(friends.size()); // 선물 횟수
    for(int i = 0; i < giftC.size(); i++)
    {
        giftC[i].resize(friends.size(), 0);
    }

    
    for(int i = 0; i < gifts.size(); i++)
    {
        vector<string> now = split(gifts[i]); // -> 분할 연산 필요
        giftC[fnum[now[0]]][fnum[now[1]]]++; // 준사람 -> 받은사람 카운트 1 증가
        giftP[fnum[now[0]]]++; // 준사람 선물지수 증가
        giftP[fnum[now[1]]]--; // 받은사람 선물지수 감소
    }
    
    int max = -1;
    for(int i = 0; i < giftC.size(); i++)
    {
        int count = 0;
        for(int j = 0; j < giftC.size(); j++)
        {
            if(i == j) continue; // 자기 자신
            
            if(giftC[i][j] > giftC[j][i]) // 본인이 준 횟수가 더 많을 경우
            {
                count++;
            }
            else if(giftC[i][j] < giftC[j][i]) // 본인이 받은 횟수가 더 많을 경우
            {
                continue;
            }
            else if(giftC[i][j] == giftC[j][i]) // 주고 받은 횟수가 같은 경우(둘다 0이어도 같음)
            {
                if(giftP[i] > giftP[j]) count++;
                else continue;
            }
        }
        if(count > max) max = count;
    }
    answer = max;
    
    
    return answer;
}
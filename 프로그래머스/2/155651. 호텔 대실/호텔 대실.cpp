#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare
{
    bool operator()(pair<int, int> A, pair<int, int> B)
    {
        if(A.second > B.second) return true;
        else return false;
    }
};

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    // 퇴실시간 기준으로 10분 청소, 퇴실 시간 + 10분이 방 이용이 가능해지는 시간
    // 모든 퇴실 시간에 10분을 더 해두면 계산하기 쉬움 -> 리스트를 한번 더 살펴야 하므로 생략
    // 입실 시간 기준으로 오름차순 정렬한 리스트 생성
    // 계산하기 편하도록 시간 * 60 + 분 의 형태로 수치 변경
    vector<pair<int, int>> bookTime;
    for(int i = 0; i < book_time.size(); i++)
    {
        vector<int> time;
        time.resize(2);
        for(int j = 0; j < 2; j++)
        {
             time[j] = ((book_time[i][j][0] - '0') * 10 + (book_time[i][j][1] - '0')) * 60
                + (book_time[i][j][3] - '0') * 10 + book_time[i][j][4] - '0';
        }
        bookTime.push_back(make_pair(time[0], time[1]));
    }
    sort(bookTime.begin(), bookTime.end());
    // queue에 퇴실시간 기준으로 오름차순 정렬 시켜서 삽입
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    // queue에 삽입하는 순간에 queue 안에 요소가 있을 경우, 입실 시간과 비교해서 작을 경우 삭제
    int room = 0;
    for(int i = 0; i < bookTime.size(); i++)
    {
        if(q.empty())
        {
            q.push(make_pair(bookTime[i].first, bookTime[i].second));
            if(room < q.size()) room = q.size();
        }
        else
        {
            if(q.top().second + 10 <= bookTime[i].first)
            {
                q.pop();
                q.push(make_pair(bookTime[i].first, bookTime[i].second));
            }
            else
            {
                q.push(make_pair(bookTime[i].first, bookTime[i].second));
            }
        }
        if(room < q.size()) room = q.size();
    }
    // 매 삽입 순간마다 queue 크기 기록
    // queue 크기의 최대치가 필요한 객실 수
    
    answer = room;
    
    return answer;
}
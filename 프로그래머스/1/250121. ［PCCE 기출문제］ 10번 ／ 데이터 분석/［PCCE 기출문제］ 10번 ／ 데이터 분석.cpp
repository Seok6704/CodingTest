#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int sortP;

bool compare(vector<int> A, vector<int> B)
{
    if(A[sortP] <= B[sortP]) return true;
    else return false;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> m;
    // val_ext보다 작은 데이터를 뽑고 // sort_by 값을 기준으로 오름차순 정렬
    // 처음부터 모든 값을 sort_by 값을 기준으로 오름차순 정렬 시켜둔 후, 기준 값보다 작은 데이터만 남기면 됨
    // ext 값(code, date, maximum, remain)을 map 형식으로 data의 위치값 기준으로 매핑
    m.insert(make_pair("code", 0));
    m.insert(make_pair("date", 1));
    m.insert(make_pair("maximum", 2));
    m.insert(make_pair("remain", 3));
    
    int extP = m[ext]; // ext 값 위치
    sortP = m[sort_by]; // 정렬 기준 값 위치
    
    sort(data.begin(), data.end(), compare);
    
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i][extP] < val_ext) answer.push_back(data[i]);
    }
    
    
    return answer;
}
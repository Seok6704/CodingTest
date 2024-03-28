#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;
    int i = num_list.size();
    if(num_list.back() > num_list[i-2]) answer.push_back(num_list.back() - num_list[i-2]);
    else answer.push_back(num_list.back()*2);
    
    return answer;
}
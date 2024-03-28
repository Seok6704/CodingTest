#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    q.push(arr[0]);
    
    for(int i = 1; i < arr.size(); i++)
    {
        if(q.back() != arr[i])
        {
            q.push(arr[i]);   
        }
    }
    while(!q.empty())
    {
        int a = q.front();
        answer.push_back(a);
        q.pop();
    }
    

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
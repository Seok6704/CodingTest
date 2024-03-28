#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    
    for(int a = 0; a < arr.size(); a++)
    {
        answer += arr.at(a);
        //if(arr.at(a) == arr.back()) break;
    }
    return answer;
}
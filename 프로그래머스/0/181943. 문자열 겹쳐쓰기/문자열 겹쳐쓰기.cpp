#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    for(int a = 0; a < overwrite_string.length(); a++)
    {
        my_string[a + s] = overwrite_string[a];
    }
    
    answer = my_string;
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int s = section[0];
    int e;
    
    for(int i = 0; i < section.size(); i++)
    {
        e = section[i];
        if(e - s >= m)
        {
            answer++;
            s = e;
            e = 0;
        }
        if(i == section.size() - 1 && e - s < m)
        {
            answer++;
        }
    }
    
    return answer;
}
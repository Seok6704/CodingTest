#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string n;

    cin >> n;

    vector<int> answer;

    for(int i = 0; i < n.length(); i++)
    {
        answer.push_back(n[i] - '0');
    }

    for(int i = 0; i < answer.size(); i++)
    {
        int max = -1;
        int maxp = 0;
        for(int j = i; j < answer.size(); j++)
        {
            if(answer[j] > max)
            {
                max = answer[j];
                maxp = j;
            }
        }
        swap(answer[i], answer[maxp]);
    }
    
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
    }
}
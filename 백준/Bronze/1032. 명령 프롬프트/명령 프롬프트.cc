#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<string> answer;
    
    for(int i = 0; i < n; i++)
    {
        string a;
        cin >> a;

        if(answer.empty()) answer.push_back(a);
        else
        {
            for(int j = 0; j < answer[0].length(); j++)
            {
                if(a[j] != answer[0][j])
                {
                    answer[0].replace(j, 1, "?");
                }
            }
        }
    }

    cout << answer[0];
}
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    stack<int> def;
    def.push(0);
    stack<int> s;
    vector<int> l;
    vector<string> answer;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        l.push_back(a);
    }
    for (int i = n; i > 0; i--)
    {
        s.push(i);
    }

    for(int i = 0; i < l.size(); i++)
    {
        if(def.top() < l[i])
        {
            while(def.top() < l[i])
            {
                def.push(s.top());
                answer.push_back("+");
                s.pop();
            }
            if(def.top() == l[i])
            {
                answer.push_back("-");
                def.pop();
            }
        }
        else if(def.top() > l[i])
        {
            cout << "NO" << "\n";
            answer.clear();
            break;
        }
        else if(def.top() == l[i])
        {
            answer.push_back("-");
            def.pop();
        }
    }

    if(!answer.empty())
    {
        for(int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << "\n";
        }
    }
}
#include <iostream>

using namespace std;

int main()
{
    //숫자 최대 크기는 다섯자리, 식의 길이 최대는 50자리, 99999를 42번 덧셈 가능 약 100000 * 42 = 42만보다 작은 수이므로 int 사용 가능
    //연산자가 나오거나 입력 값의 마지막에 도착하면 수가 끝난것.
    //최소로 만들려면 - 뒤에 나오는 값을 최대한 크게 하면 됨
    //-가 없으면 그냥 다 더하면 최소
    //- 나오기 전까지는 다 더하는게 최선
    //- 출현 이후에는 그냥 뭐가 나오든 다 빼면 됨

    string s;
    cin >> s;

    string num = "";
    bool flag = false;

    int result = 0;
    for(int i = 0; i < s.length(); i++) 
    {
        if(s[i] == '-' & !flag)
        {
            result += stoi(num);
            num = "";
            flag = true;
        }
        else if(s[i] == '-' & flag)
        {
            result -= stoi(num);
            num = "";
        }
        else if(s[i] == '+' && !flag)
        {
            result += stoi(num);
            num = "";
        }
        else if(s[i] == '+' && flag)
        {
            result -= stoi(num);
            num = "";
        }
        else
        {
            num += s[i];
        }
    }
    if(flag) result -= stoi(num);
    else result += stoi(num);

    cout << result << "\n";

}
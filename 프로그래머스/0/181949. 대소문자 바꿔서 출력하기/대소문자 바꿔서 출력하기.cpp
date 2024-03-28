#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(int a = 0; a < str.length(); a++)
    {
        if('a' <= str[a] && 'z' >= str[a])
        {
            str[a] = str[a] - 32;
        }
        else
        {
            str[a] = str[a] + 32;
        }
    }
    
    cout << str;
    
    return 0;
}
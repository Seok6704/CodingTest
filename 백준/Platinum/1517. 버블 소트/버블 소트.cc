#include <iostream>
#include <vector>

using namespace std;

void merge_sort(int s, int e);
static vector<int> a;
static vector<int> temp;
static long swapC;

int main()
{
    int n;
    cin >> n;

    a.resize(n + 1, 0);
    temp.resize(n + 1, 0);
    swapC = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    merge_sort(1, n);

    cout << swapC;
}

void merge_sort(int s, int e)
{
    if(e - s < 1) return;

    int m = s + (e - s) / 2;

    merge_sort(s, m);
    merge_sort(m + 1, e);

    for(int i = s; i <= e; i++)
    {
        temp[i] = a[i];
    }

    int k = s;
    int left = s;
    int right = m + 1;

    while(left <= m && right <= e)
    {
        if(temp[left] > temp[right])
        {
            a[k] = temp[right];
            swapC += right - k;
            k++;
            right++;
        }
        else
        {
            a[k] = temp[left];
            k++;
            left++;
        }
    }

    while(left <= m)
    {
        a[k] = temp[left];
        k++;
        left++;
    }
    while(right <= e)
    {
        a[k] = temp[right];
        k++;
        right++;
    }
}
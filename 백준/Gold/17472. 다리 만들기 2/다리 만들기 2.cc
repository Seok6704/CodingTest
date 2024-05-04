#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;
typedef tuple<int, int, int> t;

static vector<vector<int>> m;
static vector<vector<bool>> isV;
static vector<p> iList; // 섬 정보
static vector<vector<p>> AList; // 모든 섬 정보
static vector<t> T;
static vector<int> U;
void BFS(int y, int x);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
static int N, M, mNum;
void Union(int a, int b);
int Find(int a);
bool compare(t a, t b);

int main()
{
    // 모든 섬을 연결하는 다리 길이의 최솟값이므로 최소 신장 트리 사용
    // 섬을 먼저 찾아야함 BFS 사용
    cin >> N >> M;

    m.resize(N);
    isV.resize(N);

    // N = Y, M = X;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            m[i].push_back(a);
            isV[i].push_back(false);
        }
    }

    mNum = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(!isV[i][j] && m[i][j] == 1)
            {
                BFS(i, j);
                mNum++;
                AList.push_back(iList);
            }
        }
    }

    // for(int i = 0; i < N; i++)
    // {
    //     for(int j = 0; j < M; j++)
    //     {
    //         cout << m[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 0; i < AList.size(); i++)
    {
        vector<p> now = AList[i];

        for(int j = 0; j < now.size(); j++)
        {
            int ny = now[j].first;
            int nx = now[j].second;
            int nowNum = m[ny][nx];

            for(int k = 0; k < 4; k++)
            {
                int tempX = dx[k];
                int tempY = dy[k];
                int length = 0;

                while(nx + tempX >= 0 && nx + tempX < M && ny + tempY >= 0 && ny + tempY < N)
                {
                    if(m[ny + tempY][nx + tempX] == nowNum) break;
                    else if(m[ny + tempY][nx + tempX] != 0)
                    {
                        if(length > 1)
                        {
                            T.push_back(make_tuple(nowNum, m[ny + tempY][nx + tempX], length));
                            // cout << nowNum << " " << m[ny + tempY][nx + tempX] << " " << length << "\n";
                        }
                        break;
                    }
                    else length++;

                    if(tempX < 0) tempX--;
                    else if(tempX > 0) tempX++;
                    else if(tempY < 0) tempY--;
                    else if(tempY > 0) tempY++;
                }
            }
        }
    }


    for(int i = 0; i < mNum; i++)
    {
        U.push_back(i);
    }

    if(T.empty())
    {
        cout << -1 << "\n";
        return 0;
    }

    sort(T.begin(), T.end(), compare);

    int edge = 0;
    int i = 0;
    int result = 0;

    while(edge < mNum - 2)
    {
        int s = get<0>(T[i]);
        int e = get<1>(T[i]);
        int c = get<2>(T[i]);

        if(Find(s) != Find(e))
        {
            Union(s, e);
            edge++;
            result += c;
        }

        i++;
        if(i >= T.size())
        {
            result = -1;
            break;
        }
    }

    cout << result << "\n";
}

void BFS(int y, int x)
{
    queue<p> q;
    q.push(make_pair(y, x));
    iList.clear();
    iList.push_back(make_pair(y, x));

    while(!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        if(isV[ny][nx]) continue;
        isV[ny][nx] = true;
        m[ny][nx] = mNum;

        for(int i = 0; i < 4; i++)
        {
            int nextX = nx + dx[i];
            int nextY = ny + dy[i];
            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N)
            {
                if(!isV[nextY][nextX] && m[nextY][nextX] != 0)
                {
                    q.push(make_pair(nextY, nextX));
                    iList.push_back(make_pair(nextY, nextX));
                }
            }
        }
    }
}

bool compare(t a, t b)
{
    if(get<2>(a) >= get<2>(b)) return false;
    else return true;
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a != b) U[b] = a;
}

int Find(int a)
{
    if(a == U[a]) return a;
    else return U[a] = Find(U[a]);
}
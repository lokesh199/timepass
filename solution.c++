#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define VC vector<char>
#define VVC vector<VC>
#define VS vector<string>
#define VPII vector<PII>

#define MII map<int, int>
#define MIC map<int, char>
#define MIVI map<int, VI>
#define MPIII map<PII, int>

#define QI queue<int>
#define QPII queue<PII>

#define PII pair<int, int>

#define SI set<int>
#define SC set<char>
#define SPII set<PII>

#define F(i, start, end, increment) for (i = start; i < end; i += increment)
#define W(condition) while (condition)

#define LLI long long int
#define ULLI unsigned long long int

using namespace std;

int x4dir[] = {-1, 0, 1, 0};
int y4dir[] = {0, 1, 0, -1};

int x8dir[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y8dir[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int a, int b, int n, int m)
{
    if (a >= 0 && b >= 0 && a < n && b < m)
    {
        return true;
    }
    return false;
}
int bfs(char mat[21][21], int n, int m, int si, int sj, int ei, int ej, int distance[21][21])
{
    if (distance[ei][ej] != INT_MAX)
    {
        return distance[ei][ej];
    }
    else
    {
        QPII q;
        q.push(make_pair(si, sj));
        while (!q.empty())
        {
            PII presentNode = q.front();
            if (presentNode.first == ei && presentNode.second == ej)
            {
                return distance[presentNode.first][presentNode.second];
            }
            q.pop();
            int ni, nj;
            for (int i = 0; i < 4; i++)
            {
                ni = presentNode.first + x4dir[i];
                nj = presentNode.second + y4dir[i];
                PII nextNode = make_pair(ni, nj);
                if (isValid(ni, nj, n, m))
                {
                    q.push(nextNode);
                    if (distance[presentNode.first][presentNode.second] + 1 < distance[ni][nj])
                    {
                        distance[ni][nj] = distance[presentNode.first][presentNode.second] + 1;
                    }
                }
            }
        }
    }
}
int findMinDistance(char mat[21][21], int n, int m, SPII &endPositions, PII &startPosition)
{
    int i, j;
    int distance[21][21];
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 21; j++)
        {
            distance[i][j] = INT_MAX;
        }
    }
    distance[startPosition.first][startPosition.second] = 0;

    int maxi = INT_MIN;
    for (SPII::iterator it = endPositions.begin(); it != endPositions.end(); it++)
    {
        maxi = max(maxi, bfs(mat, n, m, startPosition.first, startPosition.second, (*it).first, (*it).second, distance));
    }
    return maxi;
}
PII findEndPosition(char mat[21][21], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mat[i][j] == 'h')
            {
                return make_pair(i, j);
            }
        }
    }
}
SPII findStartPositions(char mat[21][21], int n, int m)
{
    SPII ans;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mat[i][j] == 'a' || mat[i][j] == 'b' || mat[i][j] == 'c')
            {
                ans.insert(make_pair(i, j));
            }
        }
    }
    return ans;
}
int main()
{

    int n, m, t, i, j, index = 1;
    char mat[21][21];
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        SPII startPos = findStartPositions(mat, n, m);
        PII endPos = findEndPosition(mat, n, m);
        cout << "Case " << index << ": " << findMinDistance(mat, n, m, startPos, endPos) << "\n";
        index++;
    }
}

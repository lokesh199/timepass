#include <bits/stdc++.h>
using namespace std;
int xdir[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ydir[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool isValid(int ni, int nj, int r, int c)
{
    if (ni >= 0 && ni < r && nj >= 0 && nj < c)
    {
        return true;
    }
    return false;
}
int areaOfWaterHelper(vector<string> &s, int r, int c, int x, int y, set<pair<int, int>> &visited)
{
    if (s[x][y] == 'W')
    {
        visited.insert(make_pair(x, y));
        int sum = 1;
        for (int i = 0; i < 8; i++)
        {
            int ni = x + xdir[i];
            int nj = y + ydir[i];
            pair<int, int> neighbour = make_pair(ni, nj);
            if (isValid(ni, nj, r, c) && visited.find(neighbour) == visited.end() && s[ni][nj] == 'W')
            {
                sum += areaOfWaterHelper(s, r, c, ni, nj, visited);
            }
        }
        return sum;
    }
    return 0;
}
int areaOfWater(vector<string> &s, int r, int c, int x, int y)
{
    set<pair<int, int>> visited;
    return areaOfWaterHelper(s, r, c, x, y, visited);
}
int main()
{
    int t;
    string temp, str;
    bool isPoint;
    cin >> t;
    while (t--)
    {
        isPoint = false;
        getline(cin, temp);
        getline(cin, temp);
        vector<string> s;
        while (true)
        {
            cin >> str;
            if (str[0] == 'L' || str[0] == 'W')
            {
                s.push_back(str);
            }
            else
            {
                break;
            }
        }
        int r = s.size();
        int c = s[0].length();
        int x, y;
        x = stoi(str);
        cin >> y;
        x--;
        y--;
        cout << areaOfWater(s, r, c, x, y) << "\n";
        while (cin >> x >> y)
        {
            x--;
            y--;
            cout << areaOfWater(s, r, c, x, y) << "\n";
        }
    }
}

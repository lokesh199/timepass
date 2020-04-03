#include <bits/stdc++.h>
#define MOD 1000000007
#define ULLI unsigned long long int
using namespace std;

ULLI convertToInt(string number)
{
    int len = number.length(), i;
    if (len != 0)
    {
        ULLI n = 0;
        for (i = 0; i < len; i++)
        {
            n = (n * 10 + (number[i] - '0'));
        }
        return n;
    }
    return 0;
}
void findSumHelper(int root, map<int, vector<int>> parentChildMap, string number, ULLI &num1, ULLI &num2)
{
    if (parentChildMap[root].size() == 0)
    {
        string rootInStringForm = to_string(root);
        int previousLenOfNumber = number.length();
        int lengthOfPresentRoot = rootInStringForm.length();
        number += rootInStringForm;
        num2 = convertToInt(number);
        num1 = (num1 % MOD + num2 % MOD) % MOD;
        num2 = 0;
        number.erase(previousLenOfNumber - 1, lengthOfPresentRoot);
    }
    else
    {
        string rootInStringForm = to_string(root);
        int previousLenOfNumber = number.length();
        int lengthOfPresentRoot = rootInStringForm.length();
        number += rootInStringForm;
        for (int i = 0; i < parentChildMap[root].size(); i++)
        {
            findSumHelper(parentChildMap[root][i], parentChildMap, number, num1, num2);
        }
        number.erase(previousLenOfNumber, lengthOfPresentRoot);
    }
}
int findSum(int root, map<int, vector<int>> parentChildMap)
{
    string number;
    ULLI num1 = 0, num2 = 0;
    findSumHelper(root, parentChildMap, number, num1, num2);
    return num1;
}
int main()
{
    int t, i, n, parent, child, root;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, vector<int>> parentChildMap;
        for (i = 0; i < n - 1; i++)
        {
            cin >> parent >> child;
            parentChildMap[parent].push_back(child);
        }
        cin >> root;
        cout << findSum(root, parentChildMap) << "\n";
    }
}

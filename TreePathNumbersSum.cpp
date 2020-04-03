#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int modOnString(string n)
{
    int ans = 0, i;
    int len = n.length();
    for (i = 0; i < len; i++)
    {
        ans = (ans * 10 + n[i] - '0') % MOD;
    }
    return ans;
}
string add(string num1, string num2)
{
    int len1 = num1.length(), len2 = num2.length(), carry = 0, i, j;
    if (len1 > len2)
    {
        string sum(len1 + 1, '0');
        for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
        {
            sum[i + 1] = (((num1[i] - '0') + (num2[j] - '0') + carry) % 10) + '0';
            carry = ((num1[i] - '0') + (num2[j] - '0') + carry) / 10;
        }
        while (i >= 0)
        {
            sum[i + 1] = (((num1[i] - '0') + carry) % 10) + '0';
            carry = ((num1[i] - '0') + carry) / 10;
            i--;
        }
        if (carry > 0)
        {
            sum[0] = carry + '0';
        }
        return sum;
    }
    string sum(len2 + 1, '0');
    for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
    {
        sum[j + 1] = (((num1[i] - '0') + (num2[j] - '0') + carry) % 10) + '0';
        carry = ((num1[i] - '0') + (num2[j] - '0') + carry) / 10;
    }
    while (j >= 0)
    {
        sum[j + 1] = (((num2[j] - '0') + carry) % 10) + '0';
        carry = ((num2[j] - '0') + carry) / 10;
        j--;
    }
    if (carry > 0)
    {
        sum[0] = carry + '0';
    }
    return sum;
}
void findSumHelper(int root, map<int, vector<int>> parentChildMap, string &number, string &num1, string &num2)
{
    if (parentChildMap.find(root) == parentChildMap.end())
    {
        string rootInStringForm = to_string(root);
        int previousLenOfNumber = number.length();
        int lengthOfPresentRoot = rootInStringForm.length();
        number += rootInStringForm;
        num2.assign(number);
        num1.assign(add(num1, num2));
        num2.clear();
        number.erase(previousLenOfNumber, lengthOfPresentRoot);
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
    string num1, num2;
    findSumHelper(root, parentChildMap, number, num1, num2);
    int ans = modOnString(num1);
    return ans;
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

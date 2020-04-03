/*
Given an N-ary tree, where each node can have zero or more children. We are required to find the sum of all the 
numbers formed by traversing from root to leaf nodes in the tree. Nodes of the tree are guarnenteed to contain unique numbers.

Input Format

First line of input contains T - number of test cases. Its followed by 3*T lines. First line of each test case 
contains N - number of nodes in the tree. Next N-1 lines of the test case contain two space separated integers 
p c representing parent child relationships. Last line of the test case contains identifier for root of the tree.

Constraints

1 <= T <= 1000
1 <= N <= 1000

Output Format

For each test case, print a single number S representing sum of all the numbers formed by traversing all the paths
from root to leaf. Print answer MOD 1000000007 (109+7).
*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int modOnString(string n)
{
    int ans = 0, i;
    int len = n.length();
    for (i = 0; i < len; i++)
    {
        ans = (ans * 10 + (int)n[i] - '0') % MOD;
    }
    return ans;
}
void add(string &num1, string num2)
{
    // cout << "inside add num1 = " << num1 << " num2 = " << num2 << "\n";
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
        else
        {
            if (sum[0] == '0')
            {
                sum = sum.erase(0, 1);
            }
        }
        num1.assign(sum);
    }
    else
    {
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
        else
        {
            if (sum[0] == '0')
            {
                sum = sum.erase(0, 1);
            }
        }
        num1.assign(sum);
    }
}
void findSumHelper(int root, map<int, vector<int>> &parentChildMap, string number, string &num1)
{
    if (parentChildMap.find(root) == parentChildMap.end())
    {
        string rootInStringForm = to_string(root);
        number += rootInStringForm;
        // cout << "number = " << number << "\n";
        add(num1, number);
        // cout << "num1 = " << num1 << "\n";
    }
    else
    {
        string rootInStringForm = to_string(root);
        number += rootInStringForm;
        // cout << "number = " << number << "\n";
        for (int i = 0; i < parentChildMap[root].size(); i++)
        {
            findSumHelper(parentChildMap[root][i], parentChildMap, number, num1);
        }
    }
}
int findSum(int root, map<int, vector<int>> parentChildMap)
{
    string number;
    string num1;
    findSumHelper(root, parentChildMap, number, num1);
    cout << "num1 = " << num1 << "\n";
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

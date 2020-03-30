#include <bits/stdc++.h>
using namespace std;
struct BT
{
    int data;
    struct BT *left, *right;
};
typedef struct BT BT;
void verticalOrderTraversalTopToBottomHelper(BT *root, int verticalLevel, map<int, vector<BT *>> &mp)
{
    if (root)
    {
        mp[verticalLevel].push_back(root);
        verticalOrderTraversalTopToBottomHelper(root->left, verticalLevel - 1, mp);
        verticalOrderTraversalTopToBottomHelper(root->right, verticalLevel + 1, mp);
    }
}
void verticalOrderTraversalTopToBottom(BT *root, int verticalLevel, map<int, vector<BT *>> &mp)
{
    int i;
    verticalOrderTraversalTopToBottomHelper(root, verticalLevel, mp);
    for (map<int, vector<BT *>>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        int verticalLevelLength = (*it).second.size();
        for (i = 0; i < verticalLevelLength; i++)
        {
            cout << (*it).second[i]->data << " ";
        }
    }
}
BT *createNewnode(int n)
{
    BT *node = new BT;
    node->data = n;
    node->left = node->right = NULL;
    return node;
}
bool isInRange(int number, int left, int right)
{
    if (number >= left && number <= right)
    {
        return true;
    }
    return false;
}
int findInorderIndex(unordered_map<int, vector<pair<int, bool>>> &inorderIndex, int value, int inorderStart, int inorderEnd)
{
    int i;
    int inorderElementIndexLength = inorderIndex[value].size();
    for (vector<pair<int, bool>>::iterator it = inorderIndex[value].begin();
         it != inorderIndex[value].end();
         it++)
    {
        if (isInRange((*it).first, inorderStart, inorderEnd))
        {
            (*it).second = true;
            return (*it).first;
        }
    }
}
BT *BTUsingInorderPreorder(int *inorder, int *preorder, unordered_map<int, vector<pair<int, bool>>> &inorderIndex, int inorderStart, int inorderEnd, int &preorderIndex)
{
    if (inorderStart > inorderEnd)
    {
        return NULL;
    }
    int value = preorder[preorderIndex];
    preorderIndex++;
    int index = findInorderIndex(inorderIndex, value, inorderStart, inorderEnd);
    BT *root = createNewnode(value);
    if (inorderStart == inorderEnd)
    {
        return root;
    }
    else
    {
        root->left = BTUsingInorderPreorder(inorder, preorder, inorderIndex, inorderStart, index - 1, preorderIndex);
        root->right = BTUsingInorderPreorder(inorder, preorder, inorderIndex, index + 1, inorderEnd, preorderIndex);
        return root;
    }
}
void inorderTraversal(BT *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
int main()
{
    int n, i, preorderIndex = 0;
    cin >> n;
    int inorderStart = 0, inorderEnd = n - 1;
    int *inorder = new int[n];
    int *preorder = new int[n];
    unordered_map<int, vector<pair<int, bool>>> inorderIndex;
    for (i = 0; i < n; i++)
    {
        cin >> inorder[i];
        inorderIndex[inorder[i]].push_back(make_pair(i, false));
    }
    for (i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    BT *root = BTUsingInorderPreorder(inorder, preorder, inorderIndex, inorderStart, inorderEnd, preorderIndex);
    map<int, vector<BT *>> mp;
    // inorderTraversal(root);
    verticalOrderTraversalTopToBottom(root, 0, mp);
}

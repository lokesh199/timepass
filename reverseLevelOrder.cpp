#include <bits/stdc++.h>
using namespace std;
struct BST
{
    int data;
    struct BST* left , *right;
};
typedef struct BST BST;
void reverseLevelOrderTraversalBST(BST* root)
{
    if(root == NULL)
    {
        return;
    }
    stack<vector<BST*>> levelsDownToUp;
    queue<BST*> q;
    q.push(root);
    while(!q.empty())
    {
        int levelLength = q.size();
        vector<BST* > thisLevelElements;
        for(int i=0 ; i<levelLength ; i++)
        {
            BST* node = q.front();
            q.pop();
            thisLevelElements.push_back(node);
            if(node->left)
            {
                q.push(node);
            }
            if(node->right)
            {
                q.push(node);
            }
        }
        levelsDownToUp.push(thisLevelElements);
        thisLevelElements.clear();
    }
    int noOfLevels = levelsDownToUp.size();
    cout<<noOfLevels;
    // for(int i=0;i<noOfLevels;i++)
    // {
    //     int noOfPresentLevelElements = levelsDownToUp.top().size();
    //     for(int j=0 ; j < noOfPresentLevelElements ; j++)
    //     {
    //         cout<<levelsDownToUp.top()[j]<<" ";
    //     }
    //     cout<<"\n";
    //     levelsDownToUp.pop();
    // }
}
BST* createNewnode(int value)
{
    BST* node = new BST;
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
BST* insertInBST(BST* root , int n)
{
    if(root == NULL)
    {
        return createNewnode(n);
    }
    else 
    {
        if(n > root->data)
        {
            root->right = insertInBST(root->right , n);
        }
        else 
        {
            root->left = insertInBST(root->left , n);
        }
        return root;
    }
}
BST* deAllocateMemory(BST* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    else 
    {
        root->left = deAllocateMemory(root->left);
        root->right = deAllocateMemory(root->right);
        delete root;
        return NULL;
    }
}    

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    BST* root;
    int t , n , x , i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        root = NULL;
        for(i=0;i<n;i++)
        {
            cin>>x;
            root = insertInBST(root , x);
        }
        reverseLevelOrderTraversalBST(root);
        deAllocateMemory(root);
    }
}

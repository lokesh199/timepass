/*
Given a 5xN sized field that needs to be covered by tiles. We are given tiles of 2 different sizes: 1x5 and 2x5. While covering
the field, we are allowed to rotate the tiles such that we can place a tile horizontally or vertically. How many
total unique ways are there to cover the field with tiles such that field gets completely covered - We are not allowed to
break the tiles or leave any space empty on the field.
*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int dp[1000005]; // here previously i used vector but it is giving segmentation fault for n value 1000000
long find(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(dp[n] != (long)-1)
    {
        return dp[n];
    }
    else 
    {
        dp[n] = ((find(n-1)%MOD + /*(long long)*/find(n-2)%MOD)%MOD + /*(long long)*/(8*find(n-5))%MOD)%MOD;
    }
    return dp[n];
}
int main()
{
    int t,n;
    cin>>t;
    fill(dp , dp+1000005 , -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    while(t--)
    {
        cin>>n;
        cout<<find(n)<<"\n";
    }
}

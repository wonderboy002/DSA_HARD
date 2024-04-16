#include <bits/stdc++.h>
using namespace std;
int solveUsingRecursion(int *profits, int *weights, int n, int i, int wk)
{
    // base case
    // last element either include or exclude it

    if (i == n)
    {
        return 0;
    }

    // main recursion code
    // include exclude pattern
    int include = 0;
    int exclude=0;

    if (weights[i] <= wk)
    {
        include = profits[i] + solveUsingRecursion(profits, weights, n, i + 1, wk - weights[i]);
    }
    exclude = 0 + solveUsingRecursion(profits, weights, n, i + 1, wk);
    int ans=max(include,exclude);
    return ans;
}

int solveUsingTabulation(int *profits, int *weights, int n, int i, int wk){
    //create dp table
    vector<vector<int>> dp(wk+1,vector<int> (n+1,-1));
    //store answer of base cases
    //for every capacity dp[capacity][n]=0
    for (int row=0;row<=wk;row++){
        dp[row][n]=0;
    }
    
    //build answer from base cases
    //i shows capacity and j shows indices
    for (int i=0;i<=wk;i++){
        for (int j=n-1;j>=0;j--){
            //check whether item can be taken
            int include=0;
            if (weights[j]<=i){
                include=profits[j]+dp[i-weights[j]][j+1];
            }
            int exclude=dp[i][j+1];
            dp[i][j]=max(include,exclude);
        }
    }

    return dp[wk][0];
}

int main()
{
    int profits[] = {60,100,120};
    int weights[] = {10, 20, 30};
    int wk = 50;
    int index = 0;
    int size = 3;

    int ans = solveUsingRecursion(profits, weights, size, index, wk);
    cout << "Maximum achieveable profit is : " << ans << endl;

    //tabulation method 
    int ans2=solveUsingTabulation(profits,weights,size,index,wk);
    cout<<"maximum achieveable profit using tabulation is : "<<ans2<<endl;
    return 0;
}
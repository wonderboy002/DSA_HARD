#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

int fibUsingMemo(int n, vector<int> &dp)
{
    //base case
    if (n==0 || n==1){
        return n;
    }

    if (dp[n]!=-1){
        return dp[n];
    }

    dp[n]=fibUsingMemo(n-2,dp)+fibUsingMemo(n-1,dp);
    return dp[n];
}

int fibUsingTabulation(int n,vector<int> &dp){
    //store solutions of base cases
    if (n==0 || n==1){
        return n;
    }
    dp[0]=0;
    dp[1]=1;

    for (int i=2;i<=n;i++){
        dp[i]=dp[i-2]+dp[i-1];
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "enter n : " << endl;
    cin >> n;
    // plain recursive solution
    //  cout<<"The nth fibonacci number is given by : "<<fib(n)<<endl;
    // top down approach memoization store results of already solved problems in dp array to avoid re calculating them

    // vector<int> dp(n + 1, -1);
    // cout << "The nth fibonacci number is given by : " << fibUsingMemo(n, dp) << endl;

    //tabulation method of dp 
    //build solutions from base cases and return the final answer
    vector<int> dp(n+1,-1);
    cout << "The nth fibonacci number is given by : " << fibUsingTabulation(n, dp) << endl;
    return 0;
}
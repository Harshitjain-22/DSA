#include <bits/stdc++.h> 
int solveMem(vector<int> &num, int tar,vector<int>& dp){
    if(tar < 0)
        return 0;
    
    if(tar == 0)
        return 1;

    if(dp[tar]!=-1)
    return dp[tar];

    int ans = 0;
    for(int i = 0 ; i<num.size() ; i++){
       ans+= solveMem(num , tar-num[i],dp);
       
    }
    dp[tar] = ans;
    return dp[tar];
    
}
int findWays(vector<int> &num, int tar)
{
    // Memoization
    // vector<int> dp(tar+1 , -1);
    // return solveMem(num,tar,dp);

    // Tabulation
    vector<int> dp(tar+1 , 0);
    dp[0] = 1;
    int ans = 0;
    for(int i = 1 ; i<=tar ; i++){
        for(int j = 0 ; j<num.size(); j++){
            if(i - num[j]>=0)
                dp[i]+=dp[i-num[j]];
        }
    }
    return dp[tar];
}

question link - https://www.naukri.com/code360/problems/number-of-ways_3755252?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
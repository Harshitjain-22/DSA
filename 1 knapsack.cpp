#include <bits/stdc++.h> 

int solveMem(vector<int> weight, vector<int> value, int index, int maxWeight,vector<vector<int>>& dp){
	if(index==0){
		if(weight[0]<=maxWeight){
			return value[0];
		}
		else
		return 0;
	}

	if(dp[index][maxWeight]!=-1){
		return dp[index][maxWeight];
	}

	//include weight
	int inc = 0;
	if(weight[index]<=maxWeight)
	inc = value[index]+solveMem(weight,value,index-1,maxWeight-weight[index],dp);


	//exclude weight
	int exc = 0;
	exc = solveMem(weight,value,index-1,maxWeight,dp);

	dp[index][maxWeight] = max(inc,exc);
	return dp[index][maxWeight];
}

int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight){
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

	for(int w=weight[0];w<maxWeight+1;w++){

		dp[0][w]=value[0];

		}

	for (int i = 1; i < n; i++) {

		for (int w = 0; w <= maxWeight; w++) {

			int include = 0, exclude = 0;

			if (weight[i]<=w) {

				include = value[i] + dp[i - 1][w - weight[i]];

			}

			exclude = dp[i - 1][w];

			dp[i][w] = max(include, exclude);

		}

	}

	return dp[n-1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
		//Memoization solution

		// vector<vector<int>> dp(n,vector<int>(maxWeight+1 , -1));
		// return solveMem(weight,value,n-1,maxWeight,dp);


		// Tabulation approach
		// return solveTab(weight,value,n,maxWeight);

		// Space optimized
	
	vector<int> curr(maxWeight+1 , 0);
	

	for(int w=weight[0];w<maxWeight+1;w++){

		curr[w]=value[0];

		}

	for (int i = 1; i < n; i++) {

		for (int w = maxWeight; w>=0; w--) {

			int include = 0, exclude = 0;

			if (weight[i]<=w) {

				include = value[i] + curr[w - weight[i]];

			}

			exclude = curr[w];

			curr[w] = max(include, exclude);

		}
		

	}

	return	curr[maxWeight];

}


// question link - https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
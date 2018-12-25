#include <bits/stdc++.h>
using namespace std;

int ncr(int n,int r)
{
	if(r > n-r)
		r = n-r;

	int ans = 1;
	for(int i=0;i<r;i++)
	{
		ans *= n-i;
		ans /= r-i;
	}

	return ans;
}


int calculateArr(int arr[100],int n)
{
	//cout << arr[0] << arr[1] << endl;
	int dp[n];
	for(int i=0;i<n;i++)
		dp[i] = 1;

	int maxm = INT_MIN;
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<j;i++)
		{
			if(arr[i-1] < arr[j-1])
			{
				dp[j] = max(dp[j],1+dp[i]);
				maxm = max(maxm,dp[j]);
			}

		}
	}

	int res = 0;
	for(int i=2;i<n;i++)
	{
		if(dp[i] >= 3)
			res += ncr(dp[i],3);
	}
	
	return res;

}

int main()
{
	int n;
	cin >> n;
	int arr[100];

	for(int i=0;i<n;i++)
		cin >> arr[i];

	int res = calculateArr(arr,n);
	reverse(arr,arr+n);
	res += calculateArr(arr,n);
	cout << res << endl;

	return 0;
}
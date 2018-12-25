#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > findAdjacent(int i,int j,int arr[100][100],int r,int c)
{
	vector<pair<int,int> > adj;

	if(i-1 >= 0 && arr[i-1][j] != 1)//up
	{
		pair<int,int> p = make_pair(i-1,j);
		adj.push_back(p);
	}
	if(j+1 < c && arr[i][j+1] != 1)// right
	{
		pair<int,int> p = make_pair(i,j+1);
		adj.push_back(p);
	}
	if(i+1 < r && arr[i+1][j] != 1)// down
	{
		pair<int,int> p = make_pair(i+1,j);
		adj.push_back(p);
	}
	if(j-1 >= 0 && arr[i][j-1] != 1)// left
	{
		pair<int,int> p = make_pair(i,j-1);
		adj.push_back(p);
	}

	return adj;
}

bool isBoundary(int i,int j,int r,int c)
{
	return ((i == 0) || (i == r-1) || (j == 0) || (j == c-1));
}

void dfs(bool visited[100][100],int r,int c,int arr[100][100],int val,int &minval,int i,int j)
{
	visited[i][j] = true;
	vector<pair<int,int> > adj = findAdjacent(i,j,arr,r,c);

	for(int k=0;k<adj.size();k++)
	{
		if(!visited[adj[k].first][adj[k].second])
		{
			if(isBoundary(adj[k].first,adj[k].second,r,c) && (minval > val+1))
			{
				minval = val + 1;
			}

			dfs(visited,r,c,arr,val+1,minval,adj[k].first,adj[k].second);
		}
	}

}


int main()
{
	int r,c,i,j;
	cin >> r >> c;

	int arr[100][100];
	int strt_r;
	int strt_c;

	bool visited[100][100];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			visited[i][j] = false;
			cin >> arr[i][j];
			if(arr[i][j] == 2)
			{
				strt_r = i;
				strt_c = j;
			}
		}
	}

	if(isBoundary(strt_r,strt_c,r,c))
		cout << 0 << endl;
	else
	{
		int minval = INT_MAX;
		dfs(visited,r,c,arr,0,minval,strt_r,strt_c);
		cout << minval << endl;	
	}

	return 0;

}
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int cases,i1,j,k;
	cin >> cases;
	for(i1=0;i1<cases;i1++)
	{
		int n;
		cin >> n;

		int arr[n];

		int diff[n-1];
		for(int i=0;i<n;i++)
			cin >> arr[i];

		for(int i=0;i<n-1;i++)
		{
			if(arr[i+1] - arr[i] >= 0)
				diff[i] = 1;
			else
				diff[i] = -1;

			//cout << diff[i] << " ";
		}
		//cout << endl ;
		

		int first = -22;
		k = 0;
		while(diff[k] == -1)
		{
			k++;
		}

		first = k;
		vector<pair<int,int> > v;
		int in1 = 0,in2 = 0;

		for(int i = first;i<n-1;i++)
		{
			while(diff[i] == 1)
			{
				i++;
				//cout << i << endl;
				if(i == n-1)
				{
					pair<int,int> p = make_pair(first,i);
					v.push_back(p);
					in1 = 1;
					break;
				}
			}

			if(in1 == 1)
				break;

			pair<int,int> p = make_pair(first,i);
			v.push_back(p);
			
			while(diff[i] == -1)
			{
				i++;
				if(i == n-1)
					{
						in2 = 1;
						break;
					}
			}

			if(in2 == 1)
				break;
			first = i;

			if(first == n-2)
			{
				pair<int,int> p = make_pair(first,i+1);
				v.push_back(p);
				break;
			}


		}

		if(v.size() > 0)
		{
			for(int i=0;i<v.size();i++)
			cout << "(" << v[i].first << " " << v[i].second << ") ";

			cout << endl;
		}
		else
			cout << "No Profit" << endl;

		
	
	}
	return 0;
}
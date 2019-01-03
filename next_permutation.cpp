#include<bits/stdc++.h>
using namespace std;

void nextPermute(int arr[],int n)
{
    int down = -1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i] > arr[i+1])
        {
            continue;
        }
        else
        {
            down = i;
            break;
        }
    }
    
    if(down == -1)// reverse sorted
    {
        for(int i=0;i<n;i++)
        {
            cout << arr[n-i-1] << " ";
        }
        cout << endl;
    }
    else// down != -1
    {
        //print first no.s as it is
        for(int i=0;i<down;i++)
        {
            cout << arr[i] << " ";
        }
        
        for(int i=n-1;i>down;i--)
        {
            if(arr[i] < arr[down])
                continue;
            else
            {
                cout << arr[i] << " ";
                
                for(int j=n-1;j>i;j--)// print left items in reverse
                    cout << arr[j] << " ";
                
                cout << arr[down] <<  " ";//print yourself
                
                for(int j=i-1;j>down;j--)// print remaining in reverse
                    cout << arr[j] << " ";
                    
                cout << endl;
                
                break;
            }
        }
    }
    
}

int main()
 {
	//code
	int cases,i,j,k;
	cin >> cases;
	for(i=0;i<cases;i++)
	{
	    int n;
	    cin >> n;
	    int arr[n];
	    for(j=0;j<n;j++)
	        cin >> arr[j];
	        
	    nextPermute(arr,n);
	}
	return 0;
}
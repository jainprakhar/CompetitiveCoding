#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int cases,i1,j,k;
	cin >> cases;
	for(i1=0;i1<cases;i1++)
	{
	    int len;
	    cin >> len;
	    
	    string s;
	    cin >> s;
	    
	    bool table[len][len];
	    memset(table,false,sizeof(table));
	    
	    int count = 0;
	    
	    for(j=0;j<len;j++)
	        table[j][j] = true;
	        
	    for(j=1;j<len;j++)
	    {
	        if(s[j-1] == s[j])
	        {
	            table[j-1][j] = true,count++;
	        }
	    }
	    
	    for(j=3;j<=len;j++)// length 3 and more
	    {
	        for(int i=0;i<=len-j;i++)
	        {
	            k = i+j-1;
	            
	            if(s[i] == s[k] && table[i+1][k-1])
	            {
	                //cout << i <<  "  " << k << endl;
	                table[i][k] = true,count++;
	            }
	        }
	        
	    }
	    
	    
	    cout << count << endl;
	    
	    
	    
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

void calculateZ(string concat,int Z[],int pattlen)
{
    int len = concat.length();
    int r=0,l=0;
    
    for(int i=1;i<len;i++)
    {
        if(i>r)
        {
            r=l=i;
            
            while(r<len && concat[r-l] == concat[r])
                r++;
            Z[i] = r-l;
            r--;
        }
        else
        {
            int k = i-l;
            if(Z[k] < r-i+1)
                Z[i] = Z[k];
                
            else
            {
                l = i;
                while(r<len && concat[r-l] == concat[r])
                r++;
                Z[i] = r-l;
                r--;
            }
        }
    }
    Z[0] = 0;
 
    for(int i=0;i<len;i++)
    {
        
        if(Z[i] == pattlen)
        {
            int j;
            for(j=i;j<i+pattlen;j++)
                {
                    Z[j] = 1;
                
                }
            i = j-1;
          
        }
        else
        {
            Z[i] = 0;
        }
       
    }
  
    
}

bool AND(int Z1[],int Z2[],int Z3[],int slen)
{
    for(int i=0;i<slen;i++)
    {
        bool prod = Z1[i+2]|| Z2[i+3] || Z3[i+4];
        if(!prod)return false;
    }
    
    return true;
}

int main()
 {
	//code
	int cases,i,j,k;
	cin >> cases;
	for(i=0;i<cases;i++)
	{
	    string s;
	    cin >> s;
	    
	    string p1 = "R";
	    string p2 = "RY";
	    string p3 = "RYY";
	    
	    int Z1[p1.length()+s.length()+1];
	    int Z2[p2.length()+s.length()+1];
	    int Z3[p3.length()+s.length()+1];
	    string concat1 = p1+"$"+s;
	    string concat2 = p2+"$"+s;
        string concat3 = p3+"$"+s;
	    calculateZ(concat1,Z1,1);
	    calculateZ(concat2,Z2,2);
	    calculateZ(concat3,Z3,3);
	    
	    
	    
	    if(AND(Z1,Z2,Z3,s.length()))
	        cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define lli long long
#define M 1000000007
using namespace std;

class triple{
   
   public:
   int a;
   int b;
   int c;
   triple(int x,int y, int z);
    
};

triple::triple(int x,int y,int z)
{
    a = x;
    b = y;
    c = z;
}

int main()
 {
	//code
	lli cases,i,j,k;
	cin >> cases;
	for(i=0;i<cases;i++)
	{
	    int x;int y;int z;
	    cin >> x >> y >> z;
	    int digits = x+y+z;
	    vector <pair<lli,triple> > sum;
	    lli totalSum = 0;
	    if(x!=0)
	        {sum.push_back(make_pair(4,triple(x-1,y,z))),totalSum += 4;}
	    if(y!=0)
	        {sum.push_back(make_pair(5,triple(x,y-1,z))),totalSum += 5;}
	    if(z!=0)
	        {sum.push_back(make_pair(6,triple(x,y,z-1))),totalSum += 6;}
	    
        for(j=1;j<digits;j++)
        {   
            vector<pair<lli,triple > > sum1;
            //cout << "Digits: " << j+1 << endl;
            
            for(k=0;k<sum.size();k++)
            {
                pair<lli,triple> curr = sum[k];
                int triplea = (curr.second).a;
                int tripleb = (curr.second).b;
                int triplec = (curr.second).c;
                
                for(int g=0;g<3;g++)
                {
                    if(g == 0 && triplea > 0)// for 4
                    {
                        lli currsum = (10*curr.first%M + 4)%M;
                       //  cout << "Curr Sum: " << currsum << endl;
                        totalSum +=  currsum;
                        totalSum %= M; 
                        sum1.push_back(make_pair(currsum,triple(triplea-1,tripleb,triplec)));
                    }
                    if(g == 1 && tripleb > 0)// for 5
                    {
                        lli currsum = (10*curr.first%M + 5)%M;
                        //cout << "Curr Sum: " << currsum << endl;
                        totalSum +=  currsum;
                        totalSum %= M; 
                        sum1.push_back(make_pair(currsum,triple(triplea,tripleb-1,triplec)));
                        
                    }
                    if(g == 2 && triplec > 0)// for 6
                    {
                        lli currsum = (10*curr.first%M + 6)%M;
                      // cout << "Curr Sum: " << currsum << endl;
                        totalSum +=  currsum;
                        totalSum %= M; 
                        sum1.push_back(make_pair(currsum,triple(triplea,tripleb,triplec-1)));
                    }
                }
                
            }
            sum = sum1;
        }
	    
	    cout << totalSum%M << endl;
	    
	}
	return 0;
}
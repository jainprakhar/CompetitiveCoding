#include<bits/stdc++.h>
using namespace std;

string order;


int n = 0;


bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}


typedef struct graph{
  
  char ch;
  vector<char> adj;
};


pair<char,char> mismatch(string s1,string s2)
{
    for(int i=0;i<min(s1.length(),s2.length());i++)
    {
        if(s1[i] == s2[i])
            continue;
        else
        {
            pair<int,int> p = make_pair(s1[i],s2[i]);
            return p;
        }
    }
    
    pair<char,char> mp = make_pair('$','$');
    return mp;
    
}

vector<int> findAdjacent(bool graph[][27],int v,int k)
{
    vector<int> vec;
    for(int i=0;i<k+1;i++)
    {
        if(graph[v][i])
            vec.push_back(i);
    }
    
    return vec;
}


void topologySort(int v,bool graph[][27],stack<int> &st,vector<bool> &visited,bool adjacent[][27],int k)
{
    visited[v] = true;
    
     
    vector<int> adj = findAdjacent(graph,v,k);

    for(int i=0;i<adj.size();i++)
    {
        if(!visited[adj[i]])
            topologySort(adj[i],graph,st,visited,adjacent,k);
    }
    
    st.push(v);
    
}


string printOrder(string dict[], int N, int k)
{
   //Your code here
 
    bool graph[27][27];
    // vector<vector<bool> > graph(N+1);
    bool adjacent[27][27];
    
     for(int i=0;i<27;i++)
    {
      for(int j=0;j<27;j++)
      {
        graph[i][j] = false;
        adjacent[i][j] = false;
      }
    }


    // memset(graph,false,sizeof(graph[0][0])*(27)*(27));
   
   
   map<char,int> m;//it will match character to its int no
   map<int,char> n2c;// no to character
   
   int k1 = 1;
   for(int i=0;i<N;i++)
   {
       string s = dict[i];
       for(int j=0;j<s.length();j++)
       {
           if(!m[s[j]])
           {
               m[s[j]] = k1;
               n2c[k1] = s[j];
               k1++;
               cout << "char: " << s[j] << " val: " << m[s[j]] << endl;
           }
       }
   }

  
   
    for(int i=1;i<N;i++)
    {
      
        string word1 = dict[i-1];
        string word2 = dict[i];
        pair<char,char> p = mismatch(word1,word2);
        // cout << p.first << " " << p.second << endl;
        if(p.first != '$')
        {
            // edge from u to v;
            char u = p.first;
            char v = p.second;
           
            cout << "Edge from: " << u << " to: " << v << endl;
            graph[m[u]][m[v]] = true;
            adjacent[m[u]][m[v]] = true;;
        }
        
    }

   
    vector<bool> visited(k);
    
    for(int i=0;i<k;i++)
        visited[i] = false;
        
    stack<int> st;
        
    for(int i=0;i<k;i++)
    {
        if(!visited[i])
        {
            cout <<  "New:  "<< n2c[i] << endl;
            topologySort(i,graph,st,visited,adjacent,k);//vertex,graph,stack
        }
    }
    
    string ans = "";
    while(!st.empty())
    {
        ans += n2c[st.top()];
        st.pop();
    }

    cout << ans << endl;
    
    return ans;
    
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];
        
        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);
        
        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;
        
        cout<<f;
        cout<<endl;
        
    }
	return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */


#include <bits/stdc++.h>
#define lli long long int
using namespace std;


lli factorial(int n) 
{ 
    if (n == 0) 
      return 1; 
    return n*factorial(n-1); 
} 



int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		string s1,s2;
		cin >> s1;
		cin >> s2;
		cout << "****" << endl;
		cout << s1 << endl;
		cout << s2 << endl;
		lli k;
		cin >> k;

		char ans[27];
		ans[26] = '\0';
		map<char,bool> m;
		for(int i=0;i<26;i++)
		{
			m['a' + i] = true;
			ans[i] = '$';
		}

		char temp[26-s1.length()];// u can manipulate remainig characters
		
		for(int i=0;i<s1.length();i++)
		{
			m[s2[i]] = false;
			ans[s1[i]-'a'] = s2[i];
		}

		lli fact = factorial(26-s1.length());

		if(k > fact)
		{
			cout << "Not Possible" << endl;
		}
		else
		{
			int j = 0;
			for(int i=0;i<26;i++)
			{
				if(m['a'+ i])
				{
					temp[j++] = 'a' + i;
				}
			}

			for(int i=0;i<k-1;i++)
			{
				next_permutation(temp,temp+26-s1.length());
			}

			int l = 0;
			for(int i=0;i<26;i++)
			{
				if(ans[i] == '$')
				{
					ans[i] = temp[l++];
				}
			}

			printf("%s",ans);
		}


	}

	return 0;

}
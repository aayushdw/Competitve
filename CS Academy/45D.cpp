#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define vi vector<int> 
#define vvi vector< vi > 
#define vl vector<long long int>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define priority_queue pq;
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 100000+5
using namespace std;

set<string> s;

int CountPS(string str)
{
	s.clear();
	int n = str.size();
	int dp[n][n];
    memset(dp, 0, sizeof(dp));
    bool P[n][n];
    memset(P, false , sizeof(P));
 
    for (int i= 0; i< n; i++)
    {
        P[i][i] = true;
        string temp;
        rep(j,i,i+1)
        	temp.pb(str[j]);
        s.insert(temp);
    }
 
    // palindrome of length 2
    for (int i=0; i<n-1; i++)
    {
        if (str[i] == str[i+1])
        {
            P[i][i+1] = true;
            dp[i][i+1] = 1 ;
            string temp;
        	rep(k,i,i+2)
        		temp.pb(str[k]);
        	s.insert(temp);
        }
    }
 	for (int gap=2 ; gap<n; gap++)
    {
        // Pick starting point for current gap
        for (int i=0; i<n-gap; i++)
        {
            // Set ending point
            int j = gap + i;
 
            // If current string is palindrome
            if (str[i] == str[j] && P[i+1][j-1] )
            {
                P[i][j] = true;
                string temp;
        		rep(k,i,j+1)
        			temp.pb(str[k]);
        		s.insert(temp);
            }
 
            if (P[i][j] == true)
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1];
            else
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
        }
    }
 
    // return total palindromic substrings
    return dp[0][n-1];
}

int main()
{
	/*int n;
	si(n);
	int ans=INT_MAX;
	string str,temp;
	temp.resize(n);
	rep(i,0,1<<n)
	{
		rep(j,0,n)
		temp[j]='0'+ison(i,j);
		//cout<<temp<<" ";
		CountPS(temp);
		int num=s.size();
		//cout<<num<<endl;
		if(num<ans)
		{
			ans=num;
			str=temp;
		}
	}
	cout<<ans<<endl<<str<<endl;*/
	/*string str = "00110100";
	CountPS(str);
	cout<<s.size()<<endl;*/
	/*CountPS(str);
	tr(i,s)
	cout<<*i<<endl;*/
	/*string temp="1011010",ans;
	rep(i,0,n)
	ans.pb(temp[i%6]);
	CountPS(ans);
	tr(i,s)
	cout<<*i<<endl;
	cout<<s.size()<<endl;
	cout<<ans<<endl;*/
	int n;
	si(n);
	if(n<8)
		pr(n);
	else if(n==8)
		pr(7);
	else
		pr(8);
	string str = "001011";
	rep(i,0,n)
	printf("%c",str[i%6]);
	return 0;
}
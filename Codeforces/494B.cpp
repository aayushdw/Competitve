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
#define MAX 200000+5
using namespace std;

ll Z[MAX],pre[MAX],tot[MAX];
bitset<MAX> found;

void calcZ(ll Z[],string s)
{
	int L = 0, R = 0;
	int n=s.length();
	for (int i = 1; i < n; i++)
	{
		if (i > R)
		{
			L = R = i;
			while (R < n && s[R-L] == s[R]) R++;
			Z[i] = R-L; R--;
		}
		else
		{
			int k = i-L;
			if (Z[k] < R-i+1)
				Z[i] = Z[k];
			else
			{
				L = i;
				while (R < n && s[R-L] == s[R])
					R++;
				Z[i] = R-L; R--;
			}
		}
	}
}

void search(string text, string pattern)
{
    string concat = pattern + "$" + text;
    int l = concat.length();
 
    calcZ(Z,concat);
 
 	for (int i = 0; i < l; ++i)
    {
        if (Z[i] == pattern.length()) //PATTERN FOUND
            found[(i-pattern.length()-1)]=true;;
    }
}

int main()
{
	string s,pat;
	cin>>s;
	cin>>pat;
	found.reset();
	search(s,pat);
	ll n=s.length();
	ll m=pat.length();
	clr(tot); clr(pre);
	for(int i=n-1;i>=0;i--)
	{
		if(found[i])
		{
			pre[i]=pre[i+1];
			tot[i]=tot[i+1]+pre[i];
			pre[i]+=tot[i+m]+1;
			tot[i]+=tot[i+m]+1;

			rep(j,i+1,n-m+1)
			if(found[j])
				break;
			else
				pre[i]+=tot[j+m]+1, tot[i]+=tot[j+m]+1;
		}
		else
		{
			pre[i]=pre[i+1];
			tot[i]=tot[i+1]+pre[i];
		}
		pre[i]%=MOD;
		tot[i]%=MOD;
	}
	/*rep(i,0,n)
	printf("%d %d\n",pre[i],tot[i]);*/
	prll(tot[0]);
	return 0;
}
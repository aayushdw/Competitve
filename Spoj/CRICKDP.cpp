#include<stdio.h>
#include<vector>
#include<set>
#include<limits.h>
#define sc(x) scanf("%d",&x)
#define N_MAX 100005
#define K_MAX 205
#define ll long long int
using namespace std;
ll dp[N_MAX][K_MAX];
int main()
{
	int t,n,m,k,i,j,rating;
	sc(t);
	while(t--)
	{
		sc(n); sc(k); sc(m); rating=0;
		int a[n],b[m][3];
		vector<int> arr(n,INT_MAX);
		for(i=0;i<n;i++)
		{
			sc(a[i]);
			rating+=a[i];
		}
		for(i=0;i<m;i++)
		{
			sc(b[i][0]); sc(b[i][1]); sc(b[i][2]);
			b[i][0]--;
			b[i][1]--;
			b[i][2];
		}
		vector<int> L[n],R[n];
		for(i=0;i<m;i++)
		{
			L[b[i][0]].push_back(i);
			R[b[i][1]].push_back(i);
		}
		set<int> s;
		for(i=0;i<n;i++)
		{
			for(j=0;j<L[i].size();j++)
			s.insert(b[L[i][j]][2]);
			if(s.begin()!=s.end())
			arr[i]=*(s.begin());
			else
			arr[i]=-1;
			for(j=0;j<R[i].size();j++)
			s.erase(b[R[i][j]][2]);
		}
		/*for(i=0;i<n;i++)
		printf("%d ",arr[i]);
		printf("\n");*/
		vector < pair<int,int> > v;
		for(i=0;i<n;i++)
		{
			if(a[i]<0&&arr[i]>0&&arr[i]<=k)
			v.push_back(make_pair(-a[i],arr[i]));
		}
		/*for(i=0;i<v.size();i++)
		printf("%d ",v[i].first);
		printf("\n");
		for(i=0;i<v.size();i++)
		printf("%d ",v[i].second);*/
		
		n=v.size();
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				if(i==0||j==0)
				dp[i][j]=0;
				else if(v[i-1].second<=j)
				dp[i][j]=max(v[i-1].first+dp[i-1][j-v[i-1].second],dp[i-1][j]);
				else
				dp[i][j]=dp[i-1][j];
			}
		}
		printf("%lld\n",dp[n][k]);
		/*dp[0][0]=a[0];
		for(i=1;i<n;i++)
		dp[i][0]=dp[i-1][0]+a[i];
		for(i=1;i<k+1;i++)
		if(i>=arr[0]&&a[0]<0)
		dp[0][i]=0;
		else
		dp[0][i]=a[0];
		for(i=1;i<n;i++)
		for(j=1;j<k+1;j++)
		{
			ll x=INT_MIN;
			if(arr[i]<=j)
			x=dp[i-1][j-arr[i]];
			dp[i][j]=max(a[i]+dp[i-1][j],x);
		}
		printf("%lld\n",dp[n-1][k]);*/
	}
	return 0;
}

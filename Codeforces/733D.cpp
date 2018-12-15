#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 200000+5
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
map<pair<int,int>,pair<int,int> > m;
typeof(m.begin()) it;
int main()
{
	int n,a,b,c,arr[3],an[2]={0},ans=0,k=0,p;
	sc(n);
	rep(i,1,n+1)
	{
		sc(arr[0]); sc(arr[1]); sc(arr[2]);
		sort(arr,arr+3);
		a=arr[0]; b=arr[1]; c=arr[2];
		//printf("%d %d %d\n",a,b,c);
		if(k<a)
			k=a,p=i;
		it=m.find(mp(a,b));
		if(it!=m.end())
		{
			if(ans<min(a,min(b,c+it->second.first)) && it->second.second!=i)
			{
				an[0]=i, an[1]=it->second.second, ans=min(a,min(b,c+it->second.first));
				//printf("afdafaa");
			}
		}

		it=m.find(mp(a,c));
		if(it!=m.end())
		{
			if(ans<min(a,min(c,b+it->second.first)) && it->second.second!=i)
			{
				an[0]=i, an[1]=it->second.second, ans=min(a,min(c,b+it->second.first));
				//printf("afdafaa");
			}
		}
		
		it=m.find(mp(b,c));
		if(it!=m.end())
		{
			if(ans<min(b,min(c,a+it->second.first)) && it->second.second!=i)
			{
				an[0]=i, an[1]=it->second.second, ans=min(b,min(c,a+it->second.first));
				//printf("afdafaa");
			}
		}


		it=m.find(mp(a,b));
		if(it!=m.end())
		{
			if(it->second.first>c)
			{
				m.erase(it);
				m.insert(mp(mp(a,b),mp(c,i)));
			}
		}
		else
			m.insert(mp(mp(a,b),mp(c,i)));

		it=m.find(mp(a,c));
		if(it!=m.end())
		{
			if(it->second.first>b)
			{
				m.erase(it);
				m.insert(mp(mp(a,c),mp(b,i)));
			}
		}
		else
			m.insert(mp(mp(a,c),mp(b,i)));

		it=m.find(mp(b,c));
		if(it!=m.end())
		{
			if(it->second.first>a)
			{
				m.erase(it);
				m.insert(mp(mp(b,c),mp(a,i)));
			}
		}
		else
			m.insert(mp(mp(b,c),mp(a,i)));


	}
	if(an[0]==0 && an[1]==0 || ans<=k)
		printf("1\n%d",p);
	else if(an[0]==an[1])
		printf("1\n%d",an[0]);
	else
		printf("2\n%d\n%d",an[0],an[1]);
	return 0;
}
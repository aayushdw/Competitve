#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define MAX 6426330
#define L 1000000
#define LIM L/(7*9*13*19*31)
using namespace std;
bitset<MAX> t;
ll primes[440100],num[LIM+100]={0},ct;
void seive()
{
	t.reset();
	t[0]=true; t[1]=true; t[2]=false;
	
	ll i=2,j;
	while(i*i<MAX)
	{
		if(t[i])
		{
			i++;
			continue;
		}
		j=i;
		while(j*i<MAX)
		{
			t[i*j]=1;
			j++;
		}
		i++;
	}
	
	j=0;
	
	for(i=2;i<MAX;i++)
	if(!t[i])
	primes[j++]=i;
	//j++;
	//printf("%lld",j);
	
	ct=j;
	return;
}
int main()
{
	seive();
	ll p,c,n;
	vector<ll> p1,p2;
	rep(i,0,ct)
	{
		p=primes[i];
		if(p%3==1)
		p1.pb(p);
		else
		p2.pb(p);
	}
	printf("%lld %lld %lld",p1.size(),p2.size(),ct);
	
	set<ll> s;
	typeof(s.begin()) it;
	c=0;
	while(p1[c]<=LIM)
	{
		p=p1[c++]; n=p;
		s.insert(p);
		while(n<=LIM)
		{
			for(it=s.begin(); it!=s.end() && (*it)*n<=LIM; it++)
			s.insert((*it)*n);
			n*=p;
		}
	}
	printf("\n%lld\n",s.size());
	it=s.begin();
	
	for(it=s.begin();it!=s.end();it++)
	{
		num[*it]=1;
		//printf("%lld\n",*it);
	}
	
	typeof(p1.begin()) iter=p1.begin();
	iter++;
	p1.insert(iter,9);
	
	c=0;
	unsigned ll sum=0;
	rep(i1,0,p1.size())
	{
		if(p1[i1]*p1[i1+1]*p1[i1+2]*p1[i1+3]*p1[i1+4]>L) break;
		bool f1=false;
		rep(i2,i1+1,p1.size())
		{
			if(p1[i1]*p1[i2]*p1[i2+1]*p1[i2+2]*p2[i2+3]>L) break;
			f1=true;
			bool f2=false;
			rep(i3,i2+1,p1.size())
			{
				if(p1[i1]*p1[i2]*p1[i3]*p1[i3+1]*p1[i3+2]>L) break;
				f2=true;
				bool f3=false;
				rep(i4,i3+1,p1.size())
				{
					if(p1[i1]*p1[i2]*p1[i3]*p1[i4]*p1[i4+1]>L) break;
					f3=true;
					bool f4=false;
					rep(i5,i4+1,p1.size())
					{
						if(p1[i1]*p1[i2]*p1[i3]*p1[i4]*p1[i5]>L) break;
						f4=true;
						p=p1[i1]*p1[i2]*p1[i3]*p1[i4]*p1[i5];
						rep(i,1,L/p+1)
						{
							if(!num[i])
							sum+=p*i,c++,printf("%lld\n",p*i);
						}
					}
				}
			}
			if(!f2) break;
		}
		if(!f1) break;
	}
	printf("\ncount=%lld sum=%llu",c,sum);
}

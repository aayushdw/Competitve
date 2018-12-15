#include<stdio.h>
#include<vector>
#include<bitset>
#include<stdlib.h>
#define ll long long int
#define MAX 10000000
using namespace std;
bitset<MAX> t;
ll primes[3785100],count;
void seive()
{
	t[0]=t[1]=1;
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
	count=j;
	return;
}

int main()
{
	seive();
	printf("SEIVE\n");
	ll n,count=0,*a,i,j,p,u,c;
	vector<ll> v;
	vector<ll> prev,curr,next;
	for(n=1;n<4;n++)
	{
		for(i=2+3*(n-2)*(n-1),j=0;j<6*(n-1);i++,j++)
		prev.push_back(i);
		for(i=2+3*n*(n-1),j=0;j<6*n;i++,j++)
		curr.push_back(i);
		for(i=2+3*n*(n+1),j=0;j<6*(n+1);i++,j++)
		next.push_back(i);
		p=0; u=1;
		for(c=0;c<6*n;c++)
		{
			if(c==0)
			{
				v.push_back(curr[1]);
				v.push_back(curr[6*n-1]);
				v.push_back(next[0]);
				v.push_back(next[1]);
				v.push_back((next[next.size()-1]));
				v.push_back(prev[0]);
				printf("%lld = ",c);
				for(j=0;j<6;j++)
				printf("%lld ",v[i]);
				printf("\n");
				v.clear();
			}
			else if(c==6*n-1)
			{
				v.push_back(curr[0]);
				v.push_back(curr[6*n-2]);
				v.push_back(prev[0]);
				v.push_back(prev[prev.size()-1]);
				v.push_back(next[u+1]);
				v.push_back(next[u+2]);
				printf("%lld = ",c);
				for(j=0;j<6;j++)
				printf("%lld ",v[i]);
				printf("\n");
				v.clear();
			}
			if(c%n==0)
			{
				v.push_back(curr[c+1]);
				v.push_back(curr[c-1]);
				v.push_back(prev[p]);
				v.push_back(next[u]);
				v.push_back(next[u+1]);
				v.push_back(next[u+2]);
				u+=2;
				printf("%lld = ",c);
				for(j=0;j<6;j++)
				printf("%lld ",v[i]);
				printf("\n");
				v.clear();
			}
			else
			{
				v.push_back(curr[c+1]);
				v.push_back(curr[c-1]);
				v.push_back(prev[p]);
				v.push_back(prev[p+1]);
				v.push_back(next[u]);
				v.push_back(next[u+1]);
				p++; u++;
				printf("%lld = ",c);
				for(j=0;j<6;j++)
				printf("%lld ",v[i]);
				printf("\n");
				v.clear();
			}
		}
	}
}














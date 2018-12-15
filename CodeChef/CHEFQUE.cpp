#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<set>
#include<vector>
#include<limits.h>
#include<algorithm>
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define MOD 4294967296
#define DIV 100000
#define LIM MOD/DIV
using namespace std;
int main()
{
	set<int> v[LIM+1];
	ll q,s,a,b,i,j,sum=0;
	int p,x,y;
	sc(q); sc(s); sc(a); sc(b);
	while(q--)
	{
		p=s/2;
		x=p/DIV;
		y=p%DIV;
		if(s%2)
		v[x].insert(y);
		else
		v[x].erase(y);
		s=(a*s+b)%MOD;
	}
	ll r = 0; 
	for(i=0;i<LIM+1;i++)
	for(set<int>::const_iterator it = v[i].begin(); it != v[i].end(); it++)
   	r += *it+DIV*i; 
	 prll(r);
}

#include<stdio.h>
#include<stack>
#define ll long long int
#define sz 10000
ll a[sz]={290797};
using namespace std;
void span(ll price[],ll n,ll s[])
{
	stack<ll> st;
	st.push(0);
	s[0]=0;
	for(ll i=1;i<n;i++)
	{
		while(!st.empty()&&price[st.top()]>=price[i])
		st.pop();
		s[i]=(st.empty())?(i):(i-st.top()-1);
		st.push(i);
	}
}
int main()
{
	ll p=290797,m=50515093,i;
	for(i=1;i<sz;i++)
	a[i]=(a[i-1]*a[i-1])%m;
	//return 0;
	for(i=1;i<sz;i++)
	if(a[i]==p)
	printf("%lld\n",i);
}

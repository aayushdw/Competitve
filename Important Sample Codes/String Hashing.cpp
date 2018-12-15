/*
Tutorial at:
https://tp-iiita.quora.com/String-Hashing
*/
#include<stdio.h>
#include<string>
#define ll long long int
#define sc(x) scanf("%I64d",&x)
#define MAX 10000
using namespace std;
//B is generator modulo M
const long long B = 100000007; 
// hash(S): S -> x, x is integer and belongs to [0, M-1]
const long long M = 1000000009; 
ll power(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
// inverse of B w.r.t. modulo M
const long long invB = power(B, M-2, M);

//powers of and inverse modulo powers of B
ll pB[MAX]={1},invpB[MAX]={1};
void pre()
{
	int i;
	for(i=1;i<MAX;i++)
	{
		pB[i]=(pB[i-1]*B)%M;
		invpB[i]=(invpB[i-1]*invB)%M;
	}
	return;
}


// Hash and Reverse Hashes of prefixes and suffixes
// A string is a palindrome if both forward and reverse hashes are same (High Probability) ;)
void init(const string s, ll h[], ll rh[], ll n)
{
	int i;
	h[0]=s[0]-'a'; rh[n-1]=s[n-1]-'a';
	for(i=1;i<n;i++)
	h[i]=(h[i-1]+((s[i]-'a')*pB[i])%M)%M;
	for(i=n-2;i>=0;i--)
	rh[i]=(rh[i+1]+((s[i]-'a')*pB[n-i-1])%M)%M;
	return;
}

//Hash of S[i...j]
ll getSubHash(int i, int j, ll h[])
{
	ll jh=h[j];
	ll ih= (i>0)?h[i-1]:0;
	ll subHash=((jh+M-ih)*invpB[i])%M;
	return subHash;
}

//Reverse hash of S[i...j]
ll getSubRevHash(int i, int j, ll rh[])
{
	ll ih=rh[i];
}


//modular inverse of n
ll modInv(ll n,ll M)
{
	return power(n,M-2,M);
}

//calculate the hash of string S 
ll getHash(const string s)
{
	ll h = 0; // hash of the string
	int length = s.size();
	for (int i = length-1; i >= 0; i--) {
		h *= B;
		h += (s[i] - 'a');
		h %= M;
	}
	return h;
}

//hash of string concat(s1,s2)
//Complexity= O(1)
ll concatHash(const string s1, ll h1, const string s2, ll h2)
{
	int n=s1.size();
	ll p=(power(B,n,M)*h2)%M;
	p+=h1;
	return p%M;
}

//check if s2 is a substring of s1
//Complexity= O(strlen(s1))
bool isSubstr(const string s1, const string s2,ll h)
{
	int n=s1.size(),m=s2.size(),i,j;
	ll g=getHash(s1.substr(0,m)),p=power(B,m-1,M);
	if(g==h)
	return true;
	else
	for(i=m,j=0;i<n;i++,j++)
	{
		g+=(M-(s1[j]-'a'));
		g=(g*invB)%M;
		g+=(s1[i]-'a')*p;
		g%=M;
		if(g==h)
		return true;
	}
	return false;
}
int main()
{
	ll a,b;
	sc(a); sc(b);
	a=modInv(a,M);
	//printf("%")
	a*=a;
	a%=M;
	a*=a;
	a%=M;
	printf("%I64d\n%I64d",a,modInv(b,M));
	return 0;
}

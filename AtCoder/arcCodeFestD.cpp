#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n,m,k;
char p[]="RGBY";
int op[2333][2333];
void sett(int x,int y,int c)
{
	if(x>=1&&x<=n&&y>=1&&y<=m) op[x][y]=c;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(k&1)
	{
	for(int i=0;i<n;++i,puts(""))
		for(int j=0;j<m;++j)
			putchar(p[(i+j)&1]);
	return 0;
	}
	if(k==2)
	{
	k=k/2;
	for(int i=0;i<n;++i,puts(""))
		for(int j=0;j<m;++j)
		{
			int fj=j%4;
			putchar(p[(((i/k)%2+(i/k)/2%2)%2*2+fj)%4]);
		}
	return 0;
	}
	int hk=k/2;
	int l=1; int h=k-1;
	for(int i=-h-h,j=0;i<=n+k;i+=k/2,++j)
	{
		int pl=(j&1)?(-k/2):0;
		int p=j%2*2+j/2%2;
		for(int s=pl;s<=m;s+=k)
		{
			p^=1;
			for(int r=-k/2+1;r<=k/2-1;++r)
			{
				int w=k-abs(r)*2,b=abs(r)+s;
				for(int ss=b;ss<=b+w-1;++ss)
					sett(i+r,ss,p);
			}
		}
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=m;++j)
			putchar(p[op[i][j]]);
}
#include<bits/stdc++.h>
typedef unsigned char uchar;
typedef long long ll;
typedef unsigned long long ull;
#define MAXP 15711000
char s[MAXP];
void creat() {
  int i,j,q;
  memset(s,1,sizeof(s));
  q=sqrt(MAXP);
  for(s[0]=s[1]=0,i=2;i<=q;i++) if(s[i])
    for(j=i*i;j<MAXP;j+=i) s[j]=0;
}
char lo[256];
void init() {
  int i;
  lo[0]=-1;
  lo[1]=0;
  for(i=2;i<256;i++) lo[i]=1+lo[i>>1];
}
#define LOG2_32(n,r,t,tt) if((tt=n>>16)) r=(t=tt>>8)?24+lo[t]:\
  16+lo[tt]; else r=(t=n>>8)?8+lo[t]:lo[n];
int powmod(int n,int k,int mod) {
  int i,j;
  int v=n,ans=1,t,tt;
  if(!k) return 1;
  LOG2_32(k,i,t,tt)
  for(j=0;j<=i;j++) {
    if(k&(1<<j)) ans=(ull)ans*v%mod;
    v=(ull)v*v%mod;
  }
  return ans;
}
int intpowmod(int n,int k,int mod) {
  int i,j;
  int v=n,ans=1,t,tt;
  if(!k) return 1;
  LOG2_32(k,i,t,tt)
  for(j=0;j<=i;j++) {
    if(k&(1<<j)) ans=ans*v%mod;
    v=v*v%mod;
  }
  return ans;
}
int jacobi(int a,int m) {
  int t=1,z;
  a%=m;
  while(a) {
    while(!(a&1)) {
      a>>=1;
      if((m&7)==3 || (m&7)==5) t=-t;
    }
    z=a,a=m,m=z;
    if((a&3)==3 && (m&3)==3) t=-t;
    a%=m;
  }
  if(m==1) return t;
  return 0;
}
int intsqrtmod(int a,int p) {
  int p8,alpha,i,c,s,n,b,J,r2a,r;
  p8=p&7;
  if(p8==7) return intpowmod(a,(p+1)/4,p);
  alpha=0;
  s=p-1;
  while(!(s&1)) s>>=1,alpha++;
  r=intpowmod(a,(s+1)/2,p);
  r2a=r*intpowmod(a,(s+1)/2-1,p)%p;
  for(n=3;jacobi(n,p)!=-1;n+=2);
  b=intpowmod(n,s,p);
  J=0;
  for(i=0;i<alpha-1;i++) {
    c=intpowmod(b,2*J,p);
    c=r2a*c%p;
    c=intpowmod(c,1ULL<<(alpha-i-2),p);
    if(c==p-1) J+=1ULL<<i;
  }
  return r*intpowmod(b,J,p)%p;
}
int sqrtmod(int a,int p) {
  int p8,alpha,i,c,s,n,b,J,r2a,r;
  p8=p&7;
  if(p8==7) return powmod(a,(p+1)/4,p);
  alpha=0;
  s=p-1;
  while(!(s&1)) s>>=1,alpha++;
  r=powmod(a,(s+1)/2,p);
  r2a=(ll)r*powmod(a,(s+1)/2-1,p)%p;
  for(n=3;jacobi(n,p)!=-1;n+=2);
  b=powmod(n,s,p);
  J=0;
  for(i=0;i<alpha-1;i++) {
    c=powmod(b,2*J,p);
    c=(ll)r2a*c%p;
    c=powmod(c,1ULL<<(alpha-i-2),p);
    if(c==p-1) J+=1ULL<<i;
  }
  return (ll)r*powmod(b,J,p)%p;
}
#define MAXQ 10000000
char qsieve[MAXQ+1];
#define CROSS 7
void solve() {
  int r,p,start;
  memset(qsieve,1,MAXQ+1);
  #pragma omp parallel for private(start,r)
  for(p=CROSS;p<MAXP;p+=2) if(((p&7)==1 || (p&7)==7) && s[p]) {
    if(p<46340) r=intsqrtmod((p+1)/2,p);
    else r=sqrtmod((p+1)/2,p);
    for(start=r;start<=MAXQ;start+=p) qsieve[start]=0;
    for(start=-r+p;start<=MAXQ;start+=p) qsieve[start]=0;
  }
}
int ans[MAXQ+5]={0};
void answer() {
  int i;
  for(i=2;2*i*i-1<MAXP;i++) if(s[2*i*i-1]) ans[i]=1;
  for(;i<=MAXQ;i++) if(qsieve[i]) ans[i]=1;
  for(i=2;i<=MAXQ;i++)
  ans[i]=ans[i]+ans[i-1];
}
int main() {
  init();
  creat();
  solve();
  answer();
  int t,p;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d",&p);
      printf("%d\n",ans[p-1]);
  }
  return 0;
}
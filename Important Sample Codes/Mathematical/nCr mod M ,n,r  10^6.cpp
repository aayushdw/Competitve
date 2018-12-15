//n,r<=10^6, MOD is prime
ll fact[MAX],inverse[MAX],fact_inverse[MAX];
inline void precalc()
{
	fact[0]=1;
	
	inverse[0]=1;inverse[1]=1;
	
	fact_inverse[0]=1;fact_inverse[1]=1;
	
	for(ll i=1;i<MAX;i++)
		fact[i]=(i*fact[i-1])%MOD;
		
	for(ll i=2;i<MAX;i++)
	{
		inverse[i]=(MOD-((MOD/i) * inverse[MOD % i])%MOD)%MOD;
		fact_inverse[i]=(inverse[i]*fact_inverse[i-1])%MOD;
	}
}
 
inline ll choose(ll n,ll r)
{
	return (fact[n]*((fact_inverse[r]*fact_inverse[n-r])%MOD))%MOD;
}

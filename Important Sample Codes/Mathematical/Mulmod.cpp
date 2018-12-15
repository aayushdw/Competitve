ll mulmod(ll x, ll y, ll m) {
    ll w=x*y-m*(ll(double(x)*y/m+1e-3));
	while(w<0)
		w+=m;
	while(w>=m)
		w-=m;
	return w;
}

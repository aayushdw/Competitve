import math
def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
n=30
num=0
s=0
for q in range(0,n):
    p=n-1-q;
    for i in range(0,p/2+1):
        a=p-2*i
        if(a+i>q+2):
            continue;
        s+= (q+1)*nCr(q+2,a+i)*math.factorial(a+i)/(math.factorial(a)*math.factorial(i))
print s
num=s
s=0
for p in range(0,n):
    q=n-p;
    for i in range(0,p/2+1):
        a=p-2*i
        if(a+i>q+1):
            continue;
        s+= nCr(q+1,a+i)*math.factorial(a+i)/(math.factorial(a)*math.factorial(i))
num+=s;
print s
print num

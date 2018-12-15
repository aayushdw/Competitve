import math
f=math.factorial
def C(n,r):
    return f(n)/f(r)/f(n-r)
n=2
s=0
for i in range(1,n+1):
    s+=C(i+8,8)+C(i+9,9)-10
print s*1.0/(10**n-2)

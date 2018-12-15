import math
f=math.factorial
def C(n,r):
    return f(n)/f(r)/f(n-r)
s=0
for i in range(1,15):
    p=i*i//10
    for j in range(0,p):
        s+=((-1)**p)*C(i*i-10*p+19,19)*C(20,p)
print (s)

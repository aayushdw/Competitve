import math
f=math.factorial
k=f(1000)
while(k%10==0):
    k/=10
print k%100000

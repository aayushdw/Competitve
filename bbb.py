def computePrices(s, p, q):
    def binarySearch(arr, x): 
        l = 0
        r = len(arr) - 1
        while l+1 < r: 
            mid = l + (r - l)//2; 
            print(mid);
            if arr[mid] > x: 
                r = mid - 1
            else: 
                l = mid
        if( arr[r] <= x ):
            return r
        else:
            return l
            
    f = []
    # Write your code here
    z = sorted(zip(s,p))
    s =[x[0] for x in z]
    p = [x[1] for x in z]
    for x in q:
        ind = binarySearch(s,x)
        f.append(p[ind])
    print(f)
    return f

n = int(input().strip())

s = list(map(int, input().rstrip().split()))

p = list(map(int, input().rstrip().split()))

k = int(input().strip())

q = []

for _ in range(k):
    q_item = int(input().strip())
    q.append(q_item)

res = computePrices(s, p, q)
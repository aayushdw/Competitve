arr=[]
arr.append(1);
arr.append(1);
for i in range(2,50):
    arr.append(arr[i-1]+arr[i-2])
for i in range(1,20):
    print arr[2*i-1]*arr[2*i]

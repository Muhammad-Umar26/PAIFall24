import numpy as np

arr1 = np.arange(1,16)
a = arr1.reshape(5,3)

arr2 = np.arange(1,7)
b = arr2.reshape(3,2)

def mul(x,y):
    return x*y

mymul = np.frompyfunc(mul,2,1)

c = mymul(a,b)

print(a,'\n')
print(b,'\n')
print(c,'\n') # error, cannot multiply due to  size

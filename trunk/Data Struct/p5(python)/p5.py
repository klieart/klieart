# Binary Search 
# by Arturo Klie

import time

# Binary() performs a single comparison iterative binary search
# B is the array passed by reference   
# N is the size of the ordered array
# x is the value to be searched in the array
def binary(B,N,x):
   low = 0
   mid = 0
   high = N
   while low < high:
       mid = low + ((high-low)/2)
       if B[mid] < x:
           low = mid + 1
       else:
           # can't be high = mid-1: here A[mid] >= value,
           # so high can't be < mid if A[mid] == value
           high = mid

   # high == low, using high or low depends on taste 
   if ((low < N) and (B[low] == x)):
       return low # found
   else:
       return -1 # not found

# Start of main script
print "Running..."
A = [128, 512, 2048, 8192, 32768, 131072, 524288]
for i in A:
    # Initialize and fill test array.
    B = [0]*i
    for c in range(len(B)):
       B[c] = c+1
       
    # Start Timer 
    t0 = time.clock()

    # Perform 10 million unsuccessful binary searches.
    j = 0;
    while j < 10000000:
       binary(B, i, 0) # 0 results in unsuccessful searches
       j += 1
    
    # Stop Timer
    tt = time.clock()

    print "-------------------------"
    print "Array Size: %s" % (i,)
    print "Run time:   %s" % (tt - t0,) + " sec"
    print "-------------------------"
print "Done"
# End of main script

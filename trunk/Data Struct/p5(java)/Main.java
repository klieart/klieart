// Binary Search 
// by Arturo Klie

public class Main 
{
   public static void main(String[] args)
   {   
	   System.out.println("Running...");
	   
	   Main m = new Main();
	   
	   int[] A = {128, 512, 2048, 8192, 32768, 131072, 524288};
	   for (int i=0; i<A.length; i++)
	   {
		   // Initialize and fill test array.
		   int[] B = new int[A[i]];
		   m.fill(B, A[i]);
		   
		   // Start Timer 
		   long startTime = System.currentTimeMillis(); 
		   
		   // Perform 10 million unsuccessful binary searches.
		   for (int j=0; j<10000000; j++)
			   m.binary(B, A[i], 0); // 0 results in unsuccessful searches
		   
		   // Stop Timer
		   long stopTime = System.currentTimeMillis();
		   
		   System.out.println("-------------------------");
		   System.out.println("Array Size: " + A[i]);
		   System.out.println("Run time:   " + (stopTime - startTime) + " ms");
		   System.out.println("-------------------------");
	   }
	   System.out.println("Done");
    }
   
   // Fill() fills an array with ascending numbers from 1 to N
   // B is the array passed by reference   
   // N is the size of the ordered array
   public void fill(int [] B, int N)
   {
	   int c = 1;
	   for (int x=0;x<N;x++)
	   {
		   B[x] = c;
		   c++;
	   }
	   
   }
   
   // Binary() performs a single comparison iterative binary search
   // B is the array passed by reference   
   // N is the size of the ordered array
   // x is the value to be searched in the array
   public int binary(int [] B, int N, int x)
   {
	   int low = 0;  // Lower bound
       int mid = 0;  // Mid point
       int high = N; //Higher bound
       
       while (low < high) 
       {
    	   mid = low + ((high-low)/2);
    	   if (B[mid] < x)
    		   low = mid + 1;
    	   else
    		   //can't be high = mid-1: here A[mid] >= value,
               //so high can't be < mid if A[mid] == value
               high = mid; 
       }
       // high == low, using high or low depends on taste 
       if ((low < N) && (B[low] == x))
           return low; // found
       else
           return -1; // not found
   }
}

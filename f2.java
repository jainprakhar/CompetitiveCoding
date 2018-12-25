import java.util.*;
import java.lang.*;

public class Test{
    
    // generate primes
    public static void sieve(boolean isprime[]){
       int n = isprime.length;
       isprime[0] = isprime[1] = false;
       for (int p = 2; p < n/2 + 1; ++p)
          if(isprime[p])
             for(int x = p*p; x < n; x+=p)
                isprime[x] = false;
    }
    
    public static void main(String args[]){
        
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int k = s.nextInt();
        
        boolean isprime[] = new boolean[1001];
        for (int i = 0; i < 1001; ++i)
            isprime[i] = true;
         
        sieve(isprime);
        
        int ans[] = new int[1001];
        for (int i = 0; i< 1001; ++i)
            ans[i] = 10000;
            
        int pidx = 10000;
        for (int i = 1000; i > 0; --i){
            if (isprime[i]){
                pidx = i;
            }else{
                ans[i] = pidx - i;
            }
        }
    
        int array[] = new int[n];
        
        int pr = 0;
        for (int i = 0; i < n; ++i){
            array[i] = s.nextInt();
            if (isprime[array[i]])
                ++pr;
        }
    
       int dist[] = new int[1001];
        for (int i = 0; i< 1001; ++i)
            dist[i] = 10000;
            
        if (pr == k)
            System.out.println(0);
        else{
            int req = k - pr;
            for (int i = 0; i < n; ++i){
                if (isprime[array[i]] == false){
                    dist[i] = ans[array[i]];
                }
            }
            
            Arrays.sort(dist);
            int a = 0;
            for (int i = 0; i < req; ++i)
                a += dist[i];
            System.out.println(a);
        }
    }
}
class Solution {
public:
    int countPrimes(int n) {
        //dynamic allocating memory
        bool *isPrime;
        isPrime = new bool[n];
        //intialization
        for(int i=0; i<n; i++){
            isPrime[i] = true;
        }
        //processing 
        for(int i=2; i*i < n; i++)
        {
            if(!isPrime[i]) continue;
            for(int j=i*i; j < n; j+=i){
                isPrime[j] = false;
            }
        }
        
        //Counting
        int count = 0;
        for(int i=2; i<n; i++){
            if(isPrime[i]) count++;
        }
        
        return count;
    }
};
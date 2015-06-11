class Solution {
private:
    int *getPrimes(int n){
        int *primes;
        primes = new int[n];
        for(int count=0,k=2;count<n;k++){
            //if k is prime
            bool isprime = true;
            for(int j = 2; j*j<=k;j++)
            {
                if ( k % j == 0) isprime = false; 
            }
            if(isprime)
            {
                primes[count] = k;
                count++;
            }
            
        }
        return primes;
    }
	size_t hashValue(string str) {
	   // sort(str.begin(), str.end());
	   // int power = 1;
	   // size_t result = 0;
	   // for (char c : str) {
	   //     result += (c - 'a' + 1)  * power;
	   //     power *= 26;
	   // }
        size_t result= 1;
        int *primes = getPrimes(26);
        for (char c: str){
            result *= primes[c-'a'];
        }
        return result;
	}
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> res;
        unordered_map<size_t,vector<string> > mp;
        
        for(string str: strs){
            size_t value = hashValue(str);
            mp[value].push_back(str);
        }
        
        for(auto it = mp.begin();it!=mp.end(); it++){
            if(it->second.size() >= 2){
                for(string s: it->second){
                    res.push_back(s);
                }
            }
        }
        
        return res;
    }
};
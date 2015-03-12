class Solution {
private:
    int factorial(int n)
    {
        if(n==1) return 1;
        return n*factorial(n-1);
    }
public:
    string getPermutation(int n, int k) {
        int index = k-1;
        string res = "";
        vector<int> v;
        
        for(int i=0;i<n;i++) v.push_back(i+1);
        
        if(n==1){ if(k==1) return "1"; else return res;}
        
        for(int i=0;i<n-1;i++)
        {
            int t = factorial(n-i-1);
            int j = index/t;
            index = index%t;
            
            res += std::to_string(v[j]);
            v.erase(v.begin()+j);
        }
        
        res+=std::to_string(v[0]);
        return res;
    }
};
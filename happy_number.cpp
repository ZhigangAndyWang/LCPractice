class Solution {
private:
    int calculate(int n){
        int res = 0;
        while(n != 0){
            int lastDigit = n%10;
            res += pow(lastDigit,2);
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> used;
        if(n==1) return true;
        
        used.insert(n);
        
        while(n!=1){
            int tmp = calculate(n);
            if(used.find(tmp) != used.end()){
                return false;
            }
            else{
                used.insert(tmp);
            }
            n = tmp;
        }
        return true;
    }
};
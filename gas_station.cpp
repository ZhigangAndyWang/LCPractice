class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0, sumCost = 0;
        for(int i = 0; i<gas.size(); ++i){
            sumGas += gas[i];
            sumCost += cost[i];
        }
        if ( sumGas < sumCost ) return -1; //no solution
        
        int start = 0;
        int n = gas.size();
        int curSum = 0;
        
        for (int k = 0; k<n; k++){
            curSum += gas[k]-cost[k];    
            if(curSum < 0){
                start = k+1;
                curSum = 0;
            }
        }
        return start;
    }
};
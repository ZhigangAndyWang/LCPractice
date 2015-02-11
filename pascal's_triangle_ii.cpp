class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> res;
        vector<int> lastP;
        if(rowIndex < 1) return res;
        res.push_back(1);
        for(int i=2;i<=rowIndex;i++)
        {
            lastP = res;
            for(int j=1;j<i-1;j++)
            {
                res[j] = lastP[j-1]+lastP[j]; 
            }
            res.push_back(1);
        }
        return res;
    }
};
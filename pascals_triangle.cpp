class Solution {
public:
    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int>> res;
        vector<int> cVector;
        for(int i=1;i<=numRows;i++)
        {
            if(i==1)
            {
                cVector.push_back(1);
            }
            else
            {
                int size = cVector.size();
                vector<int> tVector;
                tVector=cVector;
                for(int j=1;j<size;j++)
                {
                    cVector[j] = tVector[j] + tVector[j-1];
                    
                }
                cVector.push_back(1);
            }
            res.push_back(cVector);
        }
        
        
        return res;
        
    }
};
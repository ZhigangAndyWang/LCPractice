class Solution {
    unordered_set<int> findset;
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int > > res;
        
        if(num.size()<3) return res;
        
        sort(num.begin(),num.end());
        
        int n = num.size();
        for(int i=0;i<n;i++) findset.insert(num[i]);
        
        for(int i=0;i<n-2;i++)
        {
            if(num[i]>0) break;
            int sum = 0-num[i];
            if(i==0 || num[i]!=num[i-1])
            {
                for(int j=i+1;j<n-1;j++)
                {
                    if(j==i+1 || num[j]!=num[j-1])
                    {
                        for(int k=j+1;k<n;k++)
                        {
                            if(k==j+1||num[k]!=num[k-1])
                            {
                                if(num[j]+num[k]==sum)
                                {
                                    vector<int> temp;
                                    temp.push_back(num[i]);temp.push_back(num[j]);temp.push_back(num[k]);
                                    res.push_back(temp);
                                }
                            }
                        }
                    }
                
                }
            }
        }
        return res;
    }
};
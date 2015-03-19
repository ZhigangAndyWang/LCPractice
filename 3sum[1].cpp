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
                int j = i+1, k = n-1;
                while(j<k)
                {
                    if(num[j]+num[k]==sum)
                    {
                        vector<int > temp;
                        temp.push_back(num[i]);temp.push_back(num[j]);temp.push_back(num[k]);
                        res.push_back(temp);
                        while(num[j]==num[j+1]) j++; 
                        while(num[k]==num[k-1]) k--;
                        j++;k--;
                    }
                    else if(num[j]+num[k]<sum) j++;
                    else k--;
                }
            }
        }
        return res;
    }
};
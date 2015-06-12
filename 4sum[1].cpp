class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        multimap<int,pair<int,int> > mp;
        // multimap<int,pair<int,int> > ::iterator mit,mit2;
        set<vector<int> > mset;
        vector<int> res_m(4);
        
        //get all pair sums
        for(int i=0; i<nums.size()-1;i++){
            for(int j=i+1; j<nums.size();j++){
                mp.insert(make_pair(nums[i]+nums[j], make_pair(i,j)) );
            }
        }
        
        //Use a multi map to find the results
        for(auto mit = mp.begin();mit!= mp.end();mit++){
            int leftSum = target - mit->first;
            if(mp.find(leftSum) != mp.end()){   // if the target-current value exists in the map
                //handling the same key multi-value case
                    //pair <multimap<int,pair<int,int> >::iterator, multimap<int,pair<int,int> >::iterator> ret;
                auto ret = mp.equal_range(leftSum);
                //for all the values in the same key
                for(auto mit2 = ret.first; mit2!=ret.second; ++mit2){
                    //check if duplicates exist in the two pairs 
                    if( mit->second.first != mit2->second.first && mit->second.first != mit2->second.second && 
                        mit->second.second != mit2->second.first && mit->second.second != mit2->second.second){
                        res_m[0]=(nums[mit->second.first]);
                        res_m[1]=(nums[mit->second.second]);
                        res_m[2]=(nums[mit2->second.first]);
                        res_m[3]=(nums[mit2->second.second]);
                        sort(res_m.begin(),res_m.end());
                        mset.insert(res_m);
                    }
                }
            }
        }
        
        for(vector<int > item:mset){    //for(auto &item:mset) res.push_back(item);
            res.push_back(item);
        }
        
        return res;
        
    }
};

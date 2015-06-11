class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<pair<int, int>>> mp;
        set<vector<int> > mset; 
        vector<int> res_m(4);
        
        if(nums.size()<4) return ret;
    
        //get all pair sums        
        for(int i=0; i<nums.size()-1;i++){
            for(int j=i+1; j<nums.size();j++){
                int pairSum = nums[i]+nums[j];
                if(mp.count(pairSum) == 0){
                    mp[pairSum] = {make_pair(i,j)};
                }
                else{
                    mp[pairSum].push_back(make_pair(i,j));
                }
                // mp[pairSum].push_back(make_pair(i,j)) );
            }
        }
        // find the results
        for(auto it = mp.begin();it != mp.end();++it){
            int leftSum = target - it->first;
            if(mp.find(leftSum) != mp.end()){
                vector<pair<int, int> > ary2 = mp[leftSum];
                vector<pair<int, int> > ary1 = it->second;
                for(int i = 0;i<ary2.size();i++){
                    pair<int,int> can2 = ary2[i];
                    if(i==0 || ary2[i].first!=ary2[i-1].first){ //getting rid of a lot duplicated situations!
                        for(pair<int,int> can1:ary1){
                            //check if duplicates exist in the two pairs 
                            if (can1.first!=can2.first && can1.first!=can2.second && 
                                can1.second!=can2.first && can1.second!=can2.first){
                                if (can1.second < can2.first){  //getting rid of a lot duplicated situations!
                                    res_m[0] = nums[can1.first];
                                    res_m[1] = nums[can1.second];
                                    res_m[2] = nums[can2.first];
                                    res_m[3] = nums[can2.second];
                                    sort(res_m.begin(),res_m.end());
                                    mset.insert(res_m);
                                }
                            }
                            
                        }
                    }
                }
                

            }
        }
        for(auto &item:mset){
            ret.push_back(item);
        }
        return ret;
    }
};
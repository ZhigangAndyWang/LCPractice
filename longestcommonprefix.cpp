class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size()==0) return "";
        if (strs.size()==1) return strs.back();
                
        string str1 = strs.back();
        strs.pop_back();
        string str2 = longestCommonPrefix(strs);
                
        int len1 = str1.length();
        int len2 = str2.length();
        
        string res;
        for (int i=0; i<min(len1,len2);i++){
            if(str1[i]==str2[i]) res.push_back(str1[i]);
            else break;
        }
        return res;
    }
};

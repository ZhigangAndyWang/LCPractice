class Solution {
private:
    unordered_map<int,string> map;
    
    void backtracking(int &pos,string &cur,vector<string> &res,string digits)
    {
        if(pos == digits.length())
        {
            res.push_back(cur);
            return;
        }
        else
        {
            string choices = map[digits[pos]-'0'];
            for(int i=0;i<choices.length();i++)
            {
                cur += choices[i];
                pos++;
                backtracking(pos,cur,res,digits);
                pos--;
                cur = cur.substr(0,cur.length()-1);
            }
        }
    }
public:
    Solution()
    {
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if(!digits.length()) return res;
        
        string cur = "";
        int pos = 0;
        backtracking(pos,cur,res,digits);
        return res;
    }
};
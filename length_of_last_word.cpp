class Solution {
public:
    int lengthOfLastWord(const char *s) {
        size_t len= strlen(s)-1;
        int res = 0;
        for(int i = len;i>=0;i--)
        {
            if(s[i]==' ' && res!=0) break;
            else if(s[i]!=' ')
            {
                res++;
            }
        }
        return res;
    }
};
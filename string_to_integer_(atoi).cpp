class Solution {
public:
    int atoi(string str) {
        bool overflow=false;
        int sign=0;
        int result = 0;
        int i = 0;
        while (str[i] == ' '|| str[i]=='\n'  || str[i]=='\t'){
            ++i;
        }
        switch (str[i]){
        case '-':++i; sign=-1; break;
        case '+':++i; sign= 1; break;
        default :sign=1;
        }
        while (str[i] != '\0'){
            if (!isdigit(str[i])) break;
            else{
                if(result > (INT_MAX/10)){
                    overflow=true;
                    break;
                }
                result = result * 10 + (int)(str[i] - '0');
                if(result < 0){
                    overflow=true;
                    break;
                }
                ++i;
            }
        }
        if(overflow){
            if (sign==-1)
                result = INT_MIN;
            else
                result = INT_MAX;
        }
        else 
            result = sign * result;
        return result;
    }
};
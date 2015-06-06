class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            // to avoid divide by zero
            return "";
        } 
        else if (numerator == 0) {
            // to avoid output "-0"
            return "0";
        }
            
        long long num = numerator;// One of the test case is denominator = 0x80000000, thus we must save its opposite
        long long den = denominator; // number in a long long variable.
          
        bool b1 = num < 0;
        bool b2 = den < 0;
        if(b1) num = - num; // We convert both num and den into positive numbers.
        if(b2) den = -den;
        string res = "";
        if(b1^b2) res += "-";
        
        //part1 is the part larger than 1
        string part1 = to_string(num/den);
        
        
        
        if(num % den == 0 ) 
            return res + to_string(num/den);    
            
            
        unordered_map<long long,int> occuredRemain;
        
        long long remain = num%den;
        string part2 = "";
        int pos = 0;
        while(remain){
            auto it = occuredRemain.find(remain);
            
            long long nextDigit = remain*10 / den;
            long long nextRemain = remain*10 % den;

            if(it == occuredRemain.end()){
                occuredRemain[remain] = pos;
                part2 += to_string(nextDigit);
            }
            else{   //found repeated remain
                int pos1 = it->second;
                part2.insert(pos1,"(");
                part2 += ")";
                break;
            }
            pos ++ ;
            remain = nextRemain;
        }
        
        res += part1 + "." + part2;
        return res;
    }
};
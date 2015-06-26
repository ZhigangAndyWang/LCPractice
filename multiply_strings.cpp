class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        
        string sum(n1+n2,'0');
        
        for (int i = n1-1; i >= 0 ; i--){
            int carry = 0;
            for (int j = n2-1; j >= 0 ; j--){
                int tmp = sum[i+j+1] - '0' + (num1[i] - '0')*(num2[j] - '0') + carry;
                sum[i+j+1] = '0' + tmp%10;
                carry = tmp/10;
            }
            sum[i] += carry;    //important
        }
        
        while(sum[0] == '0' && sum.size()>1)
            sum = sum.substr(1);
        return sum;
    }
};
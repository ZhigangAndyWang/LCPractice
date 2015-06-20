class Solution {
private:
    bool isNumber(string str){
        if (!str.size()) return false;
        
        if ( str[0] == '-') 
            return isNumber( str.substr(1) );
            
        for(int i = 0; i < str.size(); i++){
            char c = str[i];
            if ( !isdigit(c) )  {return false;}
        }
        
        return true;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        if (!tokens.size()) return 0;
        
        stack<int> st;
        for (int i = 0; i<tokens.size(); ++i){
            string str = tokens[i];
    
            if (isNumber(str)){
                st.push(std::stoi(str));
            }
            else{
                if ( (str == "+" || str == "-" || str == "*" || str == "/") && st.size() >= 2){
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    
                    if (str == "+"){
                        st.push(a+b);
                    }
                    if (str == "-"){
                        st.push(a-b);
                    }
                    if (str == "*"){
                        st.push(a*b);
                    }
                    if (str == "/"){
                        st.push(a/b);
                    }
                }
            }
        }
        if (st.size() == 1) return st.top();
        else return -1;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stack<string> st;
        
        for(int i = 0; i<path.size()-1 ; ++i){
            if (path[i]=='/' && path[i+1]=='/'){
                path.erase(i,1);
                --i;
            }
        }
        if (path[path.size()-1]!='/') path = path + "/";
         
        int flag = 0;
        string str = "";
        for(int i = 0;i<path.size();i++){
            if(path[i] == '/') flag++;
            if (flag == 1) str += path[i];
            if (flag == 2){
                if ( str == "/.." && !st.empty()){
                    st.pop();
                }
                if( str != "/.." && str != "/."){
                    st.push(str);
                }
                flag = 1;
                str = "/";
            }
        }
        
        if (st.empty()) return "/";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
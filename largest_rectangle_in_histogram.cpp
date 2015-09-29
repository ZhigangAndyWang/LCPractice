class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        if(!n) return 0;
        int maxSize = 0;
        
        height.push_back(0);
        
        stack<int> st;
        
        for(int i = 0; i < height.size() ; ){
            if( st.empty() || height[i] >= height[st.top()] ){
                st.push(i);
                i++;
            }
            else{
                int s = st.top();
                st.pop();
                maxSize = max(maxSize, (st.empty()? i:i-st.top()-1)*height[s]);//consider[2,0,3,2,5]
            }
        }
        return maxSize;
    }
};
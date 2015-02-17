class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int c=1;
        
        if(n==0) return 0;
        
        for(int i=1;i<n;i++)
        {
            if(A[i]!=A[i-1]) A[c++]=A[i];
        }
        
        return c;
    }
};
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;
        int c = 2;
        for(int i=2;i<n;i++)
        {   
            if(A[i]!=A[c-2])
            {
                A[c++] = A[i];
            }
        }
        return c;
    }
};
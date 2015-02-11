class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pa = m-1, pb = n-1;
        for(int i=m+n-1;i>=0;i--)
        {
            int la,lb;
            la = (pa>=0?A[pa]:INT_MIN);
            lb = (pb>=0?B[pb]:INT_MIN);
            if(la>lb)
            {
                A[i] = A[pa--];
            }
            else
            {
                A[i] = B[pb--];
            }
        }
    }
};
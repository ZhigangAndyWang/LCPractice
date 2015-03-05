class Solution {
public:
    bool canJump(int A[], int n) 
    {
        if(n==1&&A[0]==0) return true;
        if(A[0]==0) return false;
        for(int i=0;i<n;i++)
        {
            if(A[i]!=0) continue;
            else    //A[i]==0
            {
                for(int j=0;j<i;j++)
                {
                    if(A[j]>i-j || (i==n-1&&A[j]==i-j)) break;
                    else 
                    {
                        if(j==i-1) return false;
                        continue;
                    }
                }
            }
        }
        return true;
    }
};
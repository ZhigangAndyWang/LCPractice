class Solution {
public:
    void sortColors(int A[], int n) {
        int id[3] = {-1,-1,-1}; //index of 1st occurrence of 0,1,2
        if(n<=1) return;
        
        for(int i=0;i<n;)
        {
            int k = A[i];
            for(int j=k+1;j<3;j++)
            {
                if(id[j]<0) continue;
                if(id[j]>=0)
                {
                    int temp = A[i];
                    A[i] = A[id[j]];
                    A[id[j]] = temp;
                    
                    if(id[temp]<0) id[temp] = id[j];
                    id[j]++;
                    break;
                }
            }
            
            if(i==0 || A[i]>=A[i-1]) 
            {
                if(id[A[i]]<0) id[A[i]]=i;
                i++;
            }
        }
    }
};
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int front=0;
        int end=n-1;
        
        if(n==1) return (target>A[0])?1:0;
        
        if(target<=A[0]) return 0;
        if(target>A[n-1]) return n;
        
        while(end>front)
        {
            if(end-front==1)
            {
                if(A[front]==target) return front;
                if(A[end]==target) return end;
                else return end;
            }
            int mid = (front+end)/2;
            if(A[mid] == target) return mid;
            if(A[mid] > target) {end = mid; continue;}
            if(A[mid] < target) {front = mid; continue;}
        }
    }
};
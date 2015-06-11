class Solution {
private:
    int computeCommonArea(int A, int B, int C, int D, int E, int F, int G, int H){
        if(A == E && B == F && C == G && D == H){
            return (C-A)*(D-B);
        }
        
        if(A != E || C != G){
            if (E >= C && G >= C) return 0;
            if (E <= A && G <= A) return 0;
            return computeCommonArea(max(A,E),B,min(C,G),D,max(A,E),F,min(C,G),H);
        }
        
        if(B != F || D != H){
            if (H >= D && F >= D) return 0;
            if (H <= B && F <= B) return 0;
            return computeCommonArea(A,max(B,F),C,min(D,H),E,max(B,F),G,min(D,H));
        }
        return 0;
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        int commonArea = computeCommonArea(A,B,C,D,E,F,G,H);
        return area1+area2-commonArea;
        
    }
};
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if ( n==0 ) return 0;
        if ( n <= 2 ) return n;
        // if ( n == 2 ) return 1;
        
        int res = 0;
        for(int i = 0; i < n ; i++){
            Point a = points[i];
            unordered_map<double,int> slopes;
            int count = 0;
            int duplicate = 0;
            for(int j = 0; j < n ; j++){
                if(j==i) continue;
                Point b = points[j];
                double k;
                if(b.x == a.x && b.y == a.y) {
                    duplicate++;
                    continue;
                }
                if(b.x == a.x) k = INT_MAX;
                else k = (double)(b.y-a.y)/(b.x-a.x);
                if(slopes.find(k) == slopes.end()){
                    slopes.insert(make_pair(k,1));
                    count = max(count,1);
                }
                else{
                    slopes[k]++;
                    count = max(count,slopes[k]);
                }
            }
            res = max(res,count+duplicate+1);
        }
        return res;
    }
};
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct compareInterval {
        bool operator()(const Interval &a, const Interval &b) const {
            return a.start<b.start;
        }
    };
    
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compareInterval() );
        vector<Interval> res;
        
        for(int i = 0; i<intervals.size(); i++){
            if(res.empty() || res.back().end < intervals[i].start ){
                res.push_back(intervals[i]);
            }
            else{
                res.back().end = std::max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};
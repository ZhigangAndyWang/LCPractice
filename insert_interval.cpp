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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool inserted = false;
        for(int i = 0 ; i < intervals.size(); i++){
            //insert intervals before newInterval
            if(intervals[i].end < newInterval.start){
                res.push_back(intervals[i]);
            }
            //if newInterval and I[i] overlapped, merge them
            if( intervals[i].end >= newInterval.start && intervals[i].start <= newInterval.end){
                newInterval.start = std::min(intervals[i].start, newInterval.start);
                newInterval.end = std::max(intervals[i].end, newInterval.end);
                continue;
            }
            //insert newInterval if no merging needed
            if(intervals[i].start > newInterval.end && !inserted){
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                inserted = true;
                continue;
            }
            
            if(inserted){
                res.push_back(intervals[i]);
                continue;
            }
            
        }
        
        if(!inserted) res.push_back(newInterval);

        return res;
    }
};
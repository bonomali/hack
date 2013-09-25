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
    static bool less (const Interval& interval1, const Interval& interval2){
        if (interval1.start == interval2.start)
            return interval1.end < interval2.end;
        return interval1.start < interval2.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), less);
        vector<Interval> result;
        if (intervals.size() == 0) return result;
        result.push_back(intervals[0]);
        for ( int i = 1; i < intervals.size(); i++ ){
            if (result[result.size() - 1].end >= intervals[i].start){
                if (result[result.size() - 1].end <= intervals[i].end)
                    result[result.size() - 1].end = intervals[i].end;
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

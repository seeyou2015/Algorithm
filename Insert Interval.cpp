//Use Binary search to find the range which should be merged with the new interval.
// O(logN)

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
    int BinarySearch(vector<Interval>& intervals, int target){
        if(intervals.size()==0)
            return -1;
        int left=0, right=intervals.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(target==intervals[mid].start)
                return mid;
            if(target>intervals[mid].start)
                left=mid+1;
            else
                right=mid-1;
        }
        if(intervals[left].start>target)
            return left-1;
        else
            return left;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool isInserted=0;
        for(int i=0; i<intervals.size(); i++){
            if((!(intervals[i].end<newInterval.start))  && (!(intervals[i].start>newInterval.end))){
                int start=min(intervals[i].start, newInterval.start);
                int end=max(intervals[i].end, newInterval.end);
                i=BinarySearch(intervals, end);
                end=max(intervals[i].end, end);
                res.push_back(Interval(start, end));
                isInserted=1;
            }
            else
                res.push_back(intervals[i]);
        }
        if(isInserted==0){
            int i=BinarySearch(intervals, newInterval.start);
            res.insert(res.begin()+i+1,newInterval);
        }
        return res;
    }
};

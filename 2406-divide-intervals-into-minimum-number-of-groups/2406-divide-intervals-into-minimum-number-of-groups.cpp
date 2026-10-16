class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts(n);
        vector<int> ends(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int end_ptr = 0;
        int max_groups = 0;
        int active_groups = 0;
        for (int start : starts) {
            if (start <= ends[end_ptr]) {
                active_groups++;
            } else {
                end_ptr++;
            }
            max_groups = max(max_groups, active_groups);
        }
        return max_groups;
    }
};
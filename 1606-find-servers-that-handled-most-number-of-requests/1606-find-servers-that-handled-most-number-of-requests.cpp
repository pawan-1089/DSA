class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> request_counts(k, 0);
        set<int> available;
        
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        // Min-heap tracking: {completion_time, server_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        
        for (int i = 0; i < arrival.size(); ++i) {
            long long start_time = arrival[i];
            long long duration = load[i];
            
            // Release servers that have completed their processing tasks
            while (!busy.empty() && busy.top().first <= start_time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // Drop request if no servers are currently idle
            if (available.empty()) {
                continue;
            }
            
            int preferred = i % k;
            auto it = available.lower_bound(preferred);
            
            // If wrapping around the array boundary is required
            if (it == available.end()) {
                it = available.begin();
            }
            
            int chosen_server = *it;
            available.erase(it);
            
            request_counts[chosen_server]++;
            busy.push({start_time + duration, chosen_server});
        }
        
        int max_requests = *max_element(request_counts.begin(), request_counts.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_counts[i] == max_requests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
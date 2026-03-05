class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);

        for(int i = 0; i < n; i++) cars[i] = {position[i], speed[i]};

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        stack<double> st;

        for(auto it : cars) {
            double time = (double)(target - it.first) / it.second;

            if(st.empty() || st.top() < time) st.push(time); 
        }

        return st.size();
    }
};
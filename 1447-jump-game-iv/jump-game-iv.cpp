class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        // value -> list of indices
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        visited[0] = true;

        queue<int> q;
        q.push(0);
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            steps++;

            for (int i = 0; i < sz; i++) {
                int j = q.front();
                q.pop();

                // jump to j+1
                if (j + 1 < n && !visited[j + 1]) {
                    if (j + 1 == n - 1) return steps;
                    visited[j + 1] = true;
                    q.push(j + 1);
                }

                // jump to j-1
                if (j - 1 >= 0 && !visited[j - 1]) {
                    if (j - 1 == n - 1) return steps;
                    visited[j - 1] = true;
                    q.push(j - 1);
                }

                // jump to all same-value indices
                if (mp.count(arr[j])) {
                    for (int idx : mp[arr[j]]) {
                        if (!visited[idx]) {
                            if (idx == n - 1) return steps;
                            visited[idx] = true;
                            q.push(idx);
                        }
                    }
                    // clear to avoid reprocessing same-value group
                    mp.erase(arr[j]);
                }
            }
        }

        return -1; // unreachable
    }
};
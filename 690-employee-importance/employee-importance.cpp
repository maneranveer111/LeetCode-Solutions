/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, vector<int>> subOrdinate;
    unordered_map<int, int> empImp;
    unordered_set<int> vis;

    int helper(int node) {
        vis.insert(node);
        int ans = 0;

        for(auto nei : subOrdinate[node]) {
            if(!vis.count(nei)) {
                ans += helper(nei);
            }
        }

        return ans + empImp[node];
    }

    int getImportance(vector<Employee*> employees, int id) {
        for(auto emp : employees) {
            int em_id = emp->id;
            int em_imp = emp->importance;
            empImp[em_id] = em_imp;

            for(auto nei : emp->subordinates) {
                subOrdinate[em_id].push_back(nei);
            }
        }    

        return helper(id);
    }
};
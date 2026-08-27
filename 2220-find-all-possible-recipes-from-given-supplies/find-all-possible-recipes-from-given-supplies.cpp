class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> ingToRecipes;
        unordered_map<string, int> inDeg;

        for(int i = 0; i < recipes.size(); i++) {
            inDeg[recipes[i]] = ingredients[i].size();
            
            for(auto ing : ingredients[i])
                ingToRecipes[ing].push_back(recipes[i]);
        }

        queue<string> q;
        for(auto sup : supplies)
            q.push(sup);
        
        unordered_set<string> madeRecipes;
        vector<string> ans;

        while(!q.empty()) {
            string node = q.front();
            q.pop();

            if(ingToRecipes.find(node) == ingToRecipes.end())
                continue;
            
            for(auto rec : ingToRecipes[node]) {
                inDeg[rec]--;

                if(inDeg[rec] == 0 && !madeRecipes.count(rec)) {
                    ans.push_back(rec);
                    madeRecipes.insert(rec);
                    q.push(rec);
                }
            }
        }

        return ans;
    }
};
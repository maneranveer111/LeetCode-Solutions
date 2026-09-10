class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        vector<vector<bool>> adjMatrix(n, vector<bool>(n, false));

        for(auto edg : roads) {
            int u = edg[0];
            int v = edg[1];

            degrees[u]++;
            degrees[v]++;
            adjMatrix[u][v] = true;
            adjMatrix[v][u] = true;
        }   

        int maxRank = 0;

        for(int u = 0; u < n; u++) {
            for(int v = u + 1; v < n; v++) {
                int rank = degrees[u] + degrees[v] - (adjMatrix[u][v] ? 1 : 0);
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};
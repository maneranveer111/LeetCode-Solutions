class Solution {
public:
    int minPartitions(string n) {
        int max_element = -1;
        for(int i = 0; i < n.size(); i++) {
            max_element = max(max_element, n[i] - '0');
        }  

        return max_element;
    }
};
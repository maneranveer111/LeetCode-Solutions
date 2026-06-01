struct Trie{
    Trie *child[26];
    bool isEnd;
    int childCnt;

    Trie() : isEnd(false), childCnt(0) {
        fill(child, child + 26, nullptr);
    }
};

void insert(Trie* root, string& word) {
    Trie* curr = root;
    for(char ch : word) {
        if(!curr->child[ch - 'a']) {
            curr->child[ch - 'a'] = new Trie();
            curr->childCnt++;
        }

        curr = curr->child[ch - 'a'];
    }

    curr->isEnd = true;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root = new Trie();
        string ans = "";
        for(string word : strs)
            insert(root, word);
        Trie* curr = root;
        while(curr->childCnt == 1 && !curr->isEnd) {
            for(int i = 0; i < 26; i++) {
                if(curr->child[i]) {
                    ans += (char)('a' + i);
                    curr = curr->child[i];
                    break;
                }
            }
        }

        return ans;

        // for(int i = 0; i < strs.size(); i++) {
        //     if(i == 0)
        //         ans = strs[i];
        //     else {
        //         int j = 0;
        //         while(j < ans.size() && j < strs[i].size() && strs[i][j] == ans[j])
        //             j++;
        //         ans = ans.substr(0, j);
        //     }

        // }
        // return ans;
    }
};
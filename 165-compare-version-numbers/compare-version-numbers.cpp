class Solution {
public:
    int compareVersion(string version1, string version2) {
        int st1 = 0, st2 = 0;
        int curr1 = 0, curr2 = 0;
        int n = version1.size(), m = version2.size();

        while(st1 < version1.size() || st2 < version2.size()) {
            if(curr1 == 0) {
                while(st1 < n && version1[st1] == '0')
                    st1++;

                while(st1 < n && version1[st1] != '.') {
                    curr1 = curr1 * 10 + (version1[st1] - '0');
                    st1++;
                }
            }

            if(curr2 == 0) {
                while(st2 < m && version2[st2] == '0')
                    st2++;

                while(st2 < m && version2[st2] != '.') {
                    curr2 = curr2 * 10 + (version2[st2] - '0');
                    st2++;
                }
            }

            if(curr1 < curr2)
                return -1;
            else if(curr1 > curr2)
                return 1;
            
            st1++;
            st2++;
            curr1 = 0;
            curr2 = 0;
        }

        return 0;
    }
};
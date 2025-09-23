// Two pointers + substr + stoi
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int n1 = version1.size(), n2 = version2.size();

        while (i1 < n1 || i2 < n2) {
            int j1 = i1;
            while (j1 < n1 && version1[j1] != '.') ++j1;
            int j2 = i2;
            while (j2 < n2 && version2[j2] != '.') ++j2;

            int num1 = 0, num2 = 0;
            if (i1 < n1) num1 = stoi(version1.substr(i1, j1 - i1));
            if (i2 < n2) num2 = stoi(version2.substr(i2, j2 - i2));

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            i1 = j1 + 1;
            i2 = j2 + 1;
        }
        return 0;
    }
};
class Solution {
    bool flag[1001][1001] = { false };
public:
    int countSubstrings(string s) {
        int len = s.size(), maxlen = 1, st = 0;
        for (int i = 0; i < len; i++) flag[i][i] = true;

        for (int i = 0; i < len - 1; i++)
            if (s[i] == s[i + 1])
                flag[i][i + 1] = true, maxlen = 2, st = i;

        for (int trys = 3; trys <= len; trys++) {
            for (int i = 0; i < len - trys + 1; i++) {
                int j = i + trys - 1;

                if (flag[i + 1][j - 1] && s[i] == s[j]) {
                    flag[i][j] = true;
                    if (trys > maxlen)
                        maxlen = trys, st = i;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
            for (int j = i; j < s.size(); j++)
                if (flag[i][j])
                   cnt++;
        return cnt;
    }
};
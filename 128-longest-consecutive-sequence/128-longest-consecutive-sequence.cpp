class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        map<int, bool> mp;
        for (auto e : nums)
            mp[e] = true;

        int ans = 1, temp = 1, curval = mp.begin()->first;
        for (auto e : mp) {
            if (e.first == curval) continue;
            else if (e.first == curval + 1)
                temp++, curval = e.first;
            else
                ans = max(ans, temp), temp = 1, curval = e.first;
        }
        ans = max(ans, temp);
        return ans;
    }
};
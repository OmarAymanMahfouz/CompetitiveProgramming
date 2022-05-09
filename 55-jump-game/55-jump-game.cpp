class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for (int i = 0; i <= maxJump && i < nums.size(); i++){
            maxJump = max(maxJump, i + nums[i]);
        }
        

        return maxJump >= nums.size() - 1;
    }
};
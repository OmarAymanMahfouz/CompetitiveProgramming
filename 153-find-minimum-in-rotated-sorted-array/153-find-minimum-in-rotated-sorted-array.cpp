class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, ed = nums.size() - 1;
        if (nums[st] < nums[ed] || !ed) return nums[st];
        
        while(st < ed){
            int mid = ((st + ed) / 2);
            if (nums[0] <= nums[mid])
                st = mid + 1;
            else
                ed = mid;

        }
        return nums[st];
    }
};
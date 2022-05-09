class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> answer(len);
		vector<int> prefix(len), suffix(len);

		prefix[0] = nums[0];
		suffix[len - 1] = nums.back();

		for (int i = 1; i < len; i++) {
			prefix[i] = prefix[i - 1] * nums[i];
			suffix[len - i - 1] = nums[len - i - 1] * suffix[len - i];
		}

		for (int i = 0; i < len; i++) {
			if (i == 0)
				answer[i] = suffix[i + 1];
			else if (i == len - 1)
				answer[i] = prefix[i - 1];
			else
				answer[i] = prefix[i - 1] * suffix[i + 1];
		}
		return answer;
	}
};
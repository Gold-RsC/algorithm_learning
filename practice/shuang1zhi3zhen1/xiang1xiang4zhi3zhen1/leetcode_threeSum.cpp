class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1, k = nums.size() - 1; j < k; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                while (nums[i] + nums[j] + nums[k] > 0 && j < k) {
                    --k;
                }
                if (j < k && nums[i] + nums[j] + nums[k] == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ret;
    }
};

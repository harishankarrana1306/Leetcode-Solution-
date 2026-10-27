class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++) {
            int no=target-nums[i];
            if(mpp.find(no) != mpp.end()) {
                return {mpp[no], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};
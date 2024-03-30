class Solution {
public:
    int subarraysWithAtMostK(vector<int>& nums, int k){
        int count = 0;
        unordered_map<int, int> freq;
        for(int left = 0, right = 0; right < nums.size(); right++){
            freq[nums[right]]++;
            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};

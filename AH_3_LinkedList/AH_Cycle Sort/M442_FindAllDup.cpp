class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> res;
        int n= nums.size();
        for(int i = 0; i < n; i++){
        if(nums[abs(nums[i]) - 1] > 0){
            nums[abs(nums[i])- 1] *= - 1;
        }
        else{
            res.push_back(abs(nums[i]));
        }
            // khi 1 số a hiện lần 1 thì nó sẽ đưa số có chỉ số là a về âm
            // khi số a hiện 2 lần thì nó sẽ đưa số đó vào mảng. => số a là số cần tìm
    }
    return res;
    }
};
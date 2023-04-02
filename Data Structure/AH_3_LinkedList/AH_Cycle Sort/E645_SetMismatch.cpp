class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<int> res;
        int check[N+1];
        for(int i = 0; i < N; i++){
            check[i+1] = 0;
        }
        for(int i = 0; i < N; i++){
            check[nums[i]] ++; 
        }
        for(int i = 1; i <= N; i++){
            if(check[i] == 2)
                res.push_back(i);
        }
        for(int i = 1; i <= N; i++){
            if(check[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int N = arr.size();
        vector<int> res;
        int check[1000 + N + 1];
        for(int i = 0; i <= 1000 + N; i++){
            check[i] = 0;
        }
        
        for(int i = 0; i < N; i++){
            check[arr[i]] ++;
        }
        
        for(int i = 1; i <= 1000 + N; i++){
            if(check[i] == 0)
                res.push_back(i);
        }
        
        return res[k-1];
    }
};

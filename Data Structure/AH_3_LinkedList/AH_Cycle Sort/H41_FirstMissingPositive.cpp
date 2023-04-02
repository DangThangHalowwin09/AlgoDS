// Cách tiếp cận đơn giản.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int check[n+2];
        for(int i = 0; i < n+2;i++){
            check[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] >0 && nums[i] <n+2){ 
                check[nums[i]] ++;
            }
        }
        for (int i = 1;i <n+1;i++){
            if(check[i] == 0)
                return i;
        }
        return n+1;
    }          
};

// Cricle sort

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            // điều kiện swap, không đổi nếu giá trị của nó và giá trị tại chỉ số index nó bằng nhau.
                swap(A[i], A[A[i] - 1]);

            // thực hiện đổi vị trí ban đầu và vị trí ứng với giá trị index của nó.
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};
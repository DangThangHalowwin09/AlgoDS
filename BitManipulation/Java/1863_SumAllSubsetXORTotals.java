class Solution {
    private int N; // số phần tử
    private int[] selections = null; // Tập cấu hình ban đầu N phần tử mọi phần tử đều là null
    private int[] validValues = {0,1}; // Mảng 2 phần tử có thể chọn 1 => lấy, 0 => không lấy giá trin index trong mảng selections
    private int resultSum = 0; // Kết quả cần tìm
    private int[] nums = null; // Mảng kết quả
    
    private void backtrack(int index, int curXOR){
        for(int i =0; i < 2; i++){
            selections[index] = validValues[i]; 
            // lấy giá trị 
            if(selections[index] == 1){
                curXOR = curXOR ^ this.nums[index]; // cứ mỗi phần từ có giá trị 1 thì thực hiện XOR luôn
            }
            // Thực hiện tăng giá trị index hoặc trả về giá trị cuối cùng
            if(index == this.N - 1){
                int sum = curXOR;
                this.resultSum +=sum;
            }
            else
            {
                backtrack(index + 1, curXOR);
            }
        }
    }
    public int subsetXORSum(int[] nums) {
        this.N = nums.length;
        this.selections = new int[this.N];
        this.nums = nums;
        backtrack(0, 0);
        return this.resultSum;
    }
}
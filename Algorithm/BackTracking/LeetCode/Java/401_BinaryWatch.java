// Cách Backtracking:
// Cho tất cả cái giá trị giờ và phút vào một mảng
// Dùng backtracking để cập nhật giá trị giờ, giá trị phút, số lượng bit bật
// Có thể dùng String Builder để tiết kiệm time
class Solution {
        private List<String> results = new ArrayList<>();
        private int[] values = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
        private int EXPECTED_COUNT = 0;
        
        private void backtracking(int index, int curCount, int h, int m){
            for(int i = 0; i <= 1; i++){
                if( i == 1 ){
                    curCount++;
                    if(index <= 3){
                        h += values[index];
                    }
                    else{
                        m += values[index];
                    }
                }
                if(index == values.length - 1){
                    if(curCount == EXPECTED_COUNT && h < 12 && m < 60){
                        String time  = String.format("%d:%02d", h, m);
                        
                        this.results.add(time);
                    }
                }
                else{
                    backtracking(index+1, curCount, h, m);
                }
            }
        }
        public List<String> readBinaryWatch(int turnedOn){
            EXPECTED_COUNT = turnedOn;
            backtracking(0, 0, 0, 0);
            return this.results;
        }
    
};
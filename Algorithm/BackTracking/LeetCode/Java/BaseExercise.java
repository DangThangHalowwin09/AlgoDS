public class BaseExercise {
    private static String[] colors = {"red", "green", "blue", "yellow", "purple"};
    private static int[] selections = new int[colors.length];
    private static int[] valid_value = {0,1};

    public static void backtrack(int index){
        for(int i = 0; i < 2; i++){
            selections[index] = valid_value[i];
        
            if(index == colors.length - 1){
            process(selections);
            }
            else{
            backtrack(index + 1);
            }
        }
    }
    private static int count = 0;
    public static void process(int[] selections){
        String newMixColor = "";
        for(int i = 0; i < selections.length; i++){
            if(selections[i] == 1){
                
                newMixColor += colors[i];
            }
        }
        // xong mỗi cấu hình thì count sẽ tăng lên 1 đơn vị
        count++;
        System.out.println(count + " newColor:" +  " " + newMixColor);
    }
    
    public static void main(String[] args){
        backtrack(0);
    }
}
class Solution{
public int countBitOne(int number){
    int count = 0;
    while(number != 0){
    if((number & 1) == 1){
    count ++;
    }
    number = number >> 1;
    }
    return count;
}

public List<String> readBinaryWatch(int turnedOn){
    List<String> results = new ArrayList<>();

    for(int h = 0; h < 12; h++){
        for(int m = 0; m < 60; m++){
            int totalBitCount = countBitOne(h) + countBitOne(m);
            if(totalBitCount == turnedOn){
                String time  = String.format("%d:%02d", h, m);                  
                results.add(time);
            }
        }
    }
    return results;
}
};
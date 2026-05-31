class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int n = b.length();
        int num = 0;
        int p = 1;
        
        for(int i=n-1;i>=0;i--){
            if(b[i] == '1'){
                num = num + p; 
            }
            p = p*2;
        }
        return num;
    }
};
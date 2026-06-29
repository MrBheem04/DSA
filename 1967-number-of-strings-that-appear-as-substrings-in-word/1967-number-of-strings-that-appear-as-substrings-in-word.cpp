class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string str : patterns){
            if(word.contains(str)){
                count++;
            }
        }
        return count;
    }
};
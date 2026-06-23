class Solution {
public:
    void helper(int n ,string curr,vector<string>&result){
        if(curr.length() == n){
            result.push_back(curr);
            return;
        }
        helper(n,curr +"1",result);

        if(curr.empty() || curr.back() != '0'){
            helper(n,curr+"0",result);
        }
    }
    vector<string> validStrings(int n) {
        vector<string>result;
        helper(n,"",result);
        return result;        
    }
};
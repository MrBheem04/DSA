class Solution {
  public:
void solve(string &s ,int index,string current,vector<string>&result){
    if(index == s.length()){
        result.push_back(current);
        return;
    }
    solve(s,index+1,current,result);
    
    current.push_back(s[index]);
    solve(s,index+1,current,result);
    
    current.pop_back();
}
    vector<string> powerSet(string &s) {
        // Code here
        vector<string>result;
        solve(s,0,"",result);
        
        sort(result.begin(),result.end());
        return result;
    }
};
class Solution {
    void findsumsubsets(int ind,int[] nums,List<Integer> ds,List<List<Integer>>ans){
        ans.add(new ArrayList<>(ds));

        for(int i= ind;i<nums.length;i++){
            if(i != ind && nums[i] == nums[i-1])continue;
            ds.add(nums[i]);
            findsumsubsets(i+1,nums,ds,ans);
            ds.remove(ds.size()-1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<Integer>ds = new ArrayList<>();
        Arrays.sort(nums);
        List<List<Integer>>ans = new ArrayList<>();
        findsumsubsets(0,nums,ds,ans);
        return ans;
    }
}
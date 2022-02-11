// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2);
    ans[0]=-1;
    ans[1]=-1;

    int n=nums.size();
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(nums[m]<target){
            l=m+1;
        }else if(nums[m]>target){
            h=m-1;
        }else{
            int t=m;
            while(m>0 and nums[m-1]==target){
                m--;
            }
            ans[0]=m;
            while(t<n-1 and nums[t+1]==target){
                t++;
            }
            ans[1]=t;
            return ans;
            
        }
        
    }
    return ans;
    
}
};
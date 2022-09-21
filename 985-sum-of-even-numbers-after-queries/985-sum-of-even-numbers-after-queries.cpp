class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int a,sum=0,temp;
        a=queries.size();
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                sum+=nums[i];
        }
        for(int i=0;i<a;i++){
            temp=nums[queries[i][1]];
            nums[queries[i][1]]+=queries[i][0];
            if(nums[queries[i][1]]%2==0){
                if(temp%2==0)
                    sum-=temp;
                sum+=nums[queries[i][1]];
            }
            else{
                if(temp%2==0){
                    sum-=temp;
                }
            }
            arr.push_back(sum);
        }
        return arr;
    }
};
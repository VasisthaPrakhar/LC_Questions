class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        for(int i=0;i<n;i++){
            int x=nums[i];
            while(i<n && x==nums[i]){
                i++;
            }
            i--;
            a.push_back(x);
        }
        int ans=0;
        if(a.size()==1){
            if(a[0]==1){
                return 0;
            }else{
                return 1;
            }
        }
        while(a.size()>1){
            int x=a.back();
            a.pop_back();
            int y=a.back();
            a.pop_back();
            if(x==1 && y==0){
                ans+=2;
            }else{
                ans+=1;
                a.push_back(1);
            }
        }
        return ans;
    }
};
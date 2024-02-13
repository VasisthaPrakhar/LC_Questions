static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        int n=nums.size();
        int m=p.size(),ans=0;
        string s="",t="";
        for(int i=1;i<n;i++){
            // int f=0;
            // for(int j=0,k=i;j<m;j++,k++){
            //     if(p[j]==1 && nums[k]<=nums[k-1]){
            //         f=1;
            //         break;
            //     }
            //     if(p[j]==0 && nums[k]!=nums[k-1]){
            //         f=1;
            //         break;
            //     }
            //     if(p[j]==-1 && nums[k]>=nums[k-1]){
            //         f=1;
            //         break;
            //     }
            // }
            // if(f==0){ans++;}
            if(nums[i]>nums[i-1]){
                s.push_back('a');
            }else if(nums[i]<nums[i-1]){
                s.push_back('c');
            }else{
                s.push_back('b');
            }
        }
        for(int i=0;i<m;i++){
            if(p[i]==1){
                t.push_back('a');
            }else if(p[i]==0){
                t.push_back('b');
            }else{
                t.push_back('c');
            }
        }
        int f=0;
        do{
            f = s.find(t, f);
            if(f != string::npos){
                ans++,f++;
            }
        }while(f != string::npos);
        return ans;
    }
};
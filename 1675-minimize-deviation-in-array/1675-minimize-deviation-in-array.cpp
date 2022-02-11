class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mi=INT_MAX,n=nums.size(),ans=INT_MAX;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                pq.push(nums[i]*2);
                mi=min(nums[i]*2,mi);
            }else{
                pq.push(nums[i]);
                mi=min(nums[i],mi);
            }
        }
        //cout<<mi<<" ";
        while(pq.top()%2==0){
            int x=pq.top();
            ans=min(ans,pq.top()-mi);
            mi=min(mi,pq.top()/2);
            pq.pop();
            pq.push(x/2);
        }
        //cout<<pq.top()<<" ";
        ans=min(ans,pq.top()-mi);
        return ans;
    }
};
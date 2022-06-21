class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        int j=0,n=a.size(),ans=0;
        priority_queue<int>pq;
        while(j<n-1){
            int k=a[j+1]-a[j];
            if(k>0){
                b-=k;
                pq.push(k);
                if(b<0){
                    b+=pq.top();
                    pq.pop();
                    l--;
                }
                if(l<0){
                    break;
                }
            }
            j++;
        }
        return j;
    }
};
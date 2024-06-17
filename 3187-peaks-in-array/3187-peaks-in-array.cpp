class segment_tree{
private:
    int n;
    vector<int>seg;
    void build_seg_tree(int idx,int start,int end ,vector<int>&a){
        if(start==end){
            seg[idx]=a[start];
            return;
        }
        int mid=(start+end)>>1;
        build_seg_tree(2*idx+1,start,mid,a);
        build_seg_tree(2*idx+2,mid+1,end,a);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int query(int idx,int start, int end,int l,int r){
        if(end<l || start>r){
            return 0;
        }
        if(end<=r && start>=l){
            return seg[idx];
        }
        int mid=(start+end)>>1;
        int left = query(2*idx+1,start,mid,l,r);
        int right = query(2*idx+2,mid+1,end,l,r);
        return left+right;
    }

    void update(int idx,int start, int end,int i,int val){
        if(start==end){
            seg[idx]=val;
            return;
        }
        int mid=(start+end)>>1;
        if(i<=mid)
            update(2*idx+1,start,mid,i,val);
        else
            update(2*idx+2,mid+1,end,i,val);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }

public:
    segment_tree(vector<int>&a){
        this->n=a.size();
        this->seg.resize(4* (this->n),INT_MAX);
        build_seg_tree(0,0,(this->n)-1,a);
    }
    int range_query(int l,int r){
        return query(0,0, (this->n)-1,l,r);
    }
    void update_query(int idx,int val){
        update(0,0, (this->n)-1,idx,val);
    }
};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int m=q.size();
        vector<int>a(n,0);
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                a[i]=1;
            }
        }
        
        segment_tree* st=new segment_tree(a);
        vector<int>ans;
        for(int i=0;i<m;i++){
            if(q[i][0]==1){
                int c=0;
                if(q[i][1]==q[i][2]){
                    ans.push_back(0);
                    continue;
                }
                if(a[q[i][1]]==1){
                    c++;
                }
                if(a[q[i][2]]==1){
                    c++;
                }
                int k=st->range_query(q[i][1],q[i][2])-c;
                ans.push_back(max(k,0));
            }else{
                int idx=q[i][1],val=q[i][2];
                if(nums[idx]==val){continue;}
                nums[idx]=val;
                if(idx>0 && idx<n-1){
                    if(nums[idx]>nums[idx-1] && nums[idx]>nums[idx+1]){
                        a[idx]=1;
                        st->update_query(idx,1);
                    }else{
                        a[idx]=0;
                        st->update_query(idx,0);
                    }
                }
                if(idx-2>=0){
                    if(nums[idx-1]>nums[idx-2] && nums[idx-1]>nums[idx]){
                        a[idx-1]=1;
                        st->update_query(idx-1,1);
                    }else{
                        a[idx-1]=0;
                        st->update_query(idx-1,0);
                    }
                }
                if(idx+2<=n-1){
                    if(nums[idx+1]>nums[idx] && nums[idx+1]>nums[idx+2]){
                        a[idx+1]=1;
                        st->update_query(idx+1,1);
                    }else{
                        a[idx+1]=0;
                        st->update_query(idx+1,0);
                    }
                }
            }
        }
        return ans;
    }
};
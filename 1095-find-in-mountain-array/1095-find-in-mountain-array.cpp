/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int fun(int beg, int end, int t,  MountainArray &a, int n){
        int ans=-1,mid;
        while(beg<=end){
            mid=(beg+end)/2;
            int x=a.get(mid);
            if(x>=t){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        if(ans<0 || ans>=n){return -1;}
        return a.get(ans)==t?ans:-1;
    }
    int fun1(int beg, int end, int t,  MountainArray &a, int n){
        int ans=-1,mid;
        while(beg<=end){
            mid=(beg+end)/2;
            int x=a.get(mid);
            if(x>=t){
                ans=mid;
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        //cout<<ans;
         if(ans<0 || ans>=n){return -1;}
        return a.get(ans)==t?ans:-1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int peak=-1,beg=0,end=n-1,mid,ans;
        while(beg<=end){
            mid=(beg+end)/2;
            int x = mountainArr.get(mid),y=-1,z=-1;
            if(mid<n-1)
                y=mountainArr.get(mid+1);
            if(mid>0)
                z=mountainArr.get(mid-1);
            if(x>y && x>z){
                peak=mid;
                break;
            }
            if(x>y && x<z){
                end=mid-1;
            }
            if(x<y && x>z){
                beg=mid+1;
            }
        }
        ans=fun(0,peak,target,mountainArr,n);
        if(ans==-1){
            ans=fun1(peak+1,n-1,target,mountainArr,n);
        }
        return ans;
    }
};
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int guessNumber(int n) {
        long long unsigned int beg=1,end=n,mid;
        while(beg<=end){
            mid=(beg+end)/2;
            int k=guess(mid);
            if(k==0){
                return mid;
            }else if(k>0){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return beg;
    }
};
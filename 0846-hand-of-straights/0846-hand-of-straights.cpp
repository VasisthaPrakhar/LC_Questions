class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n=hand.size();
        if(n%g!=0){
            return false;
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        while(mp.size()){
            auto it=mp.begin();
            int k=g,mi=INT_MAX,a=it->first;
            while(k--){
                if(mp.find(a)==mp.end()){
                    return false;
                }
                mi=min(mi,it->second);
                it++,a++;
            }
            k=g,a=mp.begin()->first;
            while(k--){
                mp[a]-=mi;
                if(mp[a]==0){
                    mp.erase(a);
                }
                a++;
            }
        }
        return true;
    }
};
class Solution {
public:
    typedef long long int ll;
    int poorPigs(int b, int md, int mt) {
        ll a=mt/md+1;
        int die=0;
        for(int p=1;p<b;p*=a){
            die++;
        }
        return die;
    }
};
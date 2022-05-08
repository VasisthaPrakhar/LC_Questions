/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    private:stack<NestedInteger>s;
    int idx;
public:
    NestedIterator(vector<NestedInteger> &ne) {
        int sz=ne.size();
        for(int i=sz-1;i>=0;i--){
            s.push(ne[i]);
        }
    }
    
    int next() {
        auto k=s.top().getInteger();
        s.pop();
        return k;
    }
    
    bool hasNext() {
        while(!s.empty()){
            auto node=s.top();
            if(node.isInteger()){
                return true;
            }
            s.pop();
            auto &adj=node.getList();
            int k=adj.size();
            for(int i=k-1;i>=0;i--){
                s.push(adj[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
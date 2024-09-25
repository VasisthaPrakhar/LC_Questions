struct Node {
	Node *links[26];
	bool flag = false;
    int countSoFar = 0;
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch, Node *node) {
        //countSoFar++;
		links[ch - 'a'] = node;
	}
	Node *get(char ch) {
		return links[ch - 'a'];
	}
    int getCount(){
        return countSoFar;
    }
	void setEnd() {
		flag = true;
	}
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
            node->countSoFar++;
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}                                                       
			node = node->get(word[i]);
		}
		return node->isEnd();
	}
    void fun(Node* node,string &pre,vector<string>&ans){
        if(node->isEnd()){
            ans.push_back(pre);
        }
        for(int i=0;i<26;i++){
            if(node->links[i]){
                pre.push_back('a'+i);
                fun(node->links[i],pre,ans);
                pre.pop_back();
            }
        }
    }
	vector<string> startsWith(string prefix) {
		Node* node = root;
		vector<string>ans;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return ans;
			}
			node = node->get(prefix[i]);
		}
		fun(node,prefix,ans);
		return ans;
	}
    int startWith_Count(string prefix){
        Node* node=root;
        int ans=0;
        for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return ans;
			}
			node = node->get(prefix[i]);
            ans+=node->countSoFar;
		}
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& w) {
        Trie* root=new Trie();
        for(auto x:w){
            root->insert(x);
        }
        vector<int>ans;
        for(auto x:w){
            ans.push_back(root->startWith_Count(x));
        }
        
        return ans;
    }
};
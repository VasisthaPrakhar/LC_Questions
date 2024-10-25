struct Node {
	unordered_map<string,Node*>links;
	bool flag = false;
	bool containKey(string ch) {
		return (links[ch] != NULL);
	}
	void put(string ch, Node *node) {
		links[ch] = node;
	}
	Node *get(string ch) {
		return links[ch];
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

	void insert(string &word) {
		Node *node = root;
        stringstream ss(word);
        string token;
        while(getline(ss,token,'/')){
            if (!node->containKey(token)) {
				node->put(token, new Node());
			}
			node = node->get(token);
            if(node->isEnd()){
                break;
            }
        }
		// for (int i = 0; i < word.size(); i++) {
		// 	if (!node->containKey(word[i])) {
		// 		node->put(word[i], new Node());
		// 	}
		// 	node = node->get(word[i]);
		// }
		node->setEnd();
	}

	bool search(string &word) {
		Node *node = root;
        stringstream ss(word);
        string token;
        while(getline(ss,token,'/')){
            if (!node->containKey(token)) {
				return false;
			}
			node = node->get(token);
        }
		// for (int i = 0; i < word.size(); i++) {
		// 	if (!node->containKey(word[i])) {
		// 		return false;
		// 	}
		// 	node = node->get(word[i]);
		// }
		return node->isEnd();
	}
	// void fun(Node* node,string &pre,vector<string>&ans){
	// if(node->isEnd()){
	// ans.push_back(pre);
	// }
	// for(int i=0;i<26;i++){
	// if(node->links[i]){
	// pre.push_back('a'+i);
	// fun(node->links[i],pre,ans);
	// pre.pop_back();
	// }
	// }
	// }
	// vector<string> startsWith(string prefix) {
	// 	Node* node = root;
	// 	vector<string>ans;
	// 	for (int i = 0; i < prefix.size(); i++) {
	// 		if (!node->containKey(prefix[i])) {
	// 			return ans;
	// 		}
	// 		node = node->get(prefix[i]);
	// 	}
	// 	fun(node,prefix,ans);
	// 	return ans;
	// }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        Trie* trie=new Trie();
        sort(f.begin(),f.end(),[](string &a, string&b)->bool{
            return a.length()<b.length();
        });
        for(auto x:f){
            trie->insert(x);
        }
        vector<string>ans;
        for(auto x:f){
            if(trie->search(x)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
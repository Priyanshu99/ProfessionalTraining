#include <iostream>
using namespace std;

struct node{
	//bool isEndOfWord;
	int passes;
	node* child[26];
	node(){
		passes = 0;
		//isEndOfWord = false;
		for (int i = 0; i < 26; i++)child[i] = 0;
	}
};
struct trie{
	node* root;
	trie(){ root = new node; }
	void insert(char *data){
		node* cur = root;
		int idx = 0;
		while (data[idx]!=0){
			int ind = data[idx]-'a';
			if (!cur->child[ind])cur->child[ind] = new node;
			cur->passes = cur->passes+1;
			cur = cur->child[ind];
			idx++;
		}
	}
	int search(char *str){
		node*cur = root;
		int idx = 0;
		while (str[idx] != 0){
			int ind = str[idx] - 'a';
			if (!cur->child[ind])return 0;
			cur = cur->child[ind];
			idx++;
		}
		return cur->passes;
	}
};
trie* db;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	db = new trie;
	int n;
	cin >> n;
	char inp[22];
	char type[5];
	for (int i = 0; i < n; i++){
		cin >> type>>inp;
		if (type[0] == 'a'){
			db->insert(inp);
		}
		else{
			cout << db->search(inp)<<'\n';
		}
	}
}

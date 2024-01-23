#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

struct Node {
	Node *links[10];
	bool flag = false;

	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - '0'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - '0'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - '0'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};

class Trie {
private:
	Node *root;
public:

	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
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

	bool startsWith(string prefix) {
		Node *node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}

    void fillLexicographically(Node *node, string curr, vector<string> &res)  {
        for (char ch = '0'; ch <= '9'; ch++) {
            if (node->containKey(ch)) {
                Node *temp = node->get(ch);
                if (temp->isEnd()) {
                    res.push_back(curr + ch);
                }
                fillLexicographically(temp, curr + ch, res);
            }
        }
	}

    vector<int> getLexSorted() {
        vector<string> arr;
        Node *node = root;
        fillLexicographically(root, "", arr);

        vector<int> res;
        for (int i = 0; i < arr.size(); i++) {
            res.push_back(stoi(arr[i]));
            // cout << arr[i] << endl;
        }

        return res;
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie trie;
        for (int i = 1; i <= n; i++) {
            trie.insert(to_string(i));
        }

        cout << "Contains 99? " << trie.search("99") << endl;

        return trie.getLexSorted();
    }
}; 

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    Solution obj;

    vector<int> res = obj.lexicalOrder(13);

    for (int el : res) {
        cout << el << ", \t";
    }
    cout << endl;

    return 0;
}

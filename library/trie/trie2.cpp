#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node *links[26];
    int countEndsWith = 0;
    int countPrefix = 0;
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        countEndsWith++;
    }

    void increasePrefix() {
        countPrefix++;
    }

    void reduceEnd() {
        countEndsWith--;
    }

    void reducePrefix() {
        countPrefix--;
    }

    int getEndsWith() {
        return countEndsWith;
    }

    int getPrefix() {
        return countPrefix;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getEndsWith();
    }

    int countWordsStartingWith(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])){
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            } else {
                return;
            }
        }
        node->reduceEnd();
    }

};
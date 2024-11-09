#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int wordsCounter(const std::string& str) {
    vector<string> words; 
    stringstream ss(str); 
    string word;
    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return c == ',' || c == '.';
        }), word.end());
        if (!word.empty()) {
            if (find(words.begin(), words.end(), word) == words.end()) {
                words.push_back(word);
            }
        }
    }
    return words.size(); 
}

int main() {
    string sentence = "Can you, can you.";
    int count = wordsCounter(sentence);
    cout << "Количество уникальных слов: " << count << endl; 
    return 0;
}

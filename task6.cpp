#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string toLower(const string& str) {
    string lowerStr;
    for (char c : str) {
        lowerStr += tolower(c); 
    }
    return lowerStr;
}

int diffWordsCounter(const std::string& str) {
    vector<string> uniqueWords;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return c == ',' || c == '.';
        }), word.end());
        if (!word.empty()) {
            string lowerWord = toLower(word);
            if (find(uniqueWords.begin(), uniqueWords.end(), lowerWord) == uniqueWords.end()) {
                uniqueWords.push_back(lowerWord);
            }
        }
    }
    return uniqueWords.size(); 
}

int main() {
    int words = diffWordsCounter("can you can a can");
    cout << "Количество различных слов: " << words << endl;
    return 0;
}

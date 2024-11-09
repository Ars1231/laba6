#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

std::map<std::string, int> wordsMapCounter(const std::string& str) {
    map<string, int> wordCount; 
    stringstream ss(str);
    string word;
    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return c == ',' || c == '.';
         }), word.end());
        if (!word.empty()) wordCount[word]++;
    }

    return wordCount;
}

int main() {
    std::map<std::string, int> words = wordsMapCounter("can you can");
    cout << "Количество вхождений слов:" << endl;
    for (const auto& pair : words) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    return 0;
}

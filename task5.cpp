#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> 
using namespace std;

// функция для преобразования строки в нижний регистр
string toLower(const string& str) {
    string lowerStr = str;
    for (char& c : lowerStr) {
        c = tolower(c);
    }
    return lowerStr;
}

std::vector<std::string> uniqueWords(const std::string& str) {
    vector<string> uniqueWordsVec;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return c == ',' || c == '.';
        }), word.end());
        if (!word.empty()) {
            string lowerWord = toLower(word);
            if (find(uniqueWordsVec.begin(), uniqueWordsVec.end(), lowerWord) == uniqueWordsVec.end()) {
                uniqueWordsVec.push_back(lowerWord);
            }
        }
    }
    return uniqueWordsVec;
}

int main() {
    vector<string> unique = uniqueWords("Can you can");
    cout << "Уникальные слова: ";
    for (const auto& word : unique) {
        cout << word << " "; 
    }
    cout << endl;
    return 0;
}

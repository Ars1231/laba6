#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator Find(vector<int>::iterator first, vector<int>::iterator last, int el) {
    while (first != last) {
        if (*first == el)  return first; 
        ++first; 
    }
    return last; 
}

int main() {
    vector<int> v; 
    int n;
    cout << "Введите количество элементов вектора: ";
    cin >> n;
    cout << "Введите элементы вектора: " << endl;
    for (int i = 0; i < n; ++i) {
        int element;
        cout << "Элемент " << (i + 1) << ": ";
        cin >> element;
        v.push_back(element); 
    }
    int elementToFind;
    cout << "Введите элемент для поиска: ";
    cin >> elementToFind;
    vector<int>::iterator it = Find(v.begin(), v.end(), elementToFind);
    if (it != v.end()) {
        cout << "Элемент " << elementToFind << " найден на позиции: " << distance(v.begin(), it) << endl;
    } else {
        cout << "Элемент " << elementToFind << " не найден." << endl;
    }

    return 0;
}

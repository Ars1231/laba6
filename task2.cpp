#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator findInSorted(vector<int>::iterator first, vector<int>::iterator last, int el) {
    while (first < last) {
        vector<int>::iterator mid = first + (last - first) / 2; 
        if (*mid < el) {
            first = mid + 1;
        } else if (*mid > el) {
            last = mid;
        } else {
            return mid; 
        }
    }
    return last; 
}

int main() {
    vector<int> v; 
    int n;
    cout << "Введите количество элементов вектора: ";
    cin >> n;
    cout << "Введите элементы вектора (они должны быть отсортированы): " << endl;
    for (int i = 0; i < n; ++i) {
        int element;
        cout << "Элемент " << (i + 1) << ": ";
        cin >> element;
        v.push_back(element);
    }
    int elementToFind;
    cout << "Введите элемент для поиска: ";
    cin >> elementToFind;

    vector<int>::iterator it = findInSorted(v.begin(), v.end(), elementToFind);

    if (it != v.end()) {
        cout << "Элемент " << *it << " найден." << endl;
    } else {
        cout << "Элемент не найден." << endl;
    }

    return 0;
}

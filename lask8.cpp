#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void plusesDeleter(std::vector<int>& v) {
    v.erase(std::remove_if(v.begin(), v.end(), [](int num) { 
    	return num > 0; 
    	}), v.end());
}

int main() {
    vector<int> v = {1, 0, -8, -9, 0, 10, 23, -7};
    plusesDeleter(v);
    cout << "Результат: ";
    for (int num : v) {
        cout << num << " ";
    }
    return 0;
}

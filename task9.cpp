#include <iostream>
#include <list>
using namespace std;

void qSort(std::list<int>& nums) {
    nums.sort(); 
    nums.reverse();
}

int main() {
    std::list<int> nums = {1, 5, 4, -3};
    qSort(nums);
    cout << "Результат: ";
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}

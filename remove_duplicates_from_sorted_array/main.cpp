#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    size_t size{nums.size()};
    // return 0 if nums is empty
    if (size == 0)
        return 0;
    for (size_t i{}; i < size - 1; i++)
    {
        for (size_t j{i + 1}; j < size; j++)
        {
            // remove duplicates
            if (nums[i] == nums[j])
            {
                nums.erase(nums.begin() + j);
                j--;
                size--;
            }
        }
    }
    return size;
}

int main()
{
    vector<int> nums{1, 1, 2};
    vector<int> nums2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums3{1, 1, 2, 2, 2, 2, 3, 4};
    vector<int> nums4;
    cout << removeDuplicates(nums) << endl;
    cout << removeDuplicates(nums2) << endl;
    cout << removeDuplicates(nums3) << endl;
    cout << removeDuplicates(nums4) << endl;
    return 0;
}
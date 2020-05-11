#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int length{};
    size_t size{nums.size()};
    vector<int> positions;
    for (size_t i{}; i < size; i++)
    {
        if (nums[i] == val)
        {
            // get positions
            positions.push_back(i);
        }
        else
        {
            length++;
        }
    }

    size = positions.size();
    for (size_t j{}; j < size; j++)
    {
        int x{positions[j]};
        // decrement every positions
        if (j != 0)
        {
            for (auto &p : positions)
            {
                p--;
            }
        }
        // remove element
        nums.erase(nums.begin() + positions[j]);
    }
    return length;
}

int main()
{
    vector<int> nums{3, 2, 2, 3};
    cout << removeElement(nums, 3) << endl;
    for (const auto &x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        int pivot = 0;

        if (nums[left] == target) {
            return left;
        }
        if (nums[right] == target) {
            return right;
        }

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            if (mid != 0 && nums[mid-1] > nums[mid]) {
                pivot = mid;
                break;
            }
            else if (mid != (nums.size()-1) && nums[mid+1] < nums[mid]) {
                pivot = mid + 1;
                break;
            }
            else if (nums[left] < nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        left = 0;
        right = nums.size() - 1;

        if (nums[pivot] == target) {
            return pivot;
        }
        else if (nums[right] < target) {
            while (left <= pivot) {
                int mid = left + ((pivot - left) / 2);

                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[left] == target) {
                    return left;
                }
                else if (nums[pivot] == target) {
                    return pivot;
                }
                else if (nums[mid] < target) {
                    left = mid + 1;
                }
                else {
                    pivot = mid - 1;
                }
            }
        }
        else {
            while (pivot <= right) {
                int mid = pivot + ((right - pivot) / 2);

                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[right] == target) {
                    return right;
                }
                else if (nums[pivot] == target) {
                    return pivot;
                }
                else if (nums[mid] < target) {
                    pivot = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int left_val = arr[left];
                int left_count = 0;
                while (left < right && arr[left] == left_val) {
                    ++left_count;
                    ++left;
                }

                int right_val = arr[right];
                int right_count = 0;
                while (left <= right && arr[right] == right_val) {
                    ++right_count;
                    --right;
                }

                count += left_count * right_count;
            }
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }

    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int first_pos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                first_pos = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (first_pos != -1) {
            left = first_pos;
            right = len - 1;
            int last_pos = first_pos;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    last_pos = mid;
                    left = mid + 1;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            count += (last_pos - first_pos + 1);
        }
    }

    return count;
}

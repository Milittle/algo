//
// Created by milittle on 2019-02-11.
//

#ifndef ALGO_SORT_H
#define ALGO_SORT_H


namespace algo{
    class Sort {
    public:
        static void bubble_sort(int *arr, int n){
            if (n <= 0){
                return;
            }

            bool sign = false;

            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n - i - 1; ++j){
                    if (arr[j] > arr[j + 1]){
                        int tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                        sign = true;
                    }
                }
                //if the arr is ordered then break
                if (!sign){
                    return;
                }
            }
        }

        static void insertion_sort(int *arr, int n){
            if (n <= 0){
                return;
            }

            int value = 0;
            for (int i = 1; i < n; ++i){
                value = arr[i];
                int j = i - 1;
                for (; j >= 0; --j){
                    if (arr[j] > value){
                        arr[j+1] = arr[j];
                    }else {
                        break;
                    }
                }
                arr[j + 1] = value;
            }
        }

        static void selection_sort(int *arr, int n){
            if (n <= 0){
                return;
            }

            int min_value = 0;
            int min_index = 0;

            for(int i = 0; i < n; ++i){
                min_value = arr[i];
                min_index = i;
                for (int j = i; j < n; ++j){
                    if (min_value > arr[j]){
                        min_index = j;
                        min_value = arr[j];
                    }
                }
                int tmp = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = tmp;
            }
        }

        static void merge_sort(int a[], int n){
            merge_sort_c(a, 0, n-1);
        }

        static void merge_sort_c(int a[], int p, int r){
            if (p >= r)
                return;

            int q = (p + r) / 2;

            merge_sort_c(a, p, q);
            merge_sort_c(a, q+1, r);

            merge(a, p, q, r);
        }

        static void merge(int a[], int p, int q, int r){
            int * tmp = new int[r - p + 1];
            int i, j, k;
            for ( i = p, j = q + 1, k = 0; i <= q && j <= r;){
                if (a[i] <= a[j]) // in order to stable
                    tmp[k++] = a[i++];
                else
                    tmp[k++] = a[j++];
            }

            if (i == q + 1) {
                for (; j <= r;)
                    tmp[k++] = a[j++];
            } else {
                for (; i <= q;)
                    tmp[k++] = a[i++];
            }

            for (int z = p; z <= r; ++z) {
                a[z] = tmp[z - p];
            }
            delete [] tmp;
        }

        static void quick_sort(int a[], int n){
            quick_sort_c(a, 0, n - 1);
        }

        static void quick_sort_c(int a[], int p, int r){
            if (p >= r)
                return;

            int q = partition(a, p, r);

            quick_sort_c(a, p, q - 1);
            quick_sort_c(a, q + 1, r);
        }

        static int partition(int a[], int p, int r){
            int pivot = a[r];
            int i = p;

            for ( int j = p; j <= r - 1; ++j){
                if (a[j] < pivot){
                    int tmp = a[j];
                    a[j] = a[i];
                    a[i] = tmp;
                    ++i;
                }
            }

            int tmp = a[i];
            a[i] = a[r];
            a[r] = tmp;

            return i;
        }

        static void heap_adjust(std::vector<int> & nums, int size, int k){
            int tmp = nums[k];
            int i = 2 * k + 1;
            while(i < size) {
                if (i + 1 < size && nums[i] > nums[i + 1]) {
                    ++i;
                }

                if (tmp < nums[i])
                    break;

                nums[k] = nums[i];
                k = i;
                i = 2 * k + 1;
            }
            nums[k] = tmp;
        }

        static void heap_sort(std::vector<int> & nums){
            int size = nums.size();

            if (size <= 1) return;

            for (int i = size / 2 - 1; i >= 0; --i){
                heap_adjust(nums, size, i);
            }

            for (int i = size - 1; i >= 0; --i){
                std::swap(nums[0], nums[i]);
                heap_adjust(nums, i, 0);
            }
        }
    };
 } //namespace algo




#endif //ALGO_SORT_H

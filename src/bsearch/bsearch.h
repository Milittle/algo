//
// Created by milittle on 2019-02-24.
//

#ifndef ALGO_BSEARCH_H
#define ALGO_BSEARCH_H

namespace algo{
    class bsearch {

        static int bbsearch(int a[], int n, int value){
            if (n <= 0)
                return -1;
            int low = 0;
            int high = n - 1;
            int mid;
            while (low <= high){
                mid = low + ((high - low) >> 1);
                if (a[mid] == value){
                    return mid;
                }else if(a[mid] < value){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            return -1;
        }

        static int bssearch(int a[], int n, int value){
            if (n <= 0){
                return -1;
            }
            return internal(a, 0, n - 1, value);
        }

        static int internal(int a[], int low, int high, int value){
            if (low > high)
                return - 1;
            int mid = low + ((high - low) >> 1);

            if (a[mid] == value){
                return mid;
            }else if(a[mid] < value){
                return internal(a, low, mid - 1, value);
            }else{
                return internal(a, mid + 1, high, value);
            }
        }


        // return the most left eq value's index
        static int bsearch1(int a[], int n, int value){
            if (n <= 0)
                return -1;

            int low = 0;
            int high = n - 1;
            int mid = -1;

            while (low <= high){
                mid = low + ((high - low) >> 1);
                if (a[mid] >= value){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }

            if (low < n && a[low] == value) return low;

            return -1;
        }

        static int bsearch11(int a[], int n, int value){
            if (n <= 0)
                return -1;

            int low = 0;
            int high = n - 1;
            int mid = -1;

            while (low <= high){
                mid = low + ((high - low) >> 1);
                if (a[mid] > value){
                    high = mid - 1;
                }else if (a[mid] < value){
                    low = mid + 1;
                }else{
                    if (mid == 0 || a[mid - 1] != value) return mid;
                    //else high = mid - 1; //this place can optimization the blow is optimized code.
                    else{
                        while(mid != 0 && a[mid - 1] == value){
                            mid -= 1;
                        }
                        return mid;
                    }
                }
            }

            return -1;
        }

        // return the most right eq value's index
        static int bsearch2(int a[], int n, int value){
            if (n <= 0)
                return -1;

            int low = 0;
            int high = n - 1;

            int mid = -1;
            while(low <= high){
                mid = low + ((high - low) >> 1);
                if (a[mid] <= value){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }

            if (high > 0 && a[high] == value) return high;

            return -1;
        }

        static int bsearch22(int a[], int n, int value){
            if (n <= 0)
                return -1;

            int low = 0;
            int high = n - 1;
            int mid = -1;

            while (low <= high){
                mid = low + ((high - low) >> 1); // overcome the data overflow

                if (a[mid] > value){
                    high = mid - 1;
                }else if (a[mid] < value){
                    low = mid + 1;
                }else{
                    if (mid == n - 1 || a[mid + 1] != value) return mid;
                    //else low = mid + 1;
                    //can optimize the else code
                    else {
                        while (mid != n - 1 && a[mid + 1] == value){
                            mid += 1;
                        }
                        return mid;
                    }
                }
            }
            return -1;
        }

        // return the first eq value's index

        static int bsearch3(int a[], int n, int value){
            if (n <= 0)
                return -1;

            int low = 0;
            int high = n - 1;
            int mid = -1;
            while (low <= high){
                mid = low + ((high - low) >> 1);
                if (a[mid] >= value){
                    if (mid == 0 || a[mid - 1] < value) return mid;
                    else high = mid - 1;
                }else {
                    low = mid + 1;
                }
            }
            return -1;
        }

        static int bsearch4(int a[], int n, int value){
            if (n <= 0)
                return -1;

            int low = 0;
            int high = n - 1;
            int mid = -1;
            while (low <= high){
                mid = low + ((high - low) >> 1);
                if (a[mid] > value){
                    high = mid - 1;
                }else {
                    if ( mid == n - 1 || a[mid + 1] > value) return mid;
                    else low = mid + 1;
                }
            }
            return -1;
        }
    };
} //namespace algo



#endif //ALGO_BSEARCH_H

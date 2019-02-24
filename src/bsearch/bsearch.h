//
// Created by milittle on 2019-02-24.
//

#ifndef ALGO_BSEARCH_H
#define ALGO_BSEARCH_H

namespace algo{
    class bsearch {

        static int bsearch(int []a, int n, int value){

            if (n <= 0)
                return;
            int low = 0;
            int high = n - 1;
            int mid;
            while (low <= high){
                mid = (high - low) / 2;
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

        static int bssearch(int []a, int n, int value){
            if (n <= 0){
                return -1;
            }
            return internal(a, 0, n - 1, value);
        }

        static int internal(int []a, int low, int high, int value){
            if (low > high)
                return - 1;
            int mid = low + ((high - low) >> 2);

            if (a[mid] == value){
                return mid;
            }else if(a[mid] < value){
                return internal(a, low, mid - 1, value);
            }else{
                return internal(a, mid + 1, high, value);
            }
        }
    };
} //namespace algo



#endif //ALGO_BSEARCH_H

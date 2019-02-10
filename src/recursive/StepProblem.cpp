//
// Created by milittle on 2019-02-10.
//

#include <map>

namespace algo{
    int ste_problem(int n){
        if (n <= 0) return 1;

        if (n == 1) return 1;
        if (n == 2) return 2;

        return ste_problem(n - 1) + ste_problem(n - 2);
    }


    std::map<int, int> global_map_;
    long long step_problem1(int n){
        if (n <= 0){
            return 1;
        }

        if (n == 1){
            return 1;
        }

        if (n == 2){
            return 2;
        }

        auto it = global_map_.find(n);
        if (it != global_map_.end()) return it->second;

        long long tmp = step_problem1(n - 1) + ste_problem1(n - 2);

        global_map_.insert(std::make_pair(n, tmp));

        return tmp;

    }
}

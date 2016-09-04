//
//  bucket_sort.hpp
//  Algorithm
//
//  Created by dtysky on 16/8/31.
//  Copyright © 2016年 dtysky@outlook.com. All rights reserved.
//

#include <iostream>
#include "radix_sort.h"
#include "utils.hpp"


namespace my_algorithm {
    using std::cout;
    using std::endl;
    using std::vector;
    
    void testRadixSort(){
        auto v1 = vector<uint32_t>({10000, 5694, 998, 233, 47, 9, 0});
        radixSort(v1, 5, 10);
        printVector<uint32_t>(v1);
        radixSort(v1, 5, 10, true);
        printVector<uint32_t>(v1);
    }
}
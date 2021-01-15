#include <cstdlib>
#include <istream>
#include <fstream>
#include <iostream>
#include <vector>
#include "../includes/image.h"

namespace NaiveBayes {
    Image::Image(const std::string & img_string) {
        for (size_t i = 0; i < kImageSize; ++i) {
            for (size_t j = 0; j < kImageSize; ++j) {
                if (img_string[i * kImageSize + j] == '#' || img_string[i * kImageSize + j] == '+') {
                    pixels[i][j] = 1;
                } else {
                    pixels[i][j] = 0;
                }
            }
        }
    }
} 

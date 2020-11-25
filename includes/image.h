// CS 128 - Naive Bayes

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <cstdlib>
#include <istream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

namespace NaiveBayes {
  // 28 * 28 pixels is an image
  constexpr size_t kImageSize = 28;

  class Image {

    public:
    
      /**
      * Constructor for the Image class. Initializes an image containing an
      * array of pixels representing whether or not a pixel is shaded
      *
      * @param img_string a string to be parsed that contains 
      *   the pixels for the image of size 28 * 28
      */

      Image(const std::string &img_string);

    /**
      * Array representing pixels. Values are 0 if the pixel is unshaded, 1
      * if the pixel is shaded for the corresponding location [][].
      */

      int pixels[kImageSize][kImageSize];
  };
} 
#endif

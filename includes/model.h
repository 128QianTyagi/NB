// CS 128 - Naive Bayes

#ifndef _MODEL_H_
#define _MODEL_H_

#include <cstdlib>
#include <vector>

#include "image.h"

namespace NaiveBayes {

// From 0-9 inclusive.

constexpr size_t kNumClasses = 10;

// Either white or black (shaded/not shaded).

constexpr size_t kNumShades = 2;

// The index representing an unshaded pixel

const int kUnshadedIndex = 0;

// The index representing a shaded pixel

const int kShadedIndex = 1;

// Laplace smoothing constant

const double kLaplaceConstant = 0.3;

/**
 * Naive Bayes classification model to determine the
 * probability that a specific pixel for an individual
 * class is white or black.
 */

class Model {
  public:
  /**
   * Constructor for the Model class. Declares the array of images from
   * the training file and uses Probabilities() to create the
   * probabilities array
   *
   * @param labels_file file - Contains the labels corresponding to the
   *        provided images
   * @param training_file - containing the images to train the model on
   */

  Model(std::istream &lables, std::istream &train);

  /**
   * Used by the constructor to calculate the probabilities of the model
   *
   * @param labels -  string that has all the labels corresponding
   *        to the training images
   */
  int Probabilities(const std::string &labels);

  /**
   * Retrieve image list for testing
   *
   * @return the list of images provided by the constructor
   */
  std::vector<NaiveBayes::Image> ImageList();

  /**
   * Overloaded insertion Operator for a Model object.
   * Writes the model to a provided file.
   *
   * @param output - the output to write to
   * @param model - the Model object
   */

  friend std::ostream &operator<<(std::ostream &output, const Model &model);

 private:
  // The list of Images representing each image for given file
  std::vector<NaiveBayes::Image> image_list;

  /**
   * The individual probabilities for each pixel for each class for
   * whether it's shaded or not.
   *
   * Examples:
   *
   * prob[0][0][0][1] is the computed probability that a pixel at
   * [0][0] for class 0 is black (shaded).
   *
   * prob[2][10][7][0] is the computed probability that a pixel at
   * [2][10] for class 7 is white (not shaded).
   */
  double prob[kImageSize][kImageSize][kNumClasses][kNumShades];

  // The array containing priors for each class. Array index corresponds to the
  // class.

  double priors[kNumClasses];
};
}  // namespace NaiveBayes

#endif

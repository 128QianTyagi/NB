#ifndef _CLASSIFIER_H_
#define _CLASSIFIER_H_

#include <istream>

#include "image.h"
#include "model.h"

namespace NaiveBayes {

class Classifier {
 public:
  /**
   * Constructor for the classifier class based on a given model and a
   * file with images to classify.
   *
   * @param model - Model file to be loaded
   * @param images - file with images to classify
   */

  Classifier(std::istream &model, std::istream &images);

  /**
   * Classifies the probability that a pixel will be shaded in every pixel
   * and then selects the most-likely number for the image to represent.
   *
   * @return the vector containing the in-order classifications.
   */

  std::vector<int> Classify();

  /**
   * Calculates the accuracy of a classifier. Used
   * to compare results of the classificaiton against the testing labels.
   *
   * @return a percentage rounded to the nearest half % representing
   * classification accuracy.
   */

  double Accuracy(const std::vector<int> &classifications,
                  std::istream &labels_file);

  /**
   * Writes the classifications to a file to be used by
   * user - useful source of debugging.
   *
   * @param classifications_file - file to write the classifications to
   * @param classifications - vector with classifications results
   */

  int Write_Classifications(std::ostream &classifications_file,
                            const std::vector<int> &classifications);

  /**
   * Retrieves the image list used in testing
   *
   * @return list of images made by the constructor
   */

  std::vector<Image> ImageList();

 private:
  /**
   * Splits a line containing a string of numbers separated by a space.
   * returns an array containing those numbers as doubles.
   *
   * @param line - the line to be split by spaces
   * @return vector of doubles representing the numbers in the given line
   */

  std::vector<double> split(const std::string &line);

  /**
   * Array containing the logs of the probabilities.
   * Filled in constructor.
   */

  double prob_logs[kImageSize][kImageSize][kNumClasses][kNumShades];

  /** List of Images representing each image in the given file */

  std::vector<NaiveBayes::Image> image_list;

  /** Array of priors used to calculate the probability for an image */

  std::vector<double> priors;
};
}  // namespace NaiveBayes

#endif

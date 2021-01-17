#include "../includes/image.h"
#include "../includes/model.h"

namespace NaiveBayes {
  Model::Model(std::istream & lables, std::istream & train) {
    std::string image_line;
    std::string image = "";
    while (std::getline(train, image_line)) {
      image += image_line;
      if (image.length() == kImageSize * kImageSize) {
        // Process image
        image_list.push_back(Image(image));
        image = "";
      }
    }

    // Process labels
    std::string label_line;
    std::string labels = "";
    while (std::getline(lables, label_line)) {
      labels += label_line;
    }
    Probabilities(labels);
  }

  std::vector<Image> Model::ImageList() {
    return image_list;
  }

  int Model::Probabilities(const std::string & labels) {
    // compute priors first: P(class = c) = occurrences of c in training data/ total training size
    std::unordered_map<int, int> map;

    for (size_t i = 0; i < labels.length(); ++i) {
      map[labels[i] - '0']++;
    }
    for (auto i = map.begin(); i != map.end(); ++i) {
      priors[i->first] = ((double) i->second / (double) labels.length());
    }

    // Compute pixel probabilities
    for (size_t i = 0; i < image_list.size(); ++i) {
      for (int j = 0; j < kImageSize; ++j) {
        for (int k = 0; k < kImageSize; ++k) {
          if (image_list[i].pixels[j][k] == 1)
            prob[j][k][labels[i] - '0'][kShadedIndex]++;
          else 
            prob[j][k][labels[i] - '0'][kUnshadedIndex]++;
        }
      }
    }

    for (size_t i = 0; i < kImageSize; ++i) {
      for (size_t j = 0; j < kImageSize; ++j) {
        for (size_t c = 0; c < kNumClasses; ++c) {
          for (size_t k = 0; k < kNumShades; ++k) {
            prob[i][j][c][k] = (kLaplaceConstant + prob[i][j][c][k]) / (kNumClasses * kLaplaceConstant + map[c]);
          }
        }
      }
    }
    return 0;
  }

  std::ostream & operator<<(std::ostream & output, const Model & model) {
    for (size_t i = 0; i < kNumClasses; ++i) {
      output << model.priors[i];
    }
    output << "\n";

    for (size_t i = 0; i < kImageSize; ++i) {
      for (int j = 0; j < kImageSize; j++) {
                for (int k = 0; k < kNumClasses; k++) {
                    for (int z = 0; z < kNumShades; z++) {
                        output << std::to_string(i) << " ";
                        output << std::to_string(j) << " ";
                        output << std::to_string(k) << " ";
                        output << std::to_string(z) << " ";
                        output << (model.prob[i][j][k][z]) << " "; 
                    }
                }
            }
    }
    return output;
  }
}


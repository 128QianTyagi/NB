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
    return 0;
  }
}


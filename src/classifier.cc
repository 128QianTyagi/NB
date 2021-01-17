#include "../includes/image.h"
#include "../includes/model.h"
#include "../includes/classifier.h"
namespace NaiveBayes {
	Classifier::Classifier(std::istream & model, std::istream & images) {
		// read in model and fill out prob_logs
		std::string line;
		while (std::getline(model, line)) {
			std::vector<double> data = split(line);
			if (data.size() == 1) {
				// We are processing priors 
				priors.push_back(data[0]);
			} else if (data.size() == 5) {
				// We are processing probabilities
				prob_logs[(int) data[0]][(int) data[1]][(int)data[2]][(int)data[3]] = log(data[4]);
			}
		}

		std::string image_line;
		std::string image_src = "";

		while (std::getline(images, image_line)) {
			image_src += image_line;
			if (image_src.length() >= kImageSize * kImageSize) {
				image_list.push_back(Image(image_src));
				image_src = "";
			}
		}
	}

	std::vector<double> Classifier::split(const std::string & line) {
		std::vector<double> data;
	    size_t pos = 0;
	    std::string token;
	    std::string input = line;

	    while ((pos = input.find(' ')) != std::string::npos) {
	        token = input.substr(0, pos);
	        data.push_back(std::stod(token));
	        input.erase(0, pos + 1);
	    }
	    if (input.length() > 0)
	    	data.push_back(std::stod(input));
	    return data;
	}

	std::vector<int> Classifier::Classify() {
		std::vector<int> classifications;

		for (const Image & img : image_list) {
			std::vector<double> sum = std::vector<double>(kNumClasses);
			for (size_t k = 0; k < kNumClasses; ++k) {
				for (size_t i = 0; i < kImageSize; ++i) {
					for (size_t j = 0; j < kImageSize; ++j) {
						sum[k] += prob_logs[i][j][k][img.pixels[i][j]];
					}
				}
			}

			// find max
			double max = sum[0];
			int max_index = 0;

			for (size_t i = 1; i < kNumClasses; ++i) {
				if (sum[i] > max) {
					max = sum[i];
					max_index = i;
				}
				// std::cout << sum[i] << "\n";
			}

			classifications.push_back(max_index);
		}
		return classifications;
	}

	double Classifier::Accuracy(const std::vector<int> &classifications, std::istream &labels_file) {
		std::string line;
		int success = 0;
		int counter = 0;

		while (std::getline(labels_file, line)) {
			if (classifications[counter] == std::stoi(line))
				success++;
			counter++;
			// std::cout << classifications[counter] << " == " << line << "\n";
		}
		std::cout << success << " , " << counter << "\n";
		std::cout << round(((double) success / (double) counter) * 100) << "\n";
		return round(((double) success / (double) counter) * 100);
	}

	std::vector<Image> Classifier::ImageList() {
		return image_list;
	}
}
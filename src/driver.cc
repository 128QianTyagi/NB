#include <iostream>

#include "../includes/classifier.h"
#include "../includes/image.h"
#include "../includes/model.h"

#define TRAIN 0

int main(int argc, char* argv[]) {
	std::ifstream traininglabels_ifstream("data/traininglabels");
	std::ifstream trainingimages_ifstream("data/trainingimages");
	std::istream & traininglabels = traininglabels_ifstream;
	std::istream & trainingimages = trainingimages_ifstream;

	std::ifstream testinglabels_ifstream("data/testlabels");
	std::ifstream testingimages_ifstream("data/testimages");
	std::istream & testinglabels = traininglabels_ifstream;
	std::istream & testingimages = trainingimages_ifstream;

	#if TRAIN == 1
	NaiveBayes::Model model(traininglabels, trainingimages);
	std::ofstream out_stream("data/TrainedModelTest_a.txt");
  	std::ostream & out = out_stream;
  	out << model;

  	#endif
  	#if TRAIN == 0
	std::ifstream inf_stream("data/TrainedModelTest_a.txt");
  	std::istream & model_s = inf_stream;
  	NaiveBayes::Classifier classifier(model_s, testingimages);
  	std::vector<int> vec = classifier.Classify();
  	std::cout << classifier.Accuracy(vec, testinglabels);
  	#endif
	return 0; 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                  MP : Seam Carver  : Student Test Cases                  //
//                                                                          //
// Written By :                         Environment :                       //
// Date ......:                         Compiler ...:                       //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up                             //
//////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

//////////////////////////////////////////////////////////////////////////////
//                                 Includes                                 //
//////////////////////////////////////////////////////////////////////////////
#include "../includes/classifier.h"
#include "../includes/image.h"
#include "../includes/model.h"

//////////////////////////////////////////////////////////////////////////////
//                                Test Cases                                //
//////////////////////////////////////////////////////////////////////////////
// Test Image ---------------------------------------- //

TEST_CASE("Image pixels Test 1", "[constructed array]") {
  NaiveBayes::Image image(" # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "                            "
                     "############################"
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "++++++++++++++++++++++++++++");
  REQUIRE(image.pixels[0][0] == 0);
  REQUIRE(image.pixels[0][1] == 1);
  REQUIRE(image.pixels[0][2] == 0);
  REQUIRE(image.pixels[0][3] == 1);
  REQUIRE(image.pixels[1][0] == 0);
  REQUIRE(image.pixels[1][3] == 1);
  REQUIRE(image.pixels[2][0] == 0);
  REQUIRE(image.pixels[2][3] == 1);
  REQUIRE(image.pixels[3][0] == 0);
  REQUIRE(image.pixels[3][3] == 0);
  REQUIRE(image.pixels[4][0] == 1);
  REQUIRE(image.pixels[4][1] == 1);
  REQUIRE(image.pixels[4][2] == 1);
  REQUIRE(image.pixels[4][3] == 1);
  REQUIRE(image.pixels[4][4] == 1);
  REQUIRE(image.pixels[4][14] == 1);
  REQUIRE(image.pixels[4][15] == 1);
  REQUIRE(image.pixels[4][27] == 1);
  REQUIRE(image.pixels[5][24] == 0);
  REQUIRE(image.pixels[27][2] == 1);
  REQUIRE(image.pixels[27][5] == 1);
  REQUIRE(image.pixels[27][22] == 1);
  REQUIRE(image.pixels[27][23] == 1);
  REQUIRE(image.pixels[27][27] == 1);
}

TEST_CASE("Image pixels Test 2", "[constructed array]") {
  NaiveBayes::Image image(" # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "                            "
                     "############################"
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "++++++++++++++++++++++++++++");
  REQUIRE(image.pixels[0][0] == 0);
  REQUIRE(image.pixels[0][1] == 1);
  REQUIRE(image.pixels[0][2] == 0);
  REQUIRE(image.pixels[0][3] == 1);
  REQUIRE(image.pixels[1][0] == 0);
  REQUIRE(image.pixels[1][3] == 1);
  REQUIRE(image.pixels[2][0] == 0);
  REQUIRE(image.pixels[2][3] == 1);
  REQUIRE(image.pixels[3][0] == 0);
  REQUIRE(image.pixels[3][3] == 0);
  REQUIRE(image.pixels[4][0] == 1);
  REQUIRE(image.pixels[4][1] == 1);
  REQUIRE(image.pixels[4][2] == 1);
  REQUIRE(image.pixels[4][3] == 1);
  REQUIRE(image.pixels[4][4] == 1);
  REQUIRE(image.pixels[4][14] == 1);
  REQUIRE(image.pixels[4][15] == 1);
  REQUIRE(image.pixels[4][27] == 1);
  REQUIRE(image.pixels[5][24] == 0);
  REQUIRE(image.pixels[27][2] == 1);
  REQUIRE(image.pixels[27][5] == 1);
  REQUIRE(image.pixels[27][22] == 1);
  REQUIRE(image.pixels[27][23] == 1);
  REQUIRE(image.pixels[27][27] == 1);
}

TEST_CASE("Image pixels Test 3", "[constructed array]") {
  NaiveBayes::Image image(" # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "                            "
                     "############################"
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "++++++++++++++++++++++++++++");
  REQUIRE(image.pixels[0][0] == 0);
  REQUIRE(image.pixels[0][1] == 1);
  REQUIRE(image.pixels[0][2] == 0);
  REQUIRE(image.pixels[0][3] == 1);
  REQUIRE(image.pixels[1][0] == 0);
  REQUIRE(image.pixels[1][3] == 1);
  REQUIRE(image.pixels[2][0] == 0);
  REQUIRE(image.pixels[2][3] == 1);
  REQUIRE(image.pixels[3][0] == 0);
  REQUIRE(image.pixels[3][3] == 0);
  REQUIRE(image.pixels[4][0] == 1);
  REQUIRE(image.pixels[4][1] == 1);
  REQUIRE(image.pixels[4][2] == 1);
  REQUIRE(image.pixels[4][3] == 1);
  REQUIRE(image.pixels[4][4] == 1);
  REQUIRE(image.pixels[4][14] == 1);
  REQUIRE(image.pixels[4][15] == 1);
  REQUIRE(image.pixels[4][27] == 1);
  REQUIRE(image.pixels[5][24] == 0);
  REQUIRE(image.pixels[27][2] == 1);
  REQUIRE(image.pixels[27][5] == 1);
  REQUIRE(image.pixels[27][22] == 1);
  REQUIRE(image.pixels[27][23] == 1);
  REQUIRE(image.pixels[27][27] == 1);
}

TEST_CASE("Image pixels Test 4", "[constructed array]") {
  NaiveBayes::Image image(" # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "                            "
                     "############################"
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "++++++++++++++++++++++++++++");
  REQUIRE(image.pixels[0][0] == 0);
  REQUIRE(image.pixels[0][1] == 1);
  REQUIRE(image.pixels[0][2] == 0);
  REQUIRE(image.pixels[0][3] == 1);
  REQUIRE(image.pixels[1][0] == 0);
  REQUIRE(image.pixels[1][3] == 1);
  REQUIRE(image.pixels[2][0] == 0);
  REQUIRE(image.pixels[2][3] == 1);
  REQUIRE(image.pixels[3][0] == 0);
  REQUIRE(image.pixels[3][3] == 0);
  REQUIRE(image.pixels[4][0] == 1);
  REQUIRE(image.pixels[4][1] == 1);
  REQUIRE(image.pixels[4][2] == 1);
  REQUIRE(image.pixels[4][3] == 1);
  REQUIRE(image.pixels[4][4] == 1);
  REQUIRE(image.pixels[4][14] == 1);
  REQUIRE(image.pixels[4][15] == 1);
  REQUIRE(image.pixels[4][27] == 1);
  REQUIRE(image.pixels[5][24] == 0);
  REQUIRE(image.pixels[27][2] == 1);
  REQUIRE(image.pixels[27][5] == 1);
  REQUIRE(image.pixels[27][22] == 1);
  REQUIRE(image.pixels[27][23] == 1);
  REQUIRE(image.pixels[27][27] == 1);
}

TEST_CASE("Image pixels Test 5", "[constructed array]") {
  NaiveBayes::Image image(" # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "                            "
                     "############################"
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     " # + ++++++++++++++         "
                     "++++++++++++++++++++++++++++");
  REQUIRE(image.pixels[0][0] == 0);
  REQUIRE(image.pixels[0][1] == 1);
  REQUIRE(image.pixels[0][2] == 0);
  REQUIRE(image.pixels[0][3] == 1);
  REQUIRE(image.pixels[1][0] == 0);
  REQUIRE(image.pixels[1][3] == 1);
  REQUIRE(image.pixels[2][0] == 0);
  REQUIRE(image.pixels[2][3] == 1);
  REQUIRE(image.pixels[3][0] == 0);
  REQUIRE(image.pixels[3][3] == 0);
  REQUIRE(image.pixels[4][0] == 1);
  REQUIRE(image.pixels[4][1] == 1);
  REQUIRE(image.pixels[4][2] == 1);
  REQUIRE(image.pixels[4][3] == 1);
  REQUIRE(image.pixels[4][4] == 1);
  REQUIRE(image.pixels[4][14] == 1);
  REQUIRE(image.pixels[4][15] == 1);
  REQUIRE(image.pixels[4][27] == 1);
  REQUIRE(image.pixels[5][24] == 0);
  REQUIRE(image.pixels[27][2] == 1);
  REQUIRE(image.pixels[27][5] == 1);
  REQUIRE(image.pixels[27][22] == 1);
  REQUIRE(image.pixels[27][23] == 1);
  REQUIRE(image.pixels[27][27] == 1);
}

TEST_CASE("Model constructor", "[Image array created]") {
  std::ifstream model_a("data/sampleimages");
  std::ifstream labels("data/samplelabels");
  std::istream & i = model_a;
  std::istream & l = labels;
  NaiveBayes::Model model = NaiveBayes::Model(l, i);
  REQUIRE(model.ImageList().size() == 3);
}

TEST_CASE("Insertion operator", "[TrainedModel.txt written]") {
  std::ifstream model_a("data/sampleimages");
  std::ifstream labels("data/samplelabels");
  std::istream &i = model_a;
  std::istream &l = labels;
  NaiveBayes::Model model(l, i);
  std::ofstream out_stream("data/TrainedModelTest.txt");
  std::ostream & out = out_stream;
  out << model;
  std::ifstream input("data/TrainedModelTest.txt");
  std::istream & stream = input;
  std::string line = "";
  std::getline(stream, line);
  REQUIRE(line.length() != 0);
}
//////////////////////////////////////////////////////////////////////////////
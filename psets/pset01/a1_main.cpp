#include "a1.h"

using namespace std;

// This is a way for you to test your functions. 
// We will only grade the contents of a0.cpp and Image.cpp
int main() {
	Image input = Image("../Input/castle_small.png");
	Image output1 = brightness(input, 1.2);
	Image output2 = contrast(input, 2.0);
	Image output3 = color2gray(input);
	std::vector<Image> outputs = lumiChromi(input);
	Image output4 = brightnessContrastLumi(input, 1.5, 2);
	Image output5 = saturate(input, 1.5);
	output1.write("../Output/boston_brightness.png");
	output2.write("../Output/boston_high_contrast.png");
	output3.write("../Output/boston_gray.png");
	output4.write("../Output/boston_brightness_contrast_lumi.png");
	output5.write("../Output/boston_saturate.png");
	outputs[0].write("../Output/boston_lumi.png");
	outputs[1].write("../Output/boston_chrom.png");
}

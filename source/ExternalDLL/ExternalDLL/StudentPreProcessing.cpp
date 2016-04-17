#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
    /*IntensityImage &imageIntesity(image.getWidth * image.getHeight);
    for (int i = 0; i < image.getHeight; ++i){
        for (int j = 0; j < image.getWidth; ++j){
            RGB rgbConvert = image.getPixel(j, i);

            Intensity IntensityConvert = (rgbConvert.r + rgbConvert.g + rgbConvert.b / 3);
            imageIntesity.setPixel(j, i, IntensityConvert);
        }
    }*/


    //return &imageIntesity;
return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}
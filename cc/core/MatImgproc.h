#include "Mat.h"
#include <opencv2/imgproc.hpp>
#include "imgproc/Moments.h"
#include "imgproc/Contour.h"
#include "TermCriteria.h"

#ifndef __FF_MATIMGPROC_H__
#define __FF_MATIMGPROC_H__

class MatImgproc {
public:
  static void Init(v8::Local<v8::FunctionTemplate> ctor);

  static NAN_METHOD(DrawContours);
  static NAN_METHOD(Rescale);
  static NAN_METHOD(RescaleAsync);
  static NAN_METHOD(Resize);
  static NAN_METHOD(ResizeAsync);
  static NAN_METHOD(ResizeToMax);
  static NAN_METHOD(ResizeToMaxAsync);
  static NAN_METHOD(Threshold);
  static NAN_METHOD(ThresholdAsync);
  static NAN_METHOD(AdaptiveThreshold);
  static NAN_METHOD(AdaptiveThresholdAsync);
  static NAN_METHOD(InRange);
  static NAN_METHOD(InRangeAsync);
  static NAN_METHOD(CvtColor);
  static NAN_METHOD(CvtColorAsync);
  static NAN_METHOD(BgrToGray);
  static NAN_METHOD(BgrToGrayAsync);
  static NAN_METHOD(WarpAffine);
  static NAN_METHOD(WarpAffineAsync);
  static NAN_METHOD(WarpPerspective);
  static NAN_METHOD(WarpPerspectiveAsync);
  static NAN_METHOD(Erode);
  static NAN_METHOD(ErodeAsync);
  static NAN_METHOD(Dilate);
  static NAN_METHOD(DilateAsync);
  static NAN_METHOD(MorphologyEx);
  static NAN_METHOD(MorphologyExAsync);
  static NAN_METHOD(DistanceTransform);
  static NAN_METHOD(DistanceTransformAsync);
  static NAN_METHOD(DistanceTransformWithLabels);
  static NAN_METHOD(DistanceTransformWithLabelsAsync);
  static NAN_METHOD(Blur);
  static NAN_METHOD(BlurAsync);
  static NAN_METHOD(GaussianBlur);
  static NAN_METHOD(GaussianBlurAsync);
  static NAN_METHOD(MedianBlur);
  static NAN_METHOD(MedianBlurAsync);
  static NAN_METHOD(ConnectedComponents);
  static NAN_METHOD(ConnectedComponentsAsync);
  static NAN_METHOD(ConnectedComponentsWithStats);
  static NAN_METHOD(ConnectedComponentsWithStatsAsync);
  static NAN_METHOD(GrabCut);
  static NAN_METHOD(GrabCutAsync);
  static NAN_METHOD(Watershed);
  static NAN_METHOD(WatershedAsync);
  static NAN_METHOD(_Moments);
  static NAN_METHOD(_MomentsAsync);
  static NAN_METHOD(FindContours);
  static NAN_METHOD(FindContoursAsync);
  static NAN_METHOD(DrawLine);
  static NAN_METHOD(DrawArrowedLine);
  static NAN_METHOD(DrawRectangle);
  static NAN_METHOD(DrawCircle);
  static NAN_METHOD(DrawEllipse);
  static NAN_METHOD(DrawPolylines);
  static NAN_METHOD(DrawFillPoly);
  static NAN_METHOD(DrawFillConvexPoly);
  static NAN_METHOD(PutText);
  static NAN_METHOD(MatchTemplate);
  static NAN_METHOD(MatchTemplateAsync);
  static NAN_METHOD(Canny);
  static NAN_METHOD(CannyAsync);
  static NAN_METHOD(Sobel);
  static NAN_METHOD(SobelAsync);
  static NAN_METHOD(Scharr);
  static NAN_METHOD(ScharrAsync);
  static NAN_METHOD(Laplacian);
  static NAN_METHOD(LaplacianAsync);
  static NAN_METHOD(PyrDown);
  static NAN_METHOD(PyrDownAsync);
  static NAN_METHOD(PyrUp);
  static NAN_METHOD(PyrUpAsync);
  static NAN_METHOD(BuildPyramid);
  static NAN_METHOD(BuildPyramidAsync);
  static NAN_METHOD(HoughLines);
  static NAN_METHOD(HoughLinesAsync);
  static NAN_METHOD(HoughLinesP);
  static NAN_METHOD(HoughLinesPAsync);
  static NAN_METHOD(HoughCircles);
  static NAN_METHOD(HoughCirclesAsync);
  static NAN_METHOD(EqualizeHist);
  static NAN_METHOD(EqualizeHistAsync);
  static NAN_METHOD(CompareHist);
  static NAN_METHOD(CompareHistAsync);
  static NAN_METHOD(FloodFill);
  static NAN_METHOD(FloodFillAsync);
  static NAN_METHOD(BilateralFilter);
  static NAN_METHOD(BilateralFilterAsync);
  static NAN_METHOD(BoxFilter);
  static NAN_METHOD(BoxFilterAsync);
  static NAN_METHOD(SqrBoxFilter);
  static NAN_METHOD(SqrBoxFilterAsync);
  static NAN_METHOD(Filter2D);
  static NAN_METHOD(Filter2DAsync);
  static NAN_METHOD(SepFilter2D);
  static NAN_METHOD(SepFilter2DAsync);
  static NAN_METHOD(CornerHarris);
  static NAN_METHOD(CornerHarrisAsync);
  static NAN_METHOD(CornerSubPix);
  static NAN_METHOD(CornerSubPixAsync);
  static NAN_METHOD(CornerMinEigenVal);
  static NAN_METHOD(CornerMinEigenValAsync);
  static NAN_METHOD(CornerEigenValsAndVecs);
  static NAN_METHOD(CornerEigenValsAndVecsAsync);
  static NAN_METHOD(Integral);
  static NAN_METHOD(IntegralAsync);
  static NAN_METHOD(Undistort);
  static NAN_METHOD(UndistortAsync);
  static NAN_METHOD(Remap);
  static NAN_METHOD(RemapAsync);
};

#endif
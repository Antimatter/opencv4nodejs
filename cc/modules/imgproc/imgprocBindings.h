#include "imgproc.h"

#ifndef __FF_IMGPROCBINDINGS_H_
#define __FF_IMGPROCBINDINGS_H_

namespace ImgprocBindings {

  struct GetTextSizeWorker : public CatchCvExceptionWorker {
  public:
    std::string text;
    int fontFace;
    double fontScale;
    int thickness;
  
    cv::Size2d returnValue;
    int baseLine;
  
    std::string executeCatchCvExceptionWorker() {
      returnValue = cv::getTextSize(text, fontFace, fontScale, thickness, &baseLine);
      return "";
    }
  
    v8::Local<v8::Value> getReturnValue() {
      v8::Local<v8::Object> ret = Nan::New<v8::Object>();
      Nan::Set(ret, Nan::New("size").ToLocalChecked(), Size::Converter::wrap(returnValue));
      Nan::Set(ret, Nan::New("baseLine").ToLocalChecked(), IntConverter::wrap(baseLine));
      return ret;
    }
  
    bool unwrapRequiredArgs(Nan::NAN_METHOD_ARGS_TYPE info) {
      return (
        StringConverter::arg(0, &text, info) ||
        IntConverter::arg(1, &fontFace, info) ||
        DoubleConverter::arg(2, &fontScale, info) ||
        IntConverter::arg(3, &thickness, info)
      );
    }
  };

  struct InitUndistortRectifyMapWorker : public CatchCvExceptionWorker {
  public:
    cv::Mat cameraMatrix;
    std::vector<double> distCoeffs;
    cv::Mat rectTransform;
    cv::Mat newCameraMatrix;
    cv::Size2d size;
    int m1type;

    cv::Mat map1, map2;
  
    std::string executeCatchCvExceptionWorker() {
      cv::initUndistortRectifyMap(cameraMatrix, distCoeffs, rectTransform, newCameraMatrix, size, m1type, map1, map2);
      return "";
    }
  
    v8::Local<v8::Value> getReturnValue() {
      v8::Local<v8::Object> ret = Nan::New<v8::Object>();
      Nan::Set(ret, Nan::New("map1").ToLocalChecked(), Mat::Converter::wrap(map1));
      Nan::Set(ret, Nan::New("map2").ToLocalChecked(), Mat::Converter::wrap(map2));
      return ret;
    }
  
    bool unwrapRequiredArgs(Nan::NAN_METHOD_ARGS_TYPE info) {
      return (
        Mat::Converter::arg(0, &cameraMatrix, info) ||
        DoubleArrayConverter::arg(1, &distCoeffs, info) ||
        Mat::Converter::arg(2, &rectTransform, info) ||
        Mat::Converter::arg(3, &newCameraMatrix, info) ||
        Size::Converter::arg(4, &size, info) ||
        IntConverter::arg(5, &m1type, info)
      );
    }
  };

}

#endif
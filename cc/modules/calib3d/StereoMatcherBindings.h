#include "StereoMatcher.h"

#ifndef __FF_STEREOMATCHERBINDINGS_H_
#define __FF_STEREOMATCHERBINDINGS_H_

namespace StereoMatcherBindings {

  struct ComputeWorker : public CatchCvExceptionWorker {
  public:
    cv::Ptr<cv::StereoMatcher> matcher;
    ComputeWorker(cv::Ptr<cv::StereoMatcher> _matcher) {
      this->matcher = _matcher;
    }

    cv::Mat left, right;
    cv::Mat disparity;

    std::string executeCatchCvExceptionWorker() {
      matcher->compute(left, right, disparity);
      return "";
    }

    bool unwrapRequiredArgs(Nan::NAN_METHOD_ARGS_TYPE info) {
      return (
        Mat::Converter::arg(0, &left, info)
        || Mat::Converter::arg(1, &right, info)
      );
    }

    FF_VAL getReturnValue() {
      return Mat::Converter::wrap(disparity);
    }
  };

}

#endif
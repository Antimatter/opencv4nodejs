#include "macros.h"
#include "StereoMatcher.h"

#ifndef FF_STEREOBM_H_
#define FF_STEREOBM_H_

class StereoBM : public StereoMatcher {
public:
    cv::Ptr<cv::StereoBM> matcher;

    static NAN_MODULE_INIT(Init);
    static NAN_METHOD(New);

	// static FF_GETTER(AGASTDetector, GetThreshold, detector->getThreshold());

    static Nan::Persistent<v8::FunctionTemplate> constructor;

	cv::Ptr<cv::StereoMatcher> getMatcher() {
		return matcher;
	}
};

#endif

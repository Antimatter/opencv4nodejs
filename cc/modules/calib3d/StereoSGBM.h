#include "macros.h"
#include "StereoMatcher.h"

#ifndef FF_STEREOSGBM_H_
#define FF_STEREOSGBM_H_

class StereoSGBM : public StereoMatcher {
public:
    cv::Ptr<cv::StereoSGBM> matcher;

    static NAN_MODULE_INIT(Init);
    static NAN_METHOD(New);

	// static FF_GETTER(StereoSGBM, GetThreshold, detector->getThreshold());

    static Nan::Persistent<v8::FunctionTemplate> constructor;

	cv::Ptr<cv::StereoMatcher> getMatcher() {
		return matcher;
	}
};

#endif

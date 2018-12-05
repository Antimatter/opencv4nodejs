#include "macros.h"
#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>
#include "Mat.h"
#include "CatchCvExceptionWorker.h"

#ifndef FF_STEREOMATCHER_H_
#define FF_STEREOMATCHER_H_

class StereoMatcher : public Nan::ObjectWrap {
public:
	virtual cv::Ptr<cv::StereoMatcher> getMatcher() = 0;

	static void Init(v8::Local<v8::FunctionTemplate> ctor);

	static NAN_METHOD(Compute);
	static NAN_METHOD(ComputeAsync);
};

#endif
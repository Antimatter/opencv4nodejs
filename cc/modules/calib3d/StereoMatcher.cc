#include "StereoMatcher.h"
#include "StereoMatcherBindings.h"

void StereoMatcher::Init(v8::Local<v8::FunctionTemplate> ctor) {
  Nan::SetPrototypeMethod(ctor, "compute", StereoMatcher::Compute);
  Nan::SetPrototypeMethod(ctor, "computeAsync", StereoMatcher::ComputeAsync);
};

NAN_METHOD(StereoMatcher::Compute) {
  FF::SyncBinding(
    std::make_shared<StereoMatcherBindings::ComputeWorker>(FF_UNWRAP(info.This(), StereoMatcher)->getMatcher()),
    "StereoMatcher::Compute",
    info
  );
}

NAN_METHOD(StereoMatcher::ComputeAsync) {
  FF::AsyncBinding(
    std::make_shared<StereoMatcherBindings::ComputeWorker>(FF_UNWRAP(info.This(), StereoMatcher)->getMatcher()),
    "StereoMatcher::ComputeAsync",
    info
  );
}

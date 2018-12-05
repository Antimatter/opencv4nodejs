#include "StereoSGBM.h"

Nan::Persistent<v8::FunctionTemplate> StereoSGBM::constructor;

NAN_MODULE_INIT(StereoSGBM::Init) {
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(StereoSGBM::New);
  v8::Local<v8::ObjectTemplate> instanceTemplate = ctor->InstanceTemplate();

  StereoMatcher::Init(ctor);
  constructor.Reset(ctor);
  ctor->SetClassName(Nan::New("StereoSGBM").ToLocalChecked());
  instanceTemplate->SetInternalFieldCount(1);

  //Nan::SetAccessor(instanceTemplate, Nan::New("threshold").ToLocalChecked(), StereoSGBM::GetThreshold);

  target->Set(Nan::New("StereoSGBM").ToLocalChecked(), ctor->GetFunction());
};

NAN_METHOD(StereoSGBM::New) {
  FF_METHOD_CONTEXT("StereoSGBM::New");

  // optional args
  bool hasOptArgsObj = FF_HAS_ARG(0) && info[0]->IsObject();
  FF_OBJ optArgs = hasOptArgsObj ? info[0]->ToObject() : FF_NEW_OBJ();

  FF_GET_INT_IFDEF(optArgs, int minDisparity, "minDisparity", 0);
  FF_GET_INT_IFDEF(optArgs, int numDisparities, "numDisparities", 16);
  FF_GET_INT_IFDEF(optArgs, int blockSize, "blockSize", 3);
  FF_GET_INT_IFDEF(optArgs, int P1, "P1", 0);
  FF_GET_INT_IFDEF(optArgs, int P2, "P2", 0);
  FF_GET_INT_IFDEF(optArgs, int disp12MaxDiff, "disp12MaxDiff", 0);
  FF_GET_INT_IFDEF(optArgs, int preFilterCap, "preFilterCap", 0);
  FF_GET_INT_IFDEF(optArgs, int uniquenessRatio, "uniquenessRatio", 0);
  FF_GET_INT_IFDEF(optArgs, int speckleWindowSize, "speckleWindowSize", 0);
  FF_GET_INT_IFDEF(optArgs, int speckleRange, "speckleRange", 0);
  FF_GET_INT_IFDEF(optArgs, int mode, "mode", cv::StereoSGBM::MODE_SGBM);

  if (!hasOptArgsObj) {
    FF_ARG_INT_IFDEF(0, minDisparity, minDisparity);
    FF_ARG_INT_IFDEF(1, numDisparities, numDisparities);
    FF_ARG_INT_IFDEF(2, blockSize, blockSize);
    FF_ARG_INT_IFDEF(3, P1, P1);
    FF_ARG_INT_IFDEF(4, P2, P2);
    FF_ARG_INT_IFDEF(5, disp12MaxDiff, disp12MaxDiff);
    FF_ARG_INT_IFDEF(6, preFilterCap, preFilterCap);
    FF_ARG_INT_IFDEF(7, uniquenessRatio, uniquenessRatio);
    FF_ARG_INT_IFDEF(8, speckleWindowSize, speckleWindowSize);
    FF_ARG_INT_IFDEF(9, speckleRange, speckleRange);
    FF_ARG_INT_IFDEF(10, mode, mode);
  }

  StereoSGBM* self = new StereoSGBM();
  self->Wrap(info.Holder());
  self->matcher = cv::StereoSGBM::create(
    minDisparity, numDisparities, blockSize, P1, P2, disp12MaxDiff,
    preFilterCap, uniquenessRatio, speckleWindowSize, speckleRange, mode
  );
  FF_RETURN(info.Holder());
}

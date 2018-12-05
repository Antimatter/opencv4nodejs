#include "StereoBM.h"

Nan::Persistent<v8::FunctionTemplate> StereoBM::constructor;

NAN_MODULE_INIT(StereoBM::Init) {
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(StereoBM::New);
  v8::Local<v8::ObjectTemplate> instanceTemplate = ctor->InstanceTemplate();

  StereoMatcher::Init(ctor);
  constructor.Reset(ctor);
  ctor->SetClassName(Nan::New("StereoBM").ToLocalChecked());
  instanceTemplate->SetInternalFieldCount(1);

  //Nan::SetAccessor(instanceTemplate, Nan::New("threshold").ToLocalChecked(), StereoBM::GetThreshold);

  target->Set(Nan::New("StereoBM").ToLocalChecked(), ctor->GetFunction());
};

NAN_METHOD(StereoBM::New) {
  FF_METHOD_CONTEXT("StereoBM::New");

  // optional args
  bool hasOptArgsObj = FF_HAS_ARG(0) && info[0]->IsObject();
  FF_OBJ optArgs = hasOptArgsObj ? info[0]->ToObject() : FF_NEW_OBJ();

  FF_GET_INT_IFDEF(optArgs, int numDisparities, "numDisparities", 0);
  FF_GET_INT_IFDEF(optArgs, int blockSize, "blockSize", 21);
  if (!hasOptArgsObj) {
    FF_ARG_INT_IFDEF(0, numDisparities, numDisparities);
    FF_ARG_INT_IFDEF(1, blockSize, blockSize);
  }

  StereoBM* self = new StereoBM();
  self->Wrap(info.Holder());
  self->matcher = cv::StereoBM::create(numDisparities, blockSize);
  FF_RETURN(info.Holder());
}

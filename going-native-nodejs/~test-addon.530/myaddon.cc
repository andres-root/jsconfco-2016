#include <nan.h>

using namespace v8;

NAN_METHOD(Print) {
	Nan::MaybeLocal<Number> maybeNum = Nan::To<Number>(info[2]);
    if (maybeNum.IsEmpty() == false) {
      Local<Number> num = maybeNum.ToLocalChecked();
      printf("%s\n", *String::Utf8Value("works!!!"));
    }
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New("print").ToLocalChecked(),
      Nan::GetFunction(Nan::New<FunctionTemplate>(Print)).ToLocalChecked());
}

NODE_MODULE(myaddon, Init);

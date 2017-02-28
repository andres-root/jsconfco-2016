#include <nan.h>

using namespace v8;

NAN_METHOD(Print) {
	// Nan::MaybeLocal<Number> maybeNum = Nan::To<Number>(info[2]);
	Nan::MaybeLocal<String> maybeStr = Nan::To<String>(info[0]);
    if (maybeStr.IsEmpty() == false) {
      Local<String> str = maybeStr.ToLocalChecked();
      printf("%s\n", *String::Utf8Value(str));
    }
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, Nan::New("print").ToLocalChecked(),
      Nan::GetFunction(Nan::New<FunctionTemplate>(Print)).ToLocalChecked());
}

NODE_MODULE(myaddon, Init);

#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "RF24Object.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  MyObject::Init(exports);
}

NODE_MODULE(RF24, InitAll)
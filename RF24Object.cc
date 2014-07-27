#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "RF24Object.h"

using namespace v8;

Persistent<Function> RF24Object::constructor;

RF24Object::RF24Object(uint8_t _cepin, uint8_t _cspin) : rf24(new RF24(_cepin, _cspin) {}

RF24Object::RF24Object(uint8_t _cepin, uint8_t _cspin, uint32_t spispeed) : rf24(new RF24(_cepin, _cspin, spispeed) {}

RF24Object::~RF24Object() 
{
	delete rf24;
}

void RF24Object::Init(Handle<Object> exports) 
{
	// Prepare constructor template
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::NewSymbol("RF24"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);
	// Prototype
	tpl->PrototypeTemplate()->Set(String::NewSymbol("begin"),FunctionTemplate::New(begin)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("startListening"),FunctionTemplate::New(startListening)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("stopListening"),FunctionTemplate::New(stopListening)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("available"),FunctionTemplate::New(available)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("read"),FunctionTemplate::New(read)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("openWritingPipe"),FunctionTemplate::New(openWritingPipe)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("openReadingPipe"),FunctionTemplate::New(openReadingPipe)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setRetries"),FunctionTemplate::New(setRetries)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setChannel"),FunctionTemplate::New(setChannel)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());	
	
	/*tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());
	tpl->PrototypeTemplate()->Set(String::NewSymbol("setPayloadSize"),FunctionTemplate::New(setPayloadSize)->GetFunction());*/
	
	constructor = Persistent<Function>::New(tpl->GetFunction());
	exports->Set(String::NewSymbol("RF24"), constructor);
}

Handle<Value> RF24Object::New(const Arguments& args) 
{
  HandleScope scope;

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new RF24Object(...)`
	uint8_t cepin, cspin;
	uint32_t spispeed;
	RF24Object* obj;
	if (args.Length() == 2)
	{
	    cepin = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
		cspin = args[1]->IsUndefined() ? 0 : args[1]->NumberValue();
		obj = new RF24Object(cepin, cspin);
	}
	else if (args.Length() == 3)
	{
		cepin = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
		cspin = args[1]->IsUndefined() ? 0 : args[1]->NumberValue();
		spispeed = args[2]->IsUndefined() ? 0 : args[2]->NumberValue();
		obj = new RF24Object(cepin, cspin, spispeed);
	}
     
    obj->Wrap(args.This());
    return args.This();
  } else {
    // Invoked as plain function `RF24Object(...)`, turn into construct call.
    const int argc = 2;
    Local<Value> argv[argc] = { args[0], args[1] };
    return scope.Close(constructor->NewInstance(argc, argv));
  }
}

//bool begin(void);
static v8::Handle<v8::Value> begin(const v8::Arguments& args)
{
	HandleScope scope;

	RF24Object* obj = ObjectWrap::Unwrap<RF24Object>(args.This());
	obj->rf24->begin();

	return scope.Close(Undefined());
}
	// void startListening(void);
static v8::Handle<v8::Value> startListening(const v8::Arguments& args)
{
	HandleScope scope;

	RF24Object* obj = ObjectWrap::Unwrap<RF24Object>(args.This());
	obj->rf24->startListening();

	return scope.Close(Undefined());
}
	//void stopListening(void);
static v8::Handle<v8::Value> stopListening(const v8::Arguments& args)
{
	HandleScope scope;

	RF24Object* obj = ObjectWrap::Unwrap<RF24Object>(args.This());
	obj->rf24->stopListening();

	return scope.Close(Undefined());
}
	// bool write( const void* buf, uint8_t len );
static v8::Handle<v8::Value> write(const v8::Arguments& args)
{
	HandleScope scope;

	RF24Object* obj = ObjectWrap::Unwrap<RF24Object>(args.This());
	Local<Object> bufferObj = args[0]->isUndefined() ? Undefined() : args[0]->ToObject();
	char * data = Buffer:Data(bufferObj);
	unint8_t len = args[1]->IsUndefined() ? 0 : args[1]->NumberValue();
	
	bool success = obj->rf24->write((char*)data, len);

	return scope.Close(Boolean::New(success));
}
//  bool available(void);
static v8::Handle<v8::Value> available(const v8::Arguments& args)
{
	HandleScope scope;

	RF24Object* obj = ObjectWrap::Unwrap<RF24Object>(args.This());
	bool success = obj->rf24->available();
	return scope.Close(Boolean::New(success));
}
//bool read( void* buf, uint8_t len );
static v8::Handle<v8::Value> read(const v8::Arguments& args)
{
	HandleScope scope;

	RF24Object* obj = ObjectWrap::Unwrap<RF24Object>(args.This());
	unint8_t len = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
	char * data = new char[len];
	bool success = obj->rf24->read((char*)data, len);
	
	return success ? scope.Close(Object::New(data)) : Undefined();
}
//void openWritingPipe(uint64_t address);
static v8::Handle<v8::Value> openWritingPipe(const v8::Arguments& args)
{
	HandleScope scope;

	RF24Object* obj = ObjectWrap::Unwrap<RF24Object>(args.This());
	unint64_t address = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
	obj->rf24->openWritingPipe(address);
	return scope.Close(Undefined());
}

	//  void openReadingPipe(uint8_t number, uint64_t address);
//static v8::Handle<v8::Value> openReadingPipe(const v8::Arguments& args);
	//void setRetries(uint8_t delay, uint8_t count);
//static v8::Handle<v8::Value> setRetries(const v8::Arguments& args);
	//void setChannel(uint8_t channel);
//static v8::Handle<v8::Value> setChannel(const v8::Arguments& args);
	//void setPayloadSize(uint8_t size);
//static v8::Handle<v8::Value> setPayloadSize(const v8::Arguments& args);
#ifndef RF24_H
#define RF24_H
#include <node.h>
#include "RF24\librf24-rpi\librf24-bcm\RF24.h"

class RF24Obj : public node::ObjectWrap{
	public:
		static void Init(v8::Handle<v8::Object> exports);
		
	private:
	RF24 * rf24;
	
	explicit RF24Obj(uint8_t _cepin, uint8_t _cspin);
	explicit RF24Obj(uint8_t _cepin, uint8_t _cspin, uint32_t spispeed );
	~RF24Obj();
	
	static v8::Handle<v8::Value> New(const v8::Arguments& args);
	static v8::Persistent<v8::Function> constructor;
	
	//bool begin(void);
	static v8::Handle<v8::Value> begin(const v8::Arguments& args);
	// void startListening(void);
	static v8::Handle<v8::Value> startListening(const v8::Arguments& args);
	//void stopListening(void);
	static v8::Handle<v8::Value> stopListening(const v8::Arguments& args);
	// bool write( const void* buf, uint8_t len );
	static v8::Handle<v8::Value> write(const v8::Arguments& args);
	//  bool available(void);
	static v8::Handle<v8::Value> available(const v8::Arguments& args);
	//bool read( void* buf, uint8_t len );
	static v8::Handle<v8::Value> read(const v8::Arguments& args);
	//  void openWritingPipe(uint64_t address);
	static v8::Handle<v8::Value> openWritingPipe(const v8::Arguments& args);
	//  void openReadingPipe(uint8_t number, uint64_t address);
	static v8::Handle<v8::Value> openReadingPipe(const v8::Arguments& args);
	//void setRetries(uint8_t delay, uint8_t count);
	static v8::Handle<v8::Value> setRetries(const v8::Arguments& args);
	//void setChannel(uint8_t channel);
	static v8::Handle<v8::Value> setChannel(const v8::Arguments& args);
	//void setPayloadSize(uint8_t size);
	static v8::Handle<v8::Value> setPayloadSize(const v8::Arguments& args);
	// uint8_t getPayloadSize(void);
	static v8::Handle<v8::Value> getPayloadSize(const v8::Arguments& args);
	//uint8_t getDynamicPayloadSize(void);
	static v8::Handle<v8::Value> getDynamicPayloadSize(const v8::Arguments& args);
	//void enableAckPayload(void);
  	static v8::Handle<v8::Value> enableAckPayload(const v8::Arguments& args);
	//void enableDynamicPayloads(void);
  	static v8::Handle<v8::Value> enableDynamicPayloads(const v8::Arguments& args);
	//bool isPVariant(void) ;
  	static v8::Handle<v8::Value> isPVariant(const v8::Arguments& args);
	//void setAutoAck(bool enable);
	//void setAutoAck( uint8_t pipe, bool enable ) ;
  	static v8::Handle<v8::Value> setAutoAck(const v8::Arguments& args);
	//void setPALevel( rf24_pa_dbm_e level ) ;
  	static v8::Handle<v8::Value> setPALevel(const v8::Arguments& args);
	//rf24_pa_dbm_e getPALevel( void ) ;
   	static v8::Handle<v8::Value> getPALevel(const v8::Arguments& args);
	//bool setDataRate(rf24_datarate_e speed);
	static v8::Handle<v8::Value> setDataRate(const v8::Arguments& args);
	//rf24_datarate_e getDataRate( void ) ;
	static v8::Handle<v8::Value> getDataRate(const v8::Arguments& args);
	//void setCRCLength(rf24_crclength_e length);
	static v8::Handle<v8::Value> setCRCLength(const v8::Arguments& args);
	//rf24_crclength_e getCRCLength(void);
	static v8::Handle<v8::Value> getCRCLength(const v8::Arguments& args);
	//void disableCRC( void ) ;
	static v8::Handle<v8::Value> disableCRC(const v8::Arguments& args);
	//void printDetails(void);	
	static v8::Handle<v8::Value> printDetails(const v8::Arguments& args);
	//void powerDown(void);
	static v8::Handle<v8::Value> powerDown(const v8::Arguments& args);
	//void powerUp(void) ;
	static v8::Handle<v8::Value> powerUp(const v8::Arguments& args);
	// bool available(uint8_t* pipe_num);
	static v8::Handle<v8::Value> available(const v8::Arguments& args);
	//void startWrite( const void* buf, uint8_t len );
	static v8::Handle<v8::Value> startWrite(const v8::Arguments& args);
	//void writeAckPayload(uint8_t pipe, const 
	static v8::Handle<v8::Value> writeAckPayload(const v8::Arguments& args);
	//bool isAckPayloadAvailable(void);
	static v8::Handle<v8::Value> isAckPayloadAvailable(const v8::Arguments& args);
	//void whatHappened(bool& tx_ok,bool& tx_fail,bool& rx_ready);
	static v8::Handle<v8::Value> whatHappened(const v8::Arguments& args);
	//bool testCarrier(void);
	static v8::Handle<v8::Value> testCarrier(const v8::Arguments& args);
	//bool testRPD(void) ;					
	static v8::Handle<v8::Value> testRPD(const v8::Arguments& args);
	
};
#endif
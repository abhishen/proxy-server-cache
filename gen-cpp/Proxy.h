/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Proxy_H
#define Proxy_H

#include <thrift/TDispatchProcessor.h>
#include "simple_types.h"

namespace rpc {

class ProxyIf {
 public:
  virtual ~ProxyIf() {}
  virtual int32_t ping() = 0;
  virtual int32_t currentTime() = 0;
  virtual void getURL(std::string& _return, const std::string& url) = 0;
};

class ProxyIfFactory {
 public:
  typedef ProxyIf Handler;

  virtual ~ProxyIfFactory() {}

  virtual ProxyIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ProxyIf* /* handler */) = 0;
};

class ProxyIfSingletonFactory : virtual public ProxyIfFactory {
 public:
  ProxyIfSingletonFactory(const boost::shared_ptr<ProxyIf>& iface) : iface_(iface) {}
  virtual ~ProxyIfSingletonFactory() {}

  virtual ProxyIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ProxyIf* /* handler */) {}

 protected:
  boost::shared_ptr<ProxyIf> iface_;
};

class ProxyNull : virtual public ProxyIf {
 public:
  virtual ~ProxyNull() {}
  int32_t ping() {
    int32_t _return = 0;
    return _return;
  }
  int32_t currentTime() {
    int32_t _return = 0;
    return _return;
  }
  void getURL(std::string& /* _return */, const std::string& /* url */) {
    return;
  }
};


class Proxy_ping_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  Proxy_ping_args(const Proxy_ping_args&);
  Proxy_ping_args& operator=(const Proxy_ping_args&);
  Proxy_ping_args() {
  }

  virtual ~Proxy_ping_args() throw();

  bool operator == (const Proxy_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Proxy_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Proxy_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_ping_args& obj);
};


class Proxy_ping_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~Proxy_ping_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_ping_pargs& obj);
};

typedef struct _Proxy_ping_result__isset {
  _Proxy_ping_result__isset() : success(false) {}
  bool success :1;
} _Proxy_ping_result__isset;

class Proxy_ping_result {
 public:

  static const char* ascii_fingerprint; // = "32183C4A04E706C58ED2F62566DDD8DE";
  static const uint8_t binary_fingerprint[16]; // = {0x32,0x18,0x3C,0x4A,0x04,0xE7,0x06,0xC5,0x8E,0xD2,0xF6,0x25,0x66,0xDD,0xD8,0xDE};

  Proxy_ping_result(const Proxy_ping_result&);
  Proxy_ping_result& operator=(const Proxy_ping_result&);
  Proxy_ping_result() : success(0) {
  }

  virtual ~Proxy_ping_result() throw();
  int32_t success;

  _Proxy_ping_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Proxy_ping_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Proxy_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Proxy_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_ping_result& obj);
};

typedef struct _Proxy_ping_presult__isset {
  _Proxy_ping_presult__isset() : success(false) {}
  bool success :1;
} _Proxy_ping_presult__isset;

class Proxy_ping_presult {
 public:

  static const char* ascii_fingerprint; // = "32183C4A04E706C58ED2F62566DDD8DE";
  static const uint8_t binary_fingerprint[16]; // = {0x32,0x18,0x3C,0x4A,0x04,0xE7,0x06,0xC5,0x8E,0xD2,0xF6,0x25,0x66,0xDD,0xD8,0xDE};


  virtual ~Proxy_ping_presult() throw();
  int32_t* success;

  _Proxy_ping_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const Proxy_ping_presult& obj);
};


class Proxy_currentTime_args {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  Proxy_currentTime_args(const Proxy_currentTime_args&);
  Proxy_currentTime_args& operator=(const Proxy_currentTime_args&);
  Proxy_currentTime_args() {
  }

  virtual ~Proxy_currentTime_args() throw();

  bool operator == (const Proxy_currentTime_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Proxy_currentTime_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Proxy_currentTime_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_currentTime_args& obj);
};


class Proxy_currentTime_pargs {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~Proxy_currentTime_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_currentTime_pargs& obj);
};

typedef struct _Proxy_currentTime_result__isset {
  _Proxy_currentTime_result__isset() : success(false) {}
  bool success :1;
} _Proxy_currentTime_result__isset;

class Proxy_currentTime_result {
 public:

  static const char* ascii_fingerprint; // = "32183C4A04E706C58ED2F62566DDD8DE";
  static const uint8_t binary_fingerprint[16]; // = {0x32,0x18,0x3C,0x4A,0x04,0xE7,0x06,0xC5,0x8E,0xD2,0xF6,0x25,0x66,0xDD,0xD8,0xDE};

  Proxy_currentTime_result(const Proxy_currentTime_result&);
  Proxy_currentTime_result& operator=(const Proxy_currentTime_result&);
  Proxy_currentTime_result() : success(0) {
  }

  virtual ~Proxy_currentTime_result() throw();
  int32_t success;

  _Proxy_currentTime_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Proxy_currentTime_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Proxy_currentTime_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Proxy_currentTime_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_currentTime_result& obj);
};

typedef struct _Proxy_currentTime_presult__isset {
  _Proxy_currentTime_presult__isset() : success(false) {}
  bool success :1;
} _Proxy_currentTime_presult__isset;

class Proxy_currentTime_presult {
 public:

  static const char* ascii_fingerprint; // = "32183C4A04E706C58ED2F62566DDD8DE";
  static const uint8_t binary_fingerprint[16]; // = {0x32,0x18,0x3C,0x4A,0x04,0xE7,0x06,0xC5,0x8E,0xD2,0xF6,0x25,0x66,0xDD,0xD8,0xDE};


  virtual ~Proxy_currentTime_presult() throw();
  int32_t* success;

  _Proxy_currentTime_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const Proxy_currentTime_presult& obj);
};

typedef struct _Proxy_getURL_args__isset {
  _Proxy_getURL_args__isset() : url(false) {}
  bool url :1;
} _Proxy_getURL_args__isset;

class Proxy_getURL_args {
 public:

  static const char* ascii_fingerprint; // = "E2167DA91A8F7459A2FE1B5F56D14B5D";
  static const uint8_t binary_fingerprint[16]; // = {0xE2,0x16,0x7D,0xA9,0x1A,0x8F,0x74,0x59,0xA2,0xFE,0x1B,0x5F,0x56,0xD1,0x4B,0x5D};

  Proxy_getURL_args(const Proxy_getURL_args&);
  Proxy_getURL_args& operator=(const Proxy_getURL_args&);
  Proxy_getURL_args() : url() {
  }

  virtual ~Proxy_getURL_args() throw();
  std::string url;

  _Proxy_getURL_args__isset __isset;

  void __set_url(const std::string& val);

  bool operator == (const Proxy_getURL_args & rhs) const
  {
    if (!(url == rhs.url))
      return false;
    return true;
  }
  bool operator != (const Proxy_getURL_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Proxy_getURL_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_getURL_args& obj);
};


class Proxy_getURL_pargs {
 public:

  static const char* ascii_fingerprint; // = "E2167DA91A8F7459A2FE1B5F56D14B5D";
  static const uint8_t binary_fingerprint[16]; // = {0xE2,0x16,0x7D,0xA9,0x1A,0x8F,0x74,0x59,0xA2,0xFE,0x1B,0x5F,0x56,0xD1,0x4B,0x5D};


  virtual ~Proxy_getURL_pargs() throw();
  const std::string* url;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_getURL_pargs& obj);
};

typedef struct _Proxy_getURL_result__isset {
  _Proxy_getURL_result__isset() : success(false) {}
  bool success :1;
} _Proxy_getURL_result__isset;

class Proxy_getURL_result {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};

  Proxy_getURL_result(const Proxy_getURL_result&);
  Proxy_getURL_result& operator=(const Proxy_getURL_result&);
  Proxy_getURL_result() : success() {
  }

  virtual ~Proxy_getURL_result() throw();
  std::string success;

  _Proxy_getURL_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Proxy_getURL_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Proxy_getURL_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Proxy_getURL_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const Proxy_getURL_result& obj);
};

typedef struct _Proxy_getURL_presult__isset {
  _Proxy_getURL_presult__isset() : success(false) {}
  bool success :1;
} _Proxy_getURL_presult__isset;

class Proxy_getURL_presult {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};


  virtual ~Proxy_getURL_presult() throw();
  std::string* success;

  _Proxy_getURL_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const Proxy_getURL_presult& obj);
};

class ProxyClient : virtual public ProxyIf {
 public:
  ProxyClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ProxyClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t ping();
  void send_ping();
  int32_t recv_ping();
  int32_t currentTime();
  void send_currentTime();
  int32_t recv_currentTime();
  void getURL(std::string& _return, const std::string& url);
  void send_getURL(const std::string& url);
  void recv_getURL(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ProxyProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ProxyIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ProxyProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_currentTime(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getURL(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ProxyProcessor(boost::shared_ptr<ProxyIf> iface) :
    iface_(iface) {
    processMap_["ping"] = &ProxyProcessor::process_ping;
    processMap_["currentTime"] = &ProxyProcessor::process_currentTime;
    processMap_["getURL"] = &ProxyProcessor::process_getURL;
  }

  virtual ~ProxyProcessor() {}
};

class ProxyProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ProxyProcessorFactory(const ::boost::shared_ptr< ProxyIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ProxyIfFactory > handlerFactory_;
};

class ProxyMultiface : virtual public ProxyIf {
 public:
  ProxyMultiface(std::vector<boost::shared_ptr<ProxyIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ProxyMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ProxyIf> > ifaces_;
  ProxyMultiface() {}
  void add(boost::shared_ptr<ProxyIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t ping() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping();
    }
    return ifaces_[i]->ping();
  }

  int32_t currentTime() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->currentTime();
    }
    return ifaces_[i]->currentTime();
  }

  void getURL(std::string& _return, const std::string& url) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getURL(_return, url);
    }
    ifaces_[i]->getURL(_return, url);
    return;
  }

};

} // namespace

#endif

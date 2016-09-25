/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "tutorial_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace tutorial {

int _kOperationValues[] = {
  Operation::ADD,
  Operation::SUBTRACT,
  Operation::MULTIPLY,
  Operation::DIVIDE
};
const char* _kOperationNames[] = {
  "ADD",
  "SUBTRACT",
  "MULTIPLY",
  "DIVIDE"
};
const std::map<int, const char*> _Operation_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kOperationValues, _kOperationNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


Work::~Work() throw() {
}


void Work::__set_num1(const int32_t val) {
  this->num1 = val;
}

void Work::__set_num2(const int32_t val) {
  this->num2 = val;
}

void Work::__set_op(const Operation::type val) {
  this->op = val;
}

void Work::__set_comment(const std::string& val) {
  this->comment = val;
__isset.comment = true;
}

uint32_t Work::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->num1);
          this->__isset.num1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->num2);
          this->__isset.num2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->op = (Operation::type)ecast0;
          this->__isset.op = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->comment);
          this->__isset.comment = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Work::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Work");

  xfer += oprot->writeFieldBegin("num1", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->num1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("num2", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->num2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("op", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)this->op);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.comment) {
    xfer += oprot->writeFieldBegin("comment", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->comment);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Work &a, Work &b) {
  using ::std::swap;
  swap(a.num1, b.num1);
  swap(a.num2, b.num2);
  swap(a.op, b.op);
  swap(a.comment, b.comment);
  swap(a.__isset, b.__isset);
}

Work::Work(const Work& other1) {
  num1 = other1.num1;
  num2 = other1.num2;
  op = other1.op;
  comment = other1.comment;
  __isset = other1.__isset;
}
Work& Work::operator=(const Work& other2) {
  num1 = other2.num1;
  num2 = other2.num2;
  op = other2.op;
  comment = other2.comment;
  __isset = other2.__isset;
  return *this;
}
void Work::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Work(";
  out << "num1=" << to_string(num1);
  out << ", " << "num2=" << to_string(num2);
  out << ", " << "op=" << to_string(op);
  out << ", " << "comment="; (__isset.comment ? (out << to_string(comment)) : (out << "<null>"));
  out << ")";
}


HelloInt::~HelloInt() throw() {
}


void HelloInt::__set_value(const int32_t val) {
  this->value = val;
}

uint32_t HelloInt::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t HelloInt::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("HelloInt");

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(HelloInt &a, HelloInt &b) {
  using ::std::swap;
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

HelloInt::HelloInt(const HelloInt& other3) {
  value = other3.value;
  __isset = other3.__isset;
}
HelloInt& HelloInt::operator=(const HelloInt& other4) {
  value = other4.value;
  __isset = other4.__isset;
  return *this;
}
void HelloInt::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "HelloInt(";
  out << "value=" << to_string(value);
  out << ")";
}


HelloDouble::~HelloDouble() throw() {
}


void HelloDouble::__set_value(const double val) {
  this->value = val;
}

uint32_t HelloDouble::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t HelloDouble::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("HelloDouble");

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_DOUBLE, 1);
  xfer += oprot->writeDouble(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(HelloDouble &a, HelloDouble &b) {
  using ::std::swap;
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

HelloDouble::HelloDouble(const HelloDouble& other5) {
  value = other5.value;
  __isset = other5.__isset;
}
HelloDouble& HelloDouble::operator=(const HelloDouble& other6) {
  value = other6.value;
  __isset = other6.__isset;
  return *this;
}
void HelloDouble::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "HelloDouble(";
  out << "value=" << to_string(value);
  out << ")";
}


HelloString::~HelloString() throw() {
}


void HelloString::__set_name(const std::string& val) {
  this->name = val;
}

uint32_t HelloString::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t HelloString::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("HelloString");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(HelloString &a, HelloString &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.__isset, b.__isset);
}

HelloString::HelloString(const HelloString& other7) {
  name = other7.name;
  __isset = other7.__isset;
}
HelloString& HelloString::operator=(const HelloString& other8) {
  name = other8.name;
  __isset = other8.__isset;
  return *this;
}
void HelloString::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "HelloString(";
  out << "name=" << to_string(name);
  out << ")";
}


PhoneNumber::~PhoneNumber() throw() {
}


void PhoneNumber::__set_number(const std::string& val) {
  this->number = val;
}

void PhoneNumber::__set_op(const Operation::type val) {
  this->op = val;
}

uint32_t PhoneNumber::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->number);
          this->__isset.number = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast9;
          xfer += iprot->readI32(ecast9);
          this->op = (Operation::type)ecast9;
          this->__isset.op = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t PhoneNumber::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PhoneNumber");

  xfer += oprot->writeFieldBegin("number", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->number);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("op", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->op);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PhoneNumber &a, PhoneNumber &b) {
  using ::std::swap;
  swap(a.number, b.number);
  swap(a.op, b.op);
  swap(a.__isset, b.__isset);
}

PhoneNumber::PhoneNumber(const PhoneNumber& other10) {
  number = other10.number;
  op = other10.op;
  __isset = other10.__isset;
}
PhoneNumber& PhoneNumber::operator=(const PhoneNumber& other11) {
  number = other11.number;
  op = other11.op;
  __isset = other11.__isset;
  return *this;
}
void PhoneNumber::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PhoneNumber(";
  out << "number=" << to_string(number);
  out << ", " << "op=" << to_string(op);
  out << ")";
}


Person::~Person() throw() {
}


void Person::__set_name(const std::string& val) {
  this->name = val;
}

void Person::__set_id(const int32_t val) {
  this->id = val;
}

void Person::__set_email(const std::string& val) {
  this->email = val;
}

void Person::__set_phone(const PhoneNumber& val) {
  this->phone = val;
}

uint32_t Person::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->email);
          this->__isset.email = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->phone.read(iprot);
          this->__isset.phone = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Person::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Person");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("email", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->email);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("phone", ::apache::thrift::protocol::T_STRUCT, 4);
  xfer += this->phone.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Person &a, Person &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.id, b.id);
  swap(a.email, b.email);
  swap(a.phone, b.phone);
  swap(a.__isset, b.__isset);
}

Person::Person(const Person& other12) {
  name = other12.name;
  id = other12.id;
  email = other12.email;
  phone = other12.phone;
  __isset = other12.__isset;
}
Person& Person::operator=(const Person& other13) {
  name = other13.name;
  id = other13.id;
  email = other13.email;
  phone = other13.phone;
  __isset = other13.__isset;
  return *this;
}
void Person::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Person(";
  out << "name=" << to_string(name);
  out << ", " << "id=" << to_string(id);
  out << ", " << "email=" << to_string(email);
  out << ", " << "phone=" << to_string(phone);
  out << ")";
}


InvalidOperation::~InvalidOperation() throw() {
}


void InvalidOperation::__set_whatOp(const int32_t val) {
  this->whatOp = val;
}

void InvalidOperation::__set_why(const std::string& val) {
  this->why = val;
}

uint32_t InvalidOperation::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->whatOp);
          this->__isset.whatOp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->why);
          this->__isset.why = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t InvalidOperation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("InvalidOperation");

  xfer += oprot->writeFieldBegin("whatOp", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->whatOp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("why", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->why);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(InvalidOperation &a, InvalidOperation &b) {
  using ::std::swap;
  swap(a.whatOp, b.whatOp);
  swap(a.why, b.why);
  swap(a.__isset, b.__isset);
}

InvalidOperation::InvalidOperation(const InvalidOperation& other14) : TException() {
  whatOp = other14.whatOp;
  why = other14.why;
  __isset = other14.__isset;
}
InvalidOperation& InvalidOperation::operator=(const InvalidOperation& other15) {
  whatOp = other15.whatOp;
  why = other15.why;
  __isset = other15.__isset;
  return *this;
}
void InvalidOperation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "InvalidOperation(";
  out << "whatOp=" << to_string(whatOp);
  out << ", " << "why=" << to_string(why);
  out << ")";
}

const char* InvalidOperation::what() const throw() {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: InvalidOperation";
  }
}

} // namespace

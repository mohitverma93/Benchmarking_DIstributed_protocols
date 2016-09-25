#
# Autogenerated by Thrift Compiler (0.9.3)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
#  options string: py:slots
#

from thrift.Thrift import TType, TMessageType, TException, TApplicationException
import logging
from ttypes import *
from thrift.Thrift import TProcessor
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol, TProtocol
try:
  from thrift.protocol import fastbinary
except:
  fastbinary = None


class Iface:
  def methodThatThrowsAnException(self):
    pass


class Client(Iface):
  def __init__(self, iprot, oprot=None):
    self._iprot = self._oprot = iprot
    if oprot is not None:
      self._oprot = oprot
    self._seqid = 0

  def methodThatThrowsAnException(self):
    self.send_methodThatThrowsAnException()
    self.recv_methodThatThrowsAnException()

  def send_methodThatThrowsAnException(self):
    self._oprot.writeMessageBegin('methodThatThrowsAnException', TMessageType.CALL, self._seqid)
    args = methodThatThrowsAnException_args()
    args.write(self._oprot)
    self._oprot.writeMessageEnd()
    self._oprot.trans.flush()

  def recv_methodThatThrowsAnException(self):
    iprot = self._iprot
    (fname, mtype, rseqid) = iprot.readMessageBegin()
    if mtype == TMessageType.EXCEPTION:
      x = TApplicationException()
      x.read(iprot)
      iprot.readMessageEnd()
      raise x
    result = methodThatThrowsAnException_result()
    result.read(iprot)
    iprot.readMessageEnd()
    if result.xwamap is not None:
      raise result.xwamap
    return


class Processor(Iface, TProcessor):
  def __init__(self, handler):
    self._handler = handler
    self._processMap = {}
    self._processMap["methodThatThrowsAnException"] = Processor.process_methodThatThrowsAnException

  def process(self, iprot, oprot):
    (name, type, seqid) = iprot.readMessageBegin()
    if name not in self._processMap:
      iprot.skip(TType.STRUCT)
      iprot.readMessageEnd()
      x = TApplicationException(TApplicationException.UNKNOWN_METHOD, 'Unknown function %s' % (name))
      oprot.writeMessageBegin(name, TMessageType.EXCEPTION, seqid)
      x.write(oprot)
      oprot.writeMessageEnd()
      oprot.trans.flush()
      return
    else:
      self._processMap[name](self, seqid, iprot, oprot)
    return True

  def process_methodThatThrowsAnException(self, seqid, iprot, oprot):
    args = methodThatThrowsAnException_args()
    args.read(iprot)
    iprot.readMessageEnd()
    result = methodThatThrowsAnException_result()
    try:
      self._handler.methodThatThrowsAnException()
      msg_type = TMessageType.REPLY
    except (TTransport.TTransportException, KeyboardInterrupt, SystemExit):
      raise
    except ExceptionWithAMap as xwamap:
      msg_type = TMessageType.REPLY
      result.xwamap = xwamap
    except Exception as ex:
      msg_type = TMessageType.EXCEPTION
      logging.exception(ex)
      result = TApplicationException(TApplicationException.INTERNAL_ERROR, 'Internal error')
    oprot.writeMessageBegin("methodThatThrowsAnException", msg_type, seqid)
    result.write(oprot)
    oprot.writeMessageEnd()
    oprot.trans.flush()


# HELPER FUNCTIONS AND STRUCTURES

class methodThatThrowsAnException_args:

  __slots__ = [ 
   ]

  thrift_spec = (
  )

  def read(self, iprot):
    if iprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastbinary is not None:
      fastbinary.decode_binary(self, iprot.trans, (self.__class__, self.thrift_spec))
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if oprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and self.thrift_spec is not None and fastbinary is not None:
      oprot.trans.write(fastbinary.encode_binary(self, (self.__class__, self.thrift_spec)))
      return
    oprot.writeStructBegin('methodThatThrowsAnException_args')
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def validate(self):
    return


  def __hash__(self):
    value = 17
    return value

  def __repr__(self):
    L = ['%s=%r' % (key, getattr(self, key))
      for key in self.__slots__]
    return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False
    for attr in self.__slots__:
      my_val = getattr(self, attr)
      other_val = getattr(other, attr)
      if my_val != other_val:
        return False
    return True

  def __ne__(self, other):
    return not (self == other)


class methodThatThrowsAnException_result:
  """
  Attributes:
   - xwamap
  """

  __slots__ = [ 
    'xwamap',
   ]

  thrift_spec = (
    None, # 0
    (1, TType.STRUCT, 'xwamap', (ExceptionWithAMap, ExceptionWithAMap.thrift_spec), None, ), # 1
  )

  def __init__(self, xwamap=None,):
    self.xwamap = xwamap

  def read(self, iprot):
    if iprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastbinary is not None:
      fastbinary.decode_binary(self, iprot.trans, (self.__class__, self.thrift_spec))
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 1:
        if ftype == TType.STRUCT:
          self.xwamap = ExceptionWithAMap()
          self.xwamap.read(iprot)
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if oprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and self.thrift_spec is not None and fastbinary is not None:
      oprot.trans.write(fastbinary.encode_binary(self, (self.__class__, self.thrift_spec)))
      return
    oprot.writeStructBegin('methodThatThrowsAnException_result')
    if self.xwamap is not None:
      oprot.writeFieldBegin('xwamap', TType.STRUCT, 1)
      self.xwamap.write(oprot)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def validate(self):
    return


  def __hash__(self):
    value = 17
    value = (value * 31) ^ hash(self.xwamap)
    return value

  def __repr__(self):
    L = ['%s=%r' % (key, getattr(self, key))
      for key in self.__slots__]
    return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False
    for attr in self.__slots__:
      my_val = getattr(self, attr)
      other_val = getattr(other, attr)
      if my_val != other_val:
        return False
    return True

  def __ne__(self, other):
    return not (self == other)


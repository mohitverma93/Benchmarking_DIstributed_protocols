#
# Autogenerated by Thrift Compiler (0.9.3)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
#  options string: py:twisted
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

from zope.interface import Interface, implements
from twisted.internet import defer
from thrift.transport import TTwisted

class Iface(Interface):
  def getStruct(key):
    """
    Parameters:
     - key
    """
    pass


class Client:
  implements(Iface)

  def __init__(self, transport, oprot_factory):
    self._transport = transport
    self._oprot_factory = oprot_factory
    self._seqid = 0
    self._reqs = {}

  def getStruct(self, key):
    """
    Parameters:
     - key
    """
    seqid = self._seqid = self._seqid + 1
    self._reqs[seqid] = defer.Deferred()

    d = defer.maybeDeferred(self.send_getStruct, key)
    d.addCallbacks(
      callback=self.cb_send_getStruct,
      callbackArgs=(seqid,),
      errback=self.eb_send_getStruct,
      errbackArgs=(seqid,))
    return d

  def cb_send_getStruct(self, _, seqid):
    return self._reqs[seqid]

  def eb_send_getStruct(self, f, seqid):
    d = self._reqs.pop(seqid)
    d.errback(f)
    return d

  def send_getStruct(self, key):
    oprot = self._oprot_factory.getProtocol(self._transport)
    oprot.writeMessageBegin('getStruct', TMessageType.CALL, self._seqid)
    args = getStruct_args()
    args.key = key
    args.write(oprot)
    oprot.writeMessageEnd()
    oprot.trans.flush()

  def recv_getStruct(self, iprot, mtype, rseqid):
    d = self._reqs.pop(rseqid)
    if mtype == TMessageType.EXCEPTION:
      x = TApplicationException()
      x.read(iprot)
      iprot.readMessageEnd()
      return d.errback(x)
    result = getStruct_result()
    result.read(iprot)
    iprot.readMessageEnd()
    if result.success is not None:
      return d.callback(result.success)
    return d.errback(TApplicationException(TApplicationException.MISSING_RESULT, "getStruct failed: unknown result"))


class Processor(TProcessor):
  implements(Iface)

  def __init__(self, handler):
    self._handler = Iface(handler)
    self._processMap = {}
    self._processMap["getStruct"] = Processor.process_getStruct

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
      return defer.succeed(None)
    else:
      return self._processMap[name](self, seqid, iprot, oprot)

  def process_getStruct(self, seqid, iprot, oprot):
    args = getStruct_args()
    args.read(iprot)
    iprot.readMessageEnd()
    result = getStruct_result()
    d = defer.maybeDeferred(self._handler.getStruct, args.key)
    d.addCallback(self.write_results_success_getStruct, result, seqid, oprot)
    return d

  def write_results_success_getStruct(self, success, result, seqid, oprot):
    result.success = success
    oprot.writeMessageBegin("getStruct", TMessageType.REPLY, seqid)
    result.write(oprot)
    oprot.writeMessageEnd()
    oprot.trans.flush()


# HELPER FUNCTIONS AND STRUCTURES

class getStruct_args:
  """
  Attributes:
   - key
  """

  thrift_spec = (
    None, # 0
    (1, TType.I32, 'key', None, None, ), # 1
  )

  def __init__(self, key=None,):
    self.key = key

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
        if ftype == TType.I32:
          self.key = iprot.readI32()
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
    oprot.writeStructBegin('getStruct_args')
    if self.key is not None:
      oprot.writeFieldBegin('key', TType.I32, 1)
      oprot.writeI32(self.key)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def validate(self):
    return


  def __hash__(self):
    value = 17
    value = (value * 31) ^ hash(self.key)
    return value

  def __repr__(self):
    L = ['%s=%r' % (key, value)
      for key, value in self.__dict__.iteritems()]
    return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

  def __eq__(self, other):
    return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

  def __ne__(self, other):
    return not (self == other)

class getStruct_result:
  """
  Attributes:
   - success
  """

  thrift_spec = (
    (0, TType.STRUCT, 'success', (SharedStruct, SharedStruct.thrift_spec), None, ), # 0
  )

  def __init__(self, success=None,):
    self.success = success

  def read(self, iprot):
    if iprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastbinary is not None:
      fastbinary.decode_binary(self, iprot.trans, (self.__class__, self.thrift_spec))
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 0:
        if ftype == TType.STRUCT:
          self.success = SharedStruct()
          self.success.read(iprot)
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
    oprot.writeStructBegin('getStruct_result')
    if self.success is not None:
      oprot.writeFieldBegin('success', TType.STRUCT, 0)
      self.success.write(oprot)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def validate(self):
    return


  def __hash__(self):
    value = 17
    value = (value * 31) ^ hash(self.success)
    return value

  def __repr__(self):
    L = ['%s=%r' % (key, value)
      for key, value in self.__dict__.iteritems()]
    return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

  def __eq__(self, other):
    return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

  def __ne__(self, other):
    return not (self == other)

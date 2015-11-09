//assert
#include "Assert.h"

//exception
#include "BindException.h"
#include "ClassCastException.h"
#include "Error.h"
#include "Exception.h"
#include "FileNotFoundException.h"
#include "IOError.h"
#include "NullPointerException.h"
#include "RuntimeException.h"
#include "SocketException.h"
#include "Throwable.h"
#include "UnknownHostException.h"

//http
#include "HttpClient.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

//io
#include "Closeable.h"
#include "File.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "Flushable.h"

//lang
#include "Appendable.h"
#include "Boolean.h"
#include "Double.h"
#include "Integer.h"
#include "Long.h"
#include "Object.h"
#include "Strings.h"
#include "System.h"

//log
#include "Appender.h"
#include "DefaultLogger.h"
#include "FileAppender.h"
#include "Logger.h"
#include "LoggerFactory.h"
#include "StandardOutAppender.h"

//util
#include "ArrayList.h"
#include "Date.h"
#include "Entry.h"
#include "EntrySet.h"
#include "HashMap.h"
#include "Queue.h"

//typedef
typedef std::shared_ptr<HttpClient> _HttpClient;
typedef std::shared_ptr<HttpProxy> _HttpProxy;
typedef std::shared_ptr<HttpRequest> _HttpRequest;
typedef std::shared_ptr<HttpResponse> _HttpResponse;
typedef std::shared_ptr<File> _File;
typedef std::shared_ptr<FileReader> _FileReader;
typedef std::shared_ptr<FileWriter> _FileWriter;
typedef std::shared_ptr<Double> _Double;
typedef std::shared_ptr<Integer> _Integer;
typedef std::shared_ptr<Long> _Long;
typedef std::shared_ptr<Object> _Object;
typedef std::shared_ptr<Strings> _Strings;
typedef std::shared_ptr<Appender> _Appender;
typedef std::shared_ptr<DefaultLogger> _DefaultLogger;
typedef std::shared_ptr<FileAppender> _FileAppender;
typedef std::shared_ptr<Logger> _Logger;
typedef std::shared_ptr<StandardOutAppender> _StandardOutAppender;
typedef std::shared_ptr<ArrayList> _ArrayList;
typedef std::shared_ptr<Date> _Date;
typedef std::shared_ptr<HashMap> _HashMap;
typedef std::shared_ptr<Entry> _Entry;
typedef std::shared_ptr<Queue> _Queue;

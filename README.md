# viola: c++ development kit
shared object like JDK interface.

## Required
```
-std=c++11 -stdlib=libc++
```

## viola.exception

Exception
```
#include "viola.h"

...

try {
	throw new Exception("foobar");
} catch (Exception* e) {
	System::out::println(e); // -> Exception[message: foobar]
	delete e;
}
```

## viola.io

File
```
#include "viola.h"

...

_File file = std::make_shared<File>("/tmp/test.log");

if(file->exists()){
	file->deleteFile();
}
file->createNewFile();

_FileWriter writer = std::make_shared<FileWriter>(file);
writer->write("this is first line.");
writer->flush();
writer->close();

```

## viola.lang

Strings
```
#include "viola.h"

...

_Strings str = std::make_shared<Strings>();

str->append("foobar");
str->append("hoge");
System::out::println(str); // -> foobarhoge

System::out::println(str->equals("foobarhoge")); // -> 1
System::out::println(str->equals("notsame")); // -> 0
```

## viola.log

Logger

```
#include "viola.h"

...

_Logger logger = LoggerFactory::getLogger("MyClass");
logger->info("foobar");

```

## viola.util

ArrayList
```
#include "viola.h"

...

_ArrayList list = std::make_shared<ArrayList>();

for(int i = 0; i < 10; i ++){
	_Integer arg = std::make_shared<Integer>(i);
	list->add(arg);
}

for(int i = 0; i < list->size(); i++){
	System::out::println(list->get(i));
}
list->clear();
```

HashMap
```
#include "viola.h"

...

_HashMap map = std::make_shared<HashMap>();

_Strings key = std::make_shared<Strings>("foobar");
_Strings value = std::make_shared<Strings>("hoge");

map->put(key, value);
System::out::println(map->get(key)); // -> hoge

map->clear();
```

# viola: c++ development kit
shared object like JDK interface.

## Required
```
-std=c++11 -stdlib=libc++
```

## Example

### viola.exception

Exception
```
#include "viola.h"

...

try {
	throw Exception("foobar");
} catch (Exception& e) {
	System::out::println(e); // -> Exception[message: foobar]
}
```

### viola.io

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

### viola.lang

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

### viola.log

Logger

```
#include "viola.h"

...

_Logger log = LoggerFactory::getLogger("MyClass");
log->info("this is info level log.");

if(log->isTraceEnabled()){
	log->trace("this is trace level log.");
}
```

### viola.util

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

## Example violac (viola c implementation)

ArrayList
```
#include "violac.h"

...

ArrayList* list = ArrayList_new();

ArrayList_add(list, data);
void* data = ArrayList_get(list, 0);
int size = ArrayList_size(list);

ArrayList_free(list);
```

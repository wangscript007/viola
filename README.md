# viola: c++ development kit
shared object like JDK interface.

## Required
```
-std=c++11 -stdlib=libc++
```

## viola.io.*

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

## viola.lang.*

Strings
```
#include "viola.h"

...

_Strings str = std::make_shared<Strings>();

str->append("foobar");
str->append("hoge");
System::out::println(str->toString()); // -> foobarhoge

bool same = str->equals("foobar");
bool not = str->equals("notsame");
printf("<%d>\n", same); // -> 1
printf("<%d>\n", not); // -> 0
```

## viola.util.*

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
	System::out::println(list->get(i)->toString());
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
System::out::println("got: " + map->get(key)->toString()); // -> hoge

map->clear();
```

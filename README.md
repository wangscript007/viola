# viola: c++ development kit
shared object like JDK interface.

## Required
```
-std=c++11 -stdlib=libc++
```

## viola.io.*

File
file open/close, read/write.

## viola.lang.*

Strings
```
#include "viola.h"

...

_Strings str = std::make_shared<Strings>();

str->append("foobar");
str->append("hoge");
printf("<%s>\n", str->toString().c_str()); // -> foobarhoge

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

_Integer arg1 = std::make_shared<Integer>(1234);
_Integer arg2 = std::make_shared<Integer>(5678);

list->add(arg1);
list->add(arg2);

for(int i = 0; i < list->size(); i++){
	_Object got = list->get(i);
	printf("<%s>\n", got->toString().c_str());
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
_Object got = map->get(key);
printf("got: <%s>\n", got->toString().c_str()); // -> hoge

bool contains = map->containsKey(key);
printf("containsKey: <%d>\n", contains); // -> 1

map->clear();
```

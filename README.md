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
	file->delete();
}
file->createNewFile();

_FileWriter writer = std::make_shared<FileWriter>(file);
writer.write("this is first line.");
writer.flush();
writer.close();

```

## viola.lang.*

Strings
```
#include "viola.h"

...

_Strings str = std::make_shared<Strings>();

str->append("foobar");
str->append("hoge");
printf("<%s>\n", str->toChar()); // -> foobarhoge

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

_Integer arg1 = std::make_shared<Integer>(123);
_Integer arg2 = std::make_shared<Integer>(456);
_Integer arg3 = std::make_shared<Integer>(789);

list->add(arg1);
list->add(arg2);
list->add(arg3);

for(int i = 0; i < list->size(); i++){
	printf("<%s> ", list->get(i)->toChar());
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
printf("containsKey: <%d> ", map->containsKey(key)); // -> 1
printf("got: <%s> ", map->get(key)->toChar); // -> hoge

map->clear();
```

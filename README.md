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
Strings str;
printf("className: <%s>\n", str.getClassName().c_str());

str.append(s);
printf("str: <%s>\n", str.toString().c_str());
printf("hashCode: <%d>\n", str.hashCode());

bool bool1 = str.equals("foobar");
bool bool2 = str.equals("notsame");
printf("foobar->equals(foobar): <%d>\n", bool1);
printf("foobar->equals(notsame): <%d>\n", bool2);
```

## viola.util.*

ArrayList
```

arrayList list = make_shared<ArrayList>();
printf("className: <%s>\n", list.getClassName().c_str());

integer arg1 = make_shared<Integer>(1234);
integer arg2 = make_shared<Integer>(5678);
list->add(arg1);
list->add(arg2);
printf("size: <%d>\n", list->size()); // -> 2

object obj1 = list->get(0);
object obj2 = list->get(1);
printf("obj1: <%d>\n", ((Integer*) obj1.get())->get()); // -> 1234
printf("obj2: <%d>\n", ((Integer*) obj2.get())->get()); // -> 5678

list.clear();
printf("size: <%d>\n", list->size()); // -> 0
```

HashMap
```
hashMap map = make_shared<HashMap>();

strings key = make_shared<Strings>("foobar");
strings value = make_shared<Strings>("hoge");

map.put(key, value);
object got = map->get(key);
printf("got: <%s>\n", ((Strings*) got.get())->toString().c_str());

bool contains = map->containsKey(key);
printf("containsKey: <%d>\n", contains);

map->clear();
printf("size: <%d>\n", map->size()); // -> 0
```

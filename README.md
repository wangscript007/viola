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
strings str = make_shared<Strings>();

str->append("foobar");
printf("str: <%s>\n", str->toString().c_str()); // -> foobar
printf("hashCode: <%d>\n", str->hashCode());

bool bool1 = str->equals("foobar");
bool bool2 = str->equals("notsame");
printf("foobar->equals(foobar): <%d>\n", bool1); // -> 1
printf("foobar->equals(notsame): <%d>\n", bool2); // -> 0
```

## viola.util.*

ArrayList
```
arrayList list = make_shared<ArrayList>();

integer arg1 = make_shared<Integer>(1234);
integer arg2 = make_shared<Integer>(5678);

list->add(arg1);
list->add(arg2);
printf("size: <%d>\n", list->size()); // -> 2

for(int i = 0; i < list->size(); i++){
	Integer\* obj = (Integer* )list->get(i).get();
	printf("obj: <%d>\n", obj->get()); // -> 1234, 5678
}
list->clear();
printf("size: <%d>\n", list->size()); // -> 0
```

HashMap
```
hashMap map = make_shared<HashMap>();

strings key = make_shared<Strings>("foobar");
strings value = make_shared<Strings>("hoge");

map->put(key, value);
object got = map->get(key);
printf("got: <%s>\n", ((Strings*) got.get())->toString().c_str()); // -> hoge

bool contains = map->containsKey(key);
printf("containsKey: <%d>\n", contains); // -> 1

map->clear();
printf("size: <%d>\n", map->size()); // -> 0
```

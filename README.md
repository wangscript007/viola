# viola: c++ development kit
shared object like JDK interface.

## cpp.io.File
file open/close, read/write.

## cpp.lang.*
Boolean, Integer, Double, Long, String.

```
Strings* str = new Strings();
printf("className: <%s>\n", str->getClassName().c_str());

str->append(s);
printf("str: <%s>\n", str->toString().c_str());
printf("hashCode: <%d>\n", str->hashCode());

bool bool1 = str->equals("foobar");
bool bool2 = str->equals("notsame");
printf("foobar->equals(foobar): <%d>\n", bool1);
printf("foobar->equals(notsame): <%d>\n", bool2);

delete str;
```

## cpp.util.*
ArrayList, HashMap.

```
ArrayList list;
printf("className: <%s>\n", list.getClassName().c_str());

integer arg1 = std::make_shared<Integer>(1234);
integer arg2 = std::make_shared<Integer>(5678);
list.add(arg1);
list.add(arg2);
printf("size: <%d>\n", list.size()); // -> 2

object obj1 = list.get(0);
object obj2 = list.get(1);
printf("obj1: <%d>\n", ((Integer*) obj1.get())->get()); // -> 1234
printf("obj2: <%d>\n", ((Integer*) obj2.get())->get()); // -> 5678

list.clear();
printf("size: <%d>\n", list.size()); // -> 0
```

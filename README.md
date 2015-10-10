# cppdk: c++ development kit

c++ development kit is shared object like JDK.

## cpp.io.File
file open/close, read/write.

## cpp.lang.*
Boolean, Integer, Double, Long, String.

## cpp.util.*
ArrayList, HashMap.

```
ArrayList list;
integer arg1 = std::make_shared<Integer>(1234);
integer arg2 = std::make_shared<Integer>(5678);

list.add(arg1);
list.add(arg2);
printf("size: <%d>\n", list.size()); // -> size: <2>

Integer* value1 = (Integer*) list.get(0).get();
Integer* value2 = (Integer*) list.get(0).get();
printf("[0]: <%d>\n", value1->get()); // -> [0]: <1234>
printf("[1]: <%d>\n", value2->get()); // -> [1]: <5678>

list.clear();
printf("size: <%d>\n", list.size()); // -> size: <0>
```
# cppdk: c++ development kit
c++ development kit is shared object like JDK.

## cpp.io.File
file open/close, read/write.

## cpp.lang.*
Boolean, Integer, Double, Long, String.

## cpp.util.*
ArrayList, HashMap.

```
ArrayList<integer> list;
printf("className: <%s>\n", list.getClassName().c_str());

integer arg1 = std::make_shared<Integer>(1234);
integer arg2 = std::make_shared<Integer>(5678);
list.add(arg1);
list.add(arg2);
printf("size: <%d>\n", list.size()); // -> 2

integer obj1 = list.get(0);
integer obj2 = list.get(1);
printf("[0]: <%d>\n", obj1->get()); // -> 1234
printf("[1]: <%d>\n", obj2->get()); // -> 5678

list.clear();
printf("size: <%d>\n", list.size()); // -> 0
```

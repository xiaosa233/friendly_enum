
# What is the friendly-enum
In C++, `enum` is a key word to define a special type.
However, we offen get trouble in this way:
```
enum class Widget {
  kFirst,
  kSecond
}

```
How can I get enum name with the value.

E.g. GetNameByValue(Widget::kFirst); Which is expected "kFirst".


This head-only lib provides a way to answer this question, in static-compiled time!

when use the lib, and define the enum type:

```
#include "friendly_enum/friendly_enum.h"

FRIENDLY_ENUM(Widget, // Where the magic happen!
    kFirst,
    kSecodnd
);

```

You can get the enum name in this way:
```
constexpr std::string_view name = GetTraiter<Widget>().GetNameByValue(Widget::kFirst);
```
And the cost is zero! Because this is the result of static compilation.

I name this kind of enum with names `friendly_enum`!

# Get started
Only test in Ubuntu, C++17 with g++ compiler.

It is head-only library.Just copy the header file:
```
friendly_enum/
   - friendly_enum.h
   - enum_traiter.h
```

# API

```
FRIEDNLY_ENUM(EnumType, one, two ... );

GetTraiter<EnumType>().
GetNameByValue // Return the name by value.
GetValueByName // Return value by name.
GetSize // Return the number of enums
GetValue // Return the value by index for enum.

```

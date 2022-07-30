
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

// Will generate the code :
enum class Widget {
  kFirst,
  kSecond,
};

using WidgetTraiter = EnumTraiter<Widget, Widget::kFirst, Widget::kSecond>;

inline constexpr auto GetTraiterByTag(EnumTag<Widget> = {}) {
  constexpr const WidgetTraiter inst("kFirst, kSecond");
  return inst;
}
using WidgetTag = fenum::EnumTag<Widget>;

```

You can get the enum name in this way:
```
constexpr std::string_view name = GetTraiter<Widget>().GetNameByValue(Widget::kFirst);
```
And the cost is zero! Because this is the result of static compilation.

I name this kind of enum with names `friendly_enum`!

# Inner-class declaration.
For inner-class enum:
```
class WidgetClass {
 public:
  FRIEND_INNER_ENUM(Widget, kFirst, kSecodnd);
}
```

And get the inner-class firendly-enum need to specify the enum tag to get the traiter:

```
// One of way.
GetTraiterByTag(fenum::EnumTag<WidgetClass>{});
GetTraiterByTag(WidgetClassTag{});
```

# Get started
Testing to Ubuntu (G++ )&& Windows(VS2022) in std C++17.

It is head-only library.Just copy the header file:
```
friendly_enum/
   - friendly_enum.h
   - enum_traiter.h
```

# API

Easy using API:

```
FRIEDNLY_ENUM(EnumType, one, two ... );

GetTraiter<EnumType>().
GetNameByValue // Return the name by value.
GetValueByName // Return value by name.
GetSize // Return the number of enums
GetValue // Return the value by index for enum.

```

# How to run test

one of the following ways:

1. Using CMake
```
cd project_files
cmake .
```

2. Using quick_cmake
```
python quick_cmake.py
```
refer to: https://github.com/xiaosa233/quick_cmake

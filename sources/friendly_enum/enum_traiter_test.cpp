#include "friendly_enum/enum_traiter.h"

#include "gtest/gtest.h"

namespace fenum {

enum class Widget {
  kFirst = 1,
  kSecond = 2,
};

using WidgetTraiter = EnumTraiter<Widget, Widget::kFirst, Widget::kSecond>;

inline constexpr auto GetTraiterByTag(EnumTag<Widget> = {}) {
  constexpr const WidgetTraiter inst("kFirst, kSecond");
  return inst;
}
using WidgetTag = fenum::EnumTag<Widget>;
constexpr WidgetTag widget_tag;

template <Widget w> struct TestWidgetValue {
  static constexpr std::string_view value =
      GetTraiter<Widget>().GetNameByValue(w);
};

TEST(EnumTraiterTest, MapToString) {
  {
    static constexpr std::string_view first_str_value =
        GetTraiter<Widget>().GetNameByValue(Widget::kFirst);
    EXPECT_EQ("kFirst", first_str_value);
    static constexpr Widget first_value =
        GetTraiter<Widget>().GetValueByName("kFirst");
    EXPECT_EQ(Widget::kFirst, first_value);
  }
  {
    static constexpr size_t enum_size = GetTraiter<Widget>().GetSize();
    EXPECT_EQ(2, enum_size);

    static constexpr Widget first_value = GetTraiter<Widget>().GetValue(0);
    EXPECT_EQ(Widget::kFirst, first_value);
  }

  EXPECT_EQ("kFirst", TestWidgetValue<Widget::kFirst>::value);
  EXPECT_EQ("kSecond", TestWidgetValue<Widget::kSecond>::value);
}

} // namespace fenum

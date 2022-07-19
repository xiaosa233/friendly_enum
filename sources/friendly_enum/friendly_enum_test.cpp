#include "friendly_enum/friendly_enum.h"

#include "gtest/gtest.h"

#include "friendly_enum/test_case/enum_a.h"
#include "friendly_enum/test_case/enum_b.h"

FRIENDLY_ENUM(Widget, kFirst, kSecond, kThird);

namespace nsp_first {
FRIENDLY_ENUM(Widget, kFirst, kSecond, kThird);
} // namespace nsp_first

namespace fenum {

template <class T> constexpr std::string_view GetEnumFirstName() {
  return GetTraiter<T>().GetNameByValue(GetTraiter<T>().GetValue(0));
}

TEST(FriendlyEnumTest, Functionality) {
  {
    static constexpr std::string_view first_str_value =
        GetTraiter<::Widget>().GetNameByValue(Widget::kFirst);
    EXPECT_EQ("kFirst", first_str_value);
    static constexpr Widget first_value =
        GetTraiter<::Widget>().GetValueByName("kFirst");
    EXPECT_EQ(Widget::kFirst, first_value);
  }
  {
    static constexpr size_t enum_size = GetTraiter<::Widget>().GetSize();
    EXPECT_EQ(3, enum_size);

    static constexpr Widget first_value = GetTraiter<::Widget>().GetValue(0);
    EXPECT_EQ(Widget::kFirst, first_value);
  }

  // Test with namespace
  {
    static constexpr std::string_view first_str_value =
        GetTraiter<nsp_first::Widget>().GetNameByValue(
            nsp_first::Widget::kFirst);
    EXPECT_EQ("kFirst", first_str_value);
    static constexpr nsp_first::Widget first_value =
        GetTraiter<nsp_first::Widget>().GetValueByName("kFirst");
    EXPECT_EQ(nsp_first::Widget::kFirst, first_value);
  }
  {
    static constexpr size_t enum_size =
        GetTraiter<nsp_first::Widget>().GetSize();
    EXPECT_EQ(3, enum_size);

    static constexpr nsp_first::Widget first_value =
        GetTraiter<nsp_first::Widget>().GetValue(0);
    EXPECT_EQ(nsp_first::Widget::kFirst, first_value);
  }

  // Test enum a
  {
    static constexpr std::string_view first_str_value =
        GetTraiter<nsp_a::EnumA>().GetNameByValue(nsp_a::EnumA::A);
    EXPECT_EQ("A", first_str_value);
    static constexpr nsp_a::EnumA first_value =
        GetTraiter<nsp_a::EnumA>().GetValueByName("A");
    EXPECT_EQ(nsp_a::EnumA::A, first_value);
  }
  {
    static constexpr size_t enum_size = GetTraiter<nsp_a::EnumA>().GetSize();
    EXPECT_EQ(2, enum_size);

    static constexpr nsp_a::EnumA first_value =
        GetTraiter<nsp_a::EnumA>().GetValue(0);
    EXPECT_EQ(nsp_a::EnumA::A, first_value);
  }

  // Test enum b
  {
    static constexpr std::string_view first_str_value =
        GetTraiter<nsp_b::EnumB>().GetNameByValue(nsp_b::EnumB::A);
    EXPECT_EQ("A", first_str_value);
    static constexpr nsp_b::EnumB first_value =
        GetTraiter<nsp_b::EnumB>().GetValueByName("A");
    EXPECT_EQ(nsp_b::EnumB::A, first_value);
  }
  {
    static constexpr size_t enum_size = GetTraiter<nsp_b::EnumB>().GetSize();
    EXPECT_EQ(2, enum_size);

    static constexpr nsp_b::EnumB first_value =
        GetTraiter<nsp_b::EnumB>().GetValue(0);
    EXPECT_EQ(nsp_b::EnumB::A, first_value);
  }

  // Test with normal template funtion.
  {
    static constexpr std::string_view value = GetEnumFirstName<::Widget>();
    EXPECT_EQ("kFirst", value);
  }
  {
    static constexpr std::string_view value =
        GetEnumFirstName<nsp_first::Widget>();
    EXPECT_EQ("kFirst", value);
  }
  {
    static constexpr std::string_view value = GetEnumFirstName<nsp_a::EnumA>();
    EXPECT_EQ("A", value);
  }
  {
    static constexpr std::string_view value = GetEnumFirstName<nsp_b::EnumB>();
    EXPECT_EQ("A", value);
  }
}

} // namespace fenum

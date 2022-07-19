#pragma once

#include <array>
#include <initializer_list>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

namespace fenum {

template <class T> struct EnumTag {
  static_assert(std::is_enum_v<T>, "T is not an enum!");
};

template <class T, T... Args> struct EnumTraiter {
  static_assert(std::is_enum_v<T>, "T is not an enum!");
  static constexpr size_t GetSize() { return kValues.size(); }

  static constexpr T GetValue(size_t index) {
    return *(kValues.begin() + index);
  }

  constexpr EnumTraiter(const std::string_view &init_str) {
    std::size_t find_pos = 0;
    int index = 0;
    while (find_pos < init_str.size()) {
      std::size_t next_find_pos = init_str.find(',', find_pos);
      if (next_find_pos == std::string_view::npos) {
        next_find_pos = init_str.size();
      }
      enum_names_[index++] =
          Trim(init_str.substr(find_pos, next_find_pos - find_pos));
      find_pos = next_find_pos + 1;
    }
  }

  constexpr T GetValueByName(const std::string_view &name) {
    for (size_t i = 0; i < enum_names_.size(); ++i) {
      if (enum_names_[i] == name) {
        return *(kValues.begin() + i);
      }
    }
    return {};
  }

  constexpr std::string_view GetNameByValue(T value) {
    for (auto it = kValues.begin(); it != kValues.end(); ++it) {
      if (*it == value) {
        return enum_names_[std::distance(kValues.begin(), it)];
      }
    }
    return "";
  }

private:
  constexpr std::string_view Trim(const std::string_view &str_view) {
    auto begin_pos = str_view.find_first_not_of(' ');
    auto end_pos = str_view.find_last_not_of(' ') + 1;
    return str_view.substr(begin_pos, end_pos - begin_pos);
  }

  static constexpr size_t N = GetSize();
  static constexpr const std::initializer_list<T> kValues = {Args...};
  std::array<std::string_view, N> enum_names_;
};

template <class T> constexpr decltype(auto) GetTraiter() {
  // I still not figout why it can get rid of the namespace.
  return GetTraiterByTag(EnumTag<T>{});
}

} // namespace fenum

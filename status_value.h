// Licensed under the Apache License, Version 2.0.

#ifndef STATUS_VALUE_H
#define STATUS_VALUE_H

#include <utility>

namespace experimental {

template <typename Status, typename Value>
class status_value {
  Status s;
  Value v;
  bool p : 1;
  status_value() = delete;

 public:
  status_value(Status s) : s(s), v(), p(false) {}
  status_value(Status s, Value&& v) : s(s), v(std::move(v)), p(true) {}
  status_value(Status s, const Value& v) : s(s), v(v), p(true) {}
  status_value(status_value&&) = default;
  const Status& status() const { return s; }
  bool has_value() const { return p; }
  operator bool() const { return p; }
  const Value& value() const {
    if (p) return v;
    throw s;
  }
  Value& value() {
    if (p) return v;
    throw s;
  }
  const Value& operator*() const { return value(); }
  Value& operator*() { return value(); }
};

}  // namespace experimental

#endif

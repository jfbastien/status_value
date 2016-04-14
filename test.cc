// Licensed under the Apache License, Version 2.0.

#include <system_error>
#include "status_value.h"

template <typename Value>
using Maybe = experimental::status_value<std::error_code, Value>;

void test() {
  Maybe<int> i((std::error_code()));
}

int main() {
  test();
  return 0;
}

# C++ `status_value`

C++ object containing both a status and a value as described in
[A Class for Status and Optional Value](http://wg21.link/p0262r0).

From the paper's description:

```cpp
template<typename Status, typename Value> class status_value;

// Construction of a status_value can be done with or without a value.
status_value::status_value(Status s);
status_value::status_value(Status s, Value&& v);
status_value::status_value(Status s, const Value& v);

// Construction of status_value must include a status.
status_value::status_value() = delete;

// A status_value may be moved. A copy operation would make the type unusable
// for non-copyable contained objects, so we do not provide a copy operation.
status_value::status_value(status_value&& sv);

// They may be queried for status. The design assumes that inlining will remove
// the cost of returning a reference for cheap copyable types.
const Status& status_value::status() const;

// They may be queried for whether or not they have a value.
bool status_value::has_value() const;
status_value::operator bool() const;

// They may provide access to their value. If they have no value, an exception
// of type Status, with the status value passed to the constructor, is thrown.
const Value& status_value::value() const;
Value& status_value::value();
const Value& status_value::operator *() const;
Value& status_value::operator *();
```

# Chapter 1 Deducing Types

## Item 1. template type deduction


### Case 1. Reference or pointer

```
template <typename T>
f(T& param)
```

lvalue type| T type | param type
----- | ----- | ----- |
int x | int | int&
----- | ----- | ----- |
const int cx | const int | const int&
----- | ----- | ----- |
const int& rx | const int | const int &
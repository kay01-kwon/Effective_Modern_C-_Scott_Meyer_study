# Chapter 1 Deducing Types

## Item 1. template type deduction


### Case 1. Reference or pointer

```
template <typename T>
f(T& param)
```

lvalue type| T type | P type
--- | --- | --- |

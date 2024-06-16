# Chapter 1 Deducing Types

## Item 1. template type deduction


### Case 1. Param type - Reference or pointer

Rule 1. If expr's type is a reference, ignore the reference part.

Rule 2. Then pattern-match expr's type against Param type to determine T.

#### 1.1 Reference

```
template <typename T>
void f(T& param)

int x = 27;
const int cx = x;
const int& rx = x;
```


expr type | T type | param type
----- | ----- | ----- |
int x | int | int&
const int cx | const int | const int&
const int& rx | const int | const int&

#### 1.2 Const reference

```
template <typename T>
void f(const T& param)
```

expr type| T type | param type
----- | ----- | ----- |
int x | int | const int&
const int cx | int | const int&
const int& rx | int | const int&

### 1.3 Pointer

```
template <typename T>
void f(T* param)
```

expr type| T type | param type
----- | ----- | ----- |
int x | int | int*
const int cx | const int | const int*
const int* px | const int | const int*

### Case 2. Param Type - Universal reference

Rule 1. expr is an lvalue &rarr; param type is deduced to be lvalue references.

Rule 2. expr is an rvalue &rarr; Case 1 rules apply.

```
template <typename T>
void f(T&& param)
```

expr type| T type | param type
----- | ----- | ----- |
int x | int& | int&
const int cx | const int& | const int&
const int& rx | const int& | const int&
27 (rvalue) | int | int&&

### Case 3. Param Type - value (Pass-by-value)

Rule 1. expr type is a reference &rarr; ignore the reference part.

Rule 2. After ignoring expr's referenceness, **const** is ignored.

```
template <typename T>
void f(T param)
```

expr type| T type | param type
----- | ----- | ----- |
int x | int | int
const int cx | int | int
const int& rx | int | int
27 (rvalue) | int | int
const char* const ptr | const char* | const char*

Note that the **const** is ignored only for by-value parameters.

When it comes to the last expr type, the constness of what ptr points to is preserved during type deduction, but the constness of ptr itself is ignored when copying it to create the new pointer, param.

### Array Arguments

#### template by-value parameter
```
template <typename T>
void f(T param)

const char name[] = "J. P. Briggs";

const char* ptrToName = name;

f(name);
```

var | T type |
---| ---|
name | const char* |

#### template by-reference parameter
```
template <typename T>
void f(T& param)
```

var | T type |
---| ---|
name | const char (&)[13] |

### Function Arguments

#### template by-value parameter
```
void someFunc(int idx, double x);

template <typename T>
void f(T param)
```

expression | T type | param type|
---| --- | --- |
f(someFunc); | void (*) (int, double)| ptr to func

#### template by-reference parameter
```
void someFunc(int idx, double x);

template <typename T>
void f(T& param)
```

expression | T type | param type|
---| --- | --- |
f(someFunc); | void (&) (int, double)| ref to func



## Item 2. auto type deduction

The same rule is applied to auto as the template.

expression | auto type | Case |explanation
--- | --- | --- | --- |
auto x = 27; | int | 3 | neigther pointer or reference
const auto cx = x; | int | 3 | neither pointer or reference
const auto& rx = x; | const int | 1 | reference
auto&& uref1 = x; | int& | 2 |x - lvalue
auto&& uref2 = cx; | const int& | 2 |cx - lvalue
auto&& uref3 = rx; | const int& | 2 |rx - lvalue
auto&& uref4 = 27; | int&& | 2 |27 - rvalue

### Array Arguments

```
const char name[] = "R. N. Briggs";

auto arr_ptr = name;
auto& arr_ref = name;

```

var | auto type |
--- | --- |
arr_ptr | const char*|
arr_ref | const char&[13]|

### Function Arguments

```
void someFunc(int idx, double value)

auto func_ptr = someFunc;
auto func_ref = someFunc;

// How to use func_ptr and func_ref.
func_ptr(1,2.3);
func_ref(2,3.3);


```

var | auto type |
--- | --- |
func_ptr | void (*)(int, double)|
func_ref | void (&)(int, double)|
# defer-cpp

## Golang and Zig "defer" analogue in c++
## Examples to use and tests is in [main.cpp](main.cpp)
## Results of tests
```
--------------------TEST-1-START---------------------
defer can't change value of local variable if it will be returned before defer destructor called. In this case int test_local_variable() don't will return 33 with for c++ rules, it returns 9
--------------------TEST-1-END-----------------------
--------------------TEST-2-START---------------------
Before defer:
int a = 1;
float b = 1.f;
double c = 11.0;
std::string d = "1";
After defer:
int a = 252130944
float b = 6.66651e-30
double c = 6.95273e-310
std::string d = STR
--------------------TEST-2-END-----------------------
--------------------TEST-3-START---------------------
test 2
--------------------TEST-3-END-----------------------
--------------------TEST-4-START---------------------
--------------------TEST-4-END-----------------------

This message is printed last among all console messages from TEST 4
--------------------TEST-5-START---------------------
--------------------TEST-5-END-----------------------

a+b+c = 90
this message is printed last among all console messages from TEST 5

```
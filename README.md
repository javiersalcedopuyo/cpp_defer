# cpp_defer
Simple single header `defer` implementation for C++ 11 and newer, inspired by languages like Zig and Swift.

## Usage example

```c++
#include <cstdio>
#include "defer.hpp"

// I personally like to redefine the macro to something that looks more like an
// actual language feature.
#define defer(f) JSP_DEFER(f)

int main()
{
    defer( printf("Outer\n") );
    {
        defer( printf("Inner\n") );
        defer( printf("Inner 2\n") );
    }
    return 0;
}
```

Output:
```
Inner 2
Inner
Outer
```

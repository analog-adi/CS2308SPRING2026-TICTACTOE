### Example Program
```cpp
#include <iostream>

void greet() {
    std::cout << "Hello from greet()\n";
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void compute() {
    std::cout << "Inside compute()\n";
    greet();
    int num = 5;
    int fact = factorial(num);
    std::cout << "Factorial of " << num << " is " << fact << "\n";
}

int main() {
    std::cout << "Starting main()\n";
    compute();
    std::cout << "Ending main()\n";
    return 0;
}
```
### Example ProgramFlow
```text
main()
│
├── compute()
│   │
│   ├── greet()
│   │   └── [Prints "Hello from greet()"]
│   │
│   └── factorial(5)
│       └── [Recursively calls factorial(n-1) until n == 1]
│       └── [Returns result to compute()]
│
└── [Prints "Ending main()"]
```

#### Additional Instructions
* You can also upload ProgramFlow.pdf or ProgramFlow.png if you have any other alternative way of showing the program flow
* Please ignore recursion calls and library function calls
* You can replace this entire `ProgramFlow.md` file with the ProgramFlow of this program.
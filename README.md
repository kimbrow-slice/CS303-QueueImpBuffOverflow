# CS303-Assignment-3 Vulnerable Queue Implementation
 Queue Implementation with valid input, error handling, and the demonstration of a buffer overflow caused by integer overflow. The lack of proper input validation or sanitization allows potential attackers to craft malicious inputs.  By allowing an operation to exceed the limits of an integer, we can show how the program's logic might fail, which leads to a crash of the program (NOT VISUAL STUDIO). The Visual Studio debugger indicates a memory access violation, which can happen after a buffer overflow where the program's memory integrity is compromised. 

#### References:
[C++ Long Integer overflow](https://stackoverflow.com/questions/44874465/long-integer-overflow-in-c)

## Setup
1. Open Visual Studio Community. (Tested in Visual Studio Community 2022 only)
2. Select File -> Open -> Project/Solution and navigate to teh downloaded project files. 
3. Choose the solution file (.sln) file or main.cpp to open the project.
4. Right click the Project in the Solution Explorer and click Set as Startup Project. 
5. Press Crtl + F5 to build and run the program without debugging, or F5 to run with debugging.

## Queue Implementation:
### Initialization, Check Empty, Display Front Element
Input: Push (1 x10): { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, Check Empty (3): Not Empty, Display Front Element (4): 0
![Valid data input from user](/Initilaztion.png)

### Display, Move to Rear, Display, Pop
Input: Display Queue (5): { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, Move to Rear (6): 0 is moved, Display Queue (5):{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 } , Pop (2): 1
![Valid data input from user](/ValidInput2.png)

### Display, Push, Clear, Display
Input: Display Queue (5): { 2, 3, 4, 5, 6, 7, 8, 9, 0 }, Push (1): 22, Clear Queue (7), Display Queue (5): {  }
![Valid data input from user](/ValidInput3.png)

### Push, Error Handling, Clear Queue, Check Empty
Input: Push (1): 3, Invalid Input: alphabetic characters, Clear Queue (7), Check Empty (3)
![Error Handling](/EmptyandErrorHanlding.png)

### Buffer Overflow caused by Integer Overflow 
**When the queue is full** Input: Push (1): 456967743077
![Buffer Overflow](/Overflow.png)

## Linear Search Modification
![Linear Search Modification](/LinearSearch/LinearSearch.png)

## Insertion Sort Modification 
![Linear Search Modification](/InsertionSort/InsertionSort.png)

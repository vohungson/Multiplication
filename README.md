# Multiplication
Problem: There are two binary number, we can multiply two binary numbers like: String mul(string a, string b). 
The programming language that I used for demonstration is C++.
- Develop the multiplication algorithm.
- The complexity of this algorithm.
- Source code file: multiplication/main.cpp

## (Solution 1) This is the solution of the teacher with the complexity is: b*log(a)
- The complexity of adding two binary numbers (number a and number b) is: MAX[log(a), log(b)].
- The solution here to muliply two binary numbers is adding the number a with itself in b times. So the complexity is: b*log(a)
- The code source of this solution in the method: string mulBinary(string a, string b)


## (Solution 2) This is the new solution with the complexity is: log(b)*log(a)
- The complexity of adding two binary numbers (number a and number b) is: MAX[log(a), log(b)].
- The solution for muliplication of two binary numbers: For the number b that we have log(b) digits (include digit 1 and digit 0). We check last digit of number b (in the right of the number b) and multiply with number a if this digit equal to 1, continue to do the same with the next digit in the left and multiply with number a (that has already shifted to left 1 digit like the photo below), we do the same with all digits of number b. Finally we will sum all like the photo below. This algorithm, we only do in log(b) times. So the complexity is: log(b)*log(a)

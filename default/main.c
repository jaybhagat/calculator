/*****************************************
 * Jay Bhagat
 * Number Theory Calculator Program in C
 *****************************************/

#include <stdio.h>

// mod(first, second) is a function that calculates the value of
//   first mod second without using the % operator.
// Time complexity: O(1)
int mod(int first, int second) {
  return first - (first / second) * second;
}

// gcd(first, second) is a function that calculates the value of
//   gcd(first, second) using the Extended Euclidean Algorithm.
// Time complexity: O(log n) where n = min(first,second)
int gcd(int first, int second) {
  if (first == 0) { // base case
    return second;
  } else {
    return gcd(mod(second,first), first); // recurse
  }
}

// lcm(first, second) is a function that calculates the value of
//   lcm(first,second) by dividing their product by their gcd.
// Time complexity: O(log n) where n = min(first,second)
int lcm(int first, int second) {
  return (first * second) / gcd(first, second);
}

int main(void) {
  // Declaring the variables that the user will input
  char operator;
  int n1, n2;
  
  // Outputting the choices that the user has and storing their
  //   choices
	printf("Enter the operation that you would like to run (g = gcd, l = lcm,  m = mod): ");
  scanf("%c", &operator);
  printf("Enter two integers: ");
  scanf("%d %d", &n1, &n2);
  
  // If statement seperating the cases for the operator
  if (operator == 'm') {
    printf("The value of %d mod %d is: %d\n", n1, n2, mod(n1,n2));
  } else if (operator == 'g') {
    printf("The value of gcd(%d,%d) is: %d\n", n1, n2, gcd(n1,n2));
  } else if (operator == 'l') {
    printf("The value of lcm(%d,%d) is: %d\n", n1, n2, lcm(n1,n2));
  } else {
    printf("Sorry, the operator you have entered is invalid.\n");
  }
}

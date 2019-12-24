The following overloaded operations can be carried out any polynomial expressions where f is declared to be a Polynomial
object:
1. f(x) where x is a double, evaluates the polynomial f with the given x value; this is basically evaluate().
2. f(g) where g is another Polynomial object, returns the Polynomial object representing the polynomial composition
of f and g where g is substituted for every occurrence of x in f.
3. -f returns the negative of f.
4. +f returns f.
5. f=g where g is another Polynomial object, assigns g into f.
6. f+=g where g is another Polynomial object, adds g into f.
7. f-=g where g is another Polynomial object, subtracts g from f.
8. f*=g where g is another Polynomial object, multiplies g into f.
9. f^=n where n is an unsigned value, raises f to the n
th power.
10. f+g where g is another Polynomial object, returns the sum of f and g.
11. f-g where g is another Polynomial object, returns the difference of f and g.
12. f*g where g is another Polynomial object,
13. f^n where n is an unsigned value, returns the value of f raised to the n
th power.
14. outs << f where outs is an ostream object, “displays” f in the traditional way with terms of decreasing exponents
(see sample output below).



Input


The program lines of text that are in groups of three. Each group of three lines represent one test case. The first two lines
will contain a list of n + 1 integers an, an−1, . . . , a1, a0 which represent a set of coefficients of a polynomial of degree n. 


Sample Input

    -2
    1 -1
    5 0 1 6
    7 6 -1
    -1 1
    7 6 -1
    3 0 0 -4 0 2
    -5 0 3 -11 4
    1 2 3 4 5


Output

For each test case, the program displays the following:
1. the test case number (starts at 1) in the form “TEST CASE #n” where n is the test case number;
2. the first polynomial in the test case and denote this as f;
3. the second polynomial in the test case and denote this as g;
4. evaluate f for all the m + 1 given values of x (x0 through xm) in the third line of input;
5. the polynomial f+g;
6. the polynomial f-g;
7. the polynomial f*g;
8. the polynomial -g;
9. the polynomial f^2;
10. the polynomial g^3;
11. the polynomial f^0;
12. the polynomial f(g); and
13. the value of g(f(-1)).



Sample Output

        TEST CASE #1
        f: -2
        g: x - 1
        -2 -2 -2 -2
        f+g: x - 3
        f-g: -x - 1
        f*g: -2x + 2
        -g: -x + 1
        f^2: 4
        g^3: x^3 - 3x^2 + 3x - 1
        f^0: 1
        f(g): -2
        g(f(-1)): -3
        
        TEST CASE #2
        f: 7x^2 + 6x - 1
        g: -x + 1
        384 287 0
        f+g: 7x^2 + 5x
        f-g: 7x^2 + 7x - 2
        f*g: -7x^3 + x^2 + 7x - 1
        -g: x - 1
        f^2: 49x^4 + 84x^3 + 22x^2 - 12x + 1
        g^3: -x^3 + 3x^2 - 3x + 1
        f^0: 1
        f(g): 7x^2 - 20x + 12
        g(f(-1)): 1

        TEST CASE #3
        f: 3x^5 - 4x^2 + 2
        g: -5x^4 + 3x^2 - 11x + 4
        1 82 695 3010 9277
        f+g: 3x^5 - 5x^4 - x^2 - 11x + 6
        f-g: 3x^5 + 5x^4 - 7x^2 + 11x - 2
        f*g: -15x^9 + 9x^7 - 13x^6 + 12x^5 - 22x^4 + 44x^3 - 10x^2 - 22x + 8
        -g: 5x^4 - 3x^2 + 11x - 4
        f^2: 9x^10 - 24x^7 + 12x^5 + 16x^4 - 16x^2 + 4
        g^3: -125x^12 + 225x^10 - 825x^9 + 165x^8 + 990x^7 - 2148x^6 + 1023x^5 + 957x^4 - 2123x^3 + 1596x^2
        - 528x + 64
        f^0: 1
        f(g): -9375x^20 + 28125x^18 - 103125x^17 + 3750x^16 + 247500x^15 - 523500x^14 + 107250x^13 + 831675x^12
        - 1.50315e+06x^11 + 675279x^10 + 1.14494e+06x^9 - 2.3189e+06x^8 + 1.64175e+06x^7 + 135165x^6
        - 1.37327e+06x^5 + 1.39938e+06x^4 - 765336x^3 + 243260x^2 - 41888x + 3010
        g(f(-1)): -2991
        
 

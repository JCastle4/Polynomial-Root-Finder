# Polynomial-Root-Finder
A program that computes roots for polynomials. The program takes as input a file which contains description of a polynomial in the following format:

n
a(n) a(n-1) a(n-2) ... a(2) a(1) b

where n is the degree of the polynomial, a(i)  is the coefficient of the monomial of degree i, and b is the constant term. For example, the polynomial:

3x^3 + 5x^2 - 7

would be represented as:

3
3  5  0 -7

The file should have extension .pol, for example, fun1.pol would be a suitable name for a file. The program uses bisection method by default and places the solution in a file with the same name as the input, but with extension .sol (such as fun1.sol), with format:

root  iterations outcome

The program uses bisection as default and operate as follows:

> polRoot [-newt, -sec, -hybrid] [-maxIt n] initP [initP2] polyFileName

By default the program uses bisection, but this can be modified with -newt for Newton's or -sec for Secant. The program should attempt 10,000 iterations by default, but this can be modified with -maxIter and the number of desired iterations. The initial point is provided (or an extra point for bisection and secant). 

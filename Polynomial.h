/** Polynomial implementation
    Developed by Sujeet Hiremath @ Chico State
    @file Polynomial.h */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <map>
#include <tuple>
#include <iostream>

using namespace std;

class Polynomial
{
  private:

    //YOUR CODE GOES IN HERE!!!
    map <unsigned, double> poly;
    unsigned countOfTerms;

  public:

  //CONSTRUCTOR(S)////////////////////////////////////////////////////////////

  /** Creates a zero polynomial.
      @post  Polynomial is set to the zero polynomial. */
      Polynomial();
  /** Creates a constant polynomial.
      @post  Polynomial is set to the constant c. */
      Polynomial(double c);
  /** Copy constructor.
      @post  Polynomial is set to the other polynomial. */
      Polynomial(const Polynomial& other);

  //DESTRUCTOR(S)/////////////////////////////////////////////////////////////

  /** Destructor
      @post  All dynamic memory allocated for the object is released. */
     ~Polynomial();

  //MODIFICATION MEMBER FUNCTIONS/////////////////////////////////////////////
  /** Resets the polynomial to the zero polynomial.
      @post  Polynomial is set to the zero polynomial. */
      void clear();
  /** Sets a term in the polynomial.
      @pre   exponent >= 0
      @post  If successful, a new term is added to the polynomial
          and the degree of the polynomial is updated, if needed.
      @param coefficient The coefficient of the new term.
      @param exponent The exponent of the new term.
      @return  True if the set was successful, or false if not. */
      bool setTerm(unsigned exponent, double coefficient);
  /** Adds to a term in the polynomial.
      @post  If successful, a new term is added to the polynomial
          and the degree of the polynomial is updated, if needed.
      @param coefficient The value to add to the coefficient of
          the term with the given exponent.
      @param exponent The exponent of the term to update.
      @return  True if addition was successful, or false if not. */
      bool addTerm(unsigned exponent, double coefficient);

  //CONSTANT MEMBER FUNCTIONS/////////////////////////////////////////////////

  /** Determines if this is the zero polynomial.
      @return true if polynomial is the constant zero. */
      bool isZero() const;
  /** Determines the degree of the polynomial.
      @return Degree of the polynomial. */
      unsigned getDegree() const;
  /** Determines the coefficient of the term with the
      given exponent.
      @param exponent The exponent of a term.
      @pre  exponent >= 0
      @post Returns the coefficient at the specified
            exponent of this Polynomial */
      double coefficient(unsigned exponent) const;
  /** Evaluates the polynomial based on a given value for x.
      @param x The value to evaluate the polynomial with.
      @return The value f(x) of the polynomial. */
      double evaluate(double x) const;
  /** Returns the composition of this polynomial where
      every occurence of x is substituted with the
      other polynomial.
      @param other The other polynomial to substitute for x.
      @return The polynomial f(g) where g is the other polynomial. */
      Polynomial sub(const Polynomial& other) const;

      Polynomial operator + (const Polynomial &g);
      Polynomial operator () (const Polynomial &g);
      double operator () (const double num);
      Polynomial operator - (const Polynomial &g);
      Polynomial operator - ();
      Polynomial operator + ();
      Polynomial operator * (const Polynomial &g);

      Polynomial operator ^ (const unsigned power);
      bool operator = (const Polynomial &g);

      bool operator += (const Polynomial &g);
      bool operator -= (const Polynomial &g);
      bool operator *= (const Polynomial &g);
      bool operator ^= (const unsigned power);


     friend ostream &operator<<( ostream &cout, const Polynomial &D );
};

#endif

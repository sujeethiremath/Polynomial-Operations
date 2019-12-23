#include "Polynomial.h"
#include<math.h>

//Polynomial constructor with no parameters
Polynomial::Polynomial()
{
    countOfTerms = 0;
}

//Polynomial constructor with 1 parameter
Polynomial::Polynomial(double c)
{
    addTerm(0,c);
}

//Polynomial constructor with 1 parameter object, (Copy Constructor)
//copies map of other polynomial into current object
Polynomial::Polynomial(const Polynomial &other)
{
   for(auto it=other.poly.begin();it!=other.poly.end();++it)
   {
          double coefficient = it->second;
          unsigned exponent = it->first;
          poly.insert(pair<unsigned,double>(exponent,coefficient));
          countOfTerms++;
   }

}

//destructor
Polynomial :: ~Polynomial()
{}

//inserting the coefficients and exponents into map as value(coefficient) and key(exponent) pair
bool Polynomial ::addTerm (unsigned exponent, double coefficient)
{

    poly.insert(pair<unsigned,double>(exponent,coefficient));
    countOfTerms++;                    //keeping count of terms created for the polynomial
    return true;
}

//returns highest exponent of the polynomial expression
unsigned Polynomial :: getDegree() const
{
  return countOfTerms-1;
}

//evaluates terms for the double values of x
double Polynomial ::evaluate (double x) const
{
    double sum=0, result=0;
    for(auto it=poly.begin();it!=poly.end();++it)
    {
          double coefficient = it->second;     
          double powerofX = pow(x,it->first);  //calculates values of x raised to exponent
          sum = coefficient * powerofX;
          result = result+sum;

    }
    return result;
}

//clears the polynomial object
 void Polynomial:: clear()
 {
     poly.clear(); //clears the polynomial map
     countOfTerms = 0;
 }

bool Polynomial :: setTerm(unsigned exponent, double coefficient)
{
    if(poly.empty() == true) //If polynomial expression is empty, it adds as the first term
    {
      poly.insert(pair<unsigned,double>(exponent,coefficient));
      return true;
    }

    for(auto it=poly.begin();it!=poly.end();++it)
    {
        if(it->first == exponent)
        {
            it->second = coefficient;        //if already the term exists, overiding the coefficient with new one
        }
        else
        {
            poly.insert(pair<unsigned,double>(exponent,coefficient));   //if the term in the polynomial doesn't exist, create just the term
        }
    }

    return true;
}

//returns coefficient of the associated key exponent requested 
double Polynomial :: coefficient(unsigned exponent)const
{

    for(auto it=poly.begin();it!=poly.end();++it)
    {
        if(it->first == exponent)
        return it->second;
    }
    return 0;
}

//checks if the polynomial is zero polynomial
bool Polynomial:: isZero() const
{
  
  if(getDegree() > 1)
  return false;
  
  for(auto it = poly.begin();it!=poly.end();++it)
  {
    if(it->first == 0 && it->second == 0)
    return true;
  }
  
  return false;

}

//substitutes one polynomial into another
Polynomial Polynomial::sub(const Polynomial& other)const
{
   Polynomial result;
  Polynomial temp;
  Polynomial temp2;
  Polynomial temp3 = other;

  for(auto itf = poly.begin();itf!=poly.end();++itf)
  {
    double coF = itf->second;
    unsigned exF = itf ->first;
    temp = temp3^exF;  //raising the substitute polynomial power to same as the originial term exponent

    for(auto it = temp.poly.begin();it!=temp.poly.end();++it)
    {
        double newCo = coF * it->second;  //multiplying the coefficients of substitute polynomial with original polynomial  
        unsigned newEx = it->first;
        temp2.addTerm(newEx,newCo); // adding the new term thus created in the map
    }

    for(auto itn = temp2.poly.begin();itn!=temp2.poly.end();++itn)
    {
          auto tempX = result.poly.find(itn->first);

          if(tempX->first == itn->first && tempX!=result.poly.end())
          tempX->second = itn->second + tempX->second;      //adding the coefficients of the similar exponents    
          else
          result.addTerm(itn->first,itn->second); 
    }
    temp.clear();
    temp2.clear();
  }

  return result;
}

//overloaded functions of the operator += which does the addition of polynomial f and g and stores into f;
bool Polynomial :: operator += (const Polynomial &g)
{
    Polynomial temp = (*this); //accessing current object
    Polynomial temp2;
    temp2 = (temp + g);
    
    for(auto it=temp2.poly.begin();it!=temp2.poly.end();++it)
    {
      setTerm(it->first,it->second); //setting terms of ther current object as per the result of f+g
    }
  
  return true;


}

//overloaded functions of the operator -= which does the substraction of polynomial f and g and stores into f;
bool Polynomial :: operator -= (const Polynomial &g)
{
    Polynomial temp = (*this);  //accessing current object
    Polynomial temp2;
    temp2 = (temp - g);
    
    for(auto it=temp2.poly.begin();it!=temp2.poly.end();++it)
    {
      setTerm(it->first,it->second);  //setting terms of ther current object as per the result of f-g
    }
  
  return true;


}

//overloaded functions of the operator *= which does the multiplication of polynomial f and g and stores into f;
bool Polynomial :: operator *= (const Polynomial &g)
{
    Polynomial temp = (*this); //accessing current object
    Polynomial temp2;
    temp2 = (temp * g);
    
    for(auto it=temp2.poly.begin();it!=temp2.poly.end();++it)
    {
      setTerm(it->first,it->second); //setting terms of ther current object as per the result of f*g
    }
  
  return true;
}

//overloaded functions of the operator ^= which calculates the power of polynomial f and g and stores into f;
bool Polynomial :: operator ^= (const unsigned power)
{
    Polynomial temp = (*this); //accessing current object
    Polynomial temp2;
    temp2 = (temp ^ power);
    
    for(auto it=temp2.poly.begin();it!=temp2.poly.end();++it)
    {
      setTerm(it->first,it->second); //setting terms of the current object as per the result of f^number
    }
  
  return true;


}

//operator overloading function for * to calculate multiplication f * g
Polynomial Polynomial::operator * (const Polynomial &g)
{
  Polynomial result;

  for(auto itf=poly.begin();itf!=poly.end();++itf)
  {
      double coF = itf->second;
      unsigned exF = itf->first;

      for(auto itg = g.poly.begin();itg!=g.poly.end();++itg)
      {
          double coG = itg->second;  
          unsigned exG = itg->first;
          double newCo = coF*coG;  //multiplying coefficient of f with the coefficients of g polynomial
          unsigned newEx = exF+exG; //Addition of exponent of f and g
          auto temp = result.poly.find(newEx);
          if(temp->first == newEx && temp!=result.poly.end())
          temp->second = newCo + temp->second;  //if the exponents are same of any two terms in the polynomial expression after multiplication
          else                                  //then adding those two terms
          result.addTerm(newEx,newCo);
      }
  }
  return result;
}

//copies contents of map of one obejct into another
bool Polynomial::operator = (const Polynomial &g)
{
    for(auto it=g.poly.begin();it!=g.poly.end();++it)
   {
          double coefficient = it->second;
          unsigned exponent = it->first;
          addTerm (exponent,coefficient);
   }
  return true;
}

//operator overloading function for parenthesis () to calculate value of the polynomial for the given value of x
double Polynomial :: operator () (const double num)
{
  double number = num,result;
  result = evaluate(number);
  return result;

}

//operator overloading function for parenthesis to sibstitute one polynomial expression into another
Polynomial Polynomial :: operator () (const Polynomial &g)
{
  Polynomial f((*this)),gNew(g);
  
  Polynomial result=f.sub(g);
  
  return result;
  
}

//operator overloading function for + operator which adds two polynomials f and g and returns their result
Polynomial Polynomial::operator + (const Polynomial &g)
{
    Polynomial result;
    auto it=poly.begin();
    auto itr = g.poly.begin();
    auto itend = g.poly.end();
    --itend;
      for(;it!=poly.end();++it)
      {

          double coeffOfBig = it->second;
          unsigned exponentBig = it->first;
          double coeffOfSmal = itr->second;
          unsigned exponentSmal = itr->first;

              if(exponentBig == exponentSmal)
              {
                  double newCoeff=0;
                  if(coeffOfBig == 0)
                  {
                    newCoeff=coeffOfSmal;  
                  }
                  else if(coeffOfSmal == 0)
                  {
                    newCoeff=coeffOfBig;
                  }
                  else
                  {
                    newCoeff = coeffOfBig + coeffOfSmal;   //addition of one coefficient of polynomial with another of other polynomial
                  }                                        // having terms with same exponent
                  
                  result.addTerm(exponentBig,newCoeff);
              }

              if(itr != itend)
              itr++;
              else
              break;
      }


      if(poly.size() > g.poly.size())    //if original polynomial is greater in size than another then inserting remaining terms 
      {                                  //directly into the resulting polynomial    
            while(it!=poly.end())
            {
                double coeff = it->second;
                unsigned exponent = it->first;
                result.addTerm(exponent,coeff);
                ++it;
            }

      }
      else
      {
            while(itr!=g.poly.end())
            {
                double coeff = itr->second; //if second polynomial is greater in size than original then inserting remaining terms
                unsigned exponent = itr->first; //directly into the resulting polynomial 
                result.addTerm(exponent,coeff);
                itr++;
            }

      }

    return result;  //returning result of f+g
}

//returns the negative of the polynomial expression
Polynomial Polynomial:: operator - ()
{


  Polynomial result;

      for(auto itg = poly.begin();itg!=poly.end();++itg)
      {
          double coG = itg->second;
          unsigned exG = itg->first;
          double newCo = coG * -1 ;   //multiplying each terms coefficient with -1 
          result.addTerm(exG,newCo);
      }


  return result;

}


Polynomial Polynomial:: operator + ()  //resturns the original polynomial
{


  Polynomial result;

      for(auto itg = poly.begin();itg!=poly.end();++itg)
      {
          double coG = itg->second;
          unsigned exG = itg->first;
          result.addTerm(exG,coG);
      }


  return result;

}

//raises the power of the expression to requested number
Polynomial Polynomial:: operator ^ (const unsigned power)
{


    Polynomial f((*this)),resultZe(1),result,temp;

    if(power == 0)
    return resultZe;
    else if(power == 1)
    return f;

    result = f * f;  

    for(unsigned i=2;i<power;i++)
    {
         temp = (result * f);  //multiplying the same polynomial with itself to attain the requested power of the polynomial
         result.clear();
         result = temp;
         temp.clear();

    }


    return result;


}

//returns substraction of two polynomials f - g
Polynomial Polynomial::operator - (const Polynomial &g)
{
    Polynomial result;
    auto it=poly.begin();
    auto itr = g.poly.begin();
    auto itend = g.poly.end();
    --itend;
      for(;it!=poly.end();++it)
      {

          double coeffOfBig = it->second;
          unsigned exponentBig = it->first;
          double coeffOfSmal = itr->second;
          unsigned exponentSmal = itr->first;

              if(exponentBig == exponentSmal)
              {
                  double newCoeff=0;
                  if(coeffOfBig == 0)
                  {
                    newCoeff=coeffOfSmal*-1;
                  }
                  else if(coeffOfSmal == 0)
                  {
                    newCoeff = coeffOfBig;
                  }
                  else
                  {
                    newCoeff = coeffOfBig - coeffOfSmal;  //substracting coefficient of first polynomial and second polynomial
                  }
                  result.addTerm(exponentBig,newCoeff);
              }

              if(itr!=itend)
              ++itr;
              else
              break;
      }


      if(poly.size() > g.poly.size()) //if the original polynomial is greater in size adding the remaining terms
      {
            while(it!=poly.end())
            {
                double coeff = it->second;
                unsigned exponent = it->first;
                result.addTerm(exponent,coeff);
                ++it;
            }

      }
      else
      {
            while(itr!=g.poly.end())       //if the second polynomial is greater in size addding the remaining terms
            {                              // by multiplying the coeficients of the second polynomial with -1
                double coeff = ((itr->second)*-1);
                unsigned exponent = itr->first;
                result.addTerm(exponent,coeff);
                ++itr;
            }

      }

    return result;
}

//overloaded operation of << which return ostream object
ostream &operator<<( ostream &cout, const Polynomial &D )
{

    unsigned count=0;
    unsigned size = D.poly.size();

     for(auto it=D.poly.rbegin();it!=D.poly.rend();++it)
     {
           double coefficient = it->second;
           unsigned exponent = it->first;
           auto temp = it;
           ++temp;
          double next = temp->second;


           if(coefficient>1 && exponent>1)
           {
             cout<<coefficient;
             cout<<"x^"<<exponent;
           }
           if(coefficient<-1 && exponent>1 && count == 0)
           {
             cout<<coefficient;
             cout<<"x^"<<exponent;
           }
           else if(coefficient<-1 && exponent>1 && count>0)
           {
             cout<<(coefficient * -1);
             cout<<"x^"<<exponent;
           }
           else if (coefficient>1 && exponent==1)
           {
             cout<<coefficient;
             cout<<"x";
           }
           else if (coefficient<-1 && exponent==1 && count==0)
           {
             cout<<coefficient;
             cout<<"x";
           }
           else if (coefficient<-1 && exponent==1 && count>0)
           {
             cout<<coefficient*-1;
             cout<<"x";
           }
           else if(coefficient == 1 && exponent>1)
           {
             cout<<"x^"<<exponent;
           }
           else if(coefficient == 1 && exponent == 1)
           {
             cout<<"x";
           }
           else if(coefficient == -1 && exponent==1 && count>0)
           {
             cout<<"x";
           }
           else if(coefficient == -1 && exponent==1 && count==0)
           {
             cout<<"-x";
           }
           else if(coefficient == -1 && exponent>1 && count>0)
           {
             cout<<"x^"<<exponent;
           }
           else if(coefficient == -1 && exponent>1 && count==0)
           {
             cout<<"-x^"<<exponent;
           }

            if(next > 0 && count < size && count+1 != size)
           cout<<" + ";
           else if(next < 0 && count < size && count+1 != size)
           cout<<" - ";

           if(exponent == 0 && coefficient>0)
           cout<<coefficient;
           else if(exponent == 0 && coefficient < 0 && count <= size && count>0)
           cout<<coefficient * -1;
           else if(exponent == 0 && coefficient < 0 && count <= size )
           cout<<coefficient;

           count++;

     }
     
     return cout;

}

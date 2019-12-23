#include "Polynomial.h"

#include <sstream>  // for istringstream
#include <vector>
#include <string>

using namespace std;


vector<string> split( const string& s , char delimiter )
    {
        vector<string> tokens;          // vector of tokens
        string token;                   // a single token
        istringstream tokenStream(s);   // an input string stream

        // Tokenize s by grabbing individual tokens
        while( getline( tokenStream , token , delimiter ) )
            tokens.push_back(token);    // add found token

        return tokens;
    }



int main()
{
    string input;
    unsigned flag=1; //flags for keeping track of getline inputs
    //unsigned count=0;                 // input string to hold 1 line from cin
    char   delimiter = ' ';       // what separates tokens in the input string
    vector<string> listOfTokens;
    vector<double> evaluateResult;
    unsigned count = 1;
      // store tokens of input here
 
   // Read in a string as a line of text from standard input.
 
    Polynomial f,g,mul;
    while( getline( cin , input ) ) {
 
        // Use the split() function above to extract tokens
        listOfTokens = split( input , delimiter );        
        
        if(flag==1)
        {                       
           vector<double> inputData;   //holds input of coefficient
           unsigned preSize = 0;    
           for(unsigned b=0;b<listOfTokens.size();b++)
           {
             if(stod(listOfTokens[b])==0)
             preSize++;
             else
             break;
           }
           for(unsigned i=preSize;i<listOfTokens.size();i++)
             inputData.push_back(stod(listOfTokens[i]));
           unsigned k=0;  
           for(int i=inputData.size()-1; i!=-1; i-- )
        	{
				      f.addTerm(k,inputData[i]);     //adding the terms of the first object f
            	k++;
            }
          flag=2;
          cout<<"TEST CASE #"<<count<<endl;
          cout<<"f: "<<f;
          cout<<endl;
                 
        }
        else if(flag==2)
        {
           vector<double> inputData;         
           unsigned preSize = 0;    
           for(unsigned b=0;b<listOfTokens.size();b++)
           {
             if(stod(listOfTokens[b])==0)
             preSize++;
             else
             break;
           }
           for(unsigned i=preSize;i<listOfTokens.size();i++)
             inputData.push_back(stod(listOfTokens[i]));
           unsigned k=0;  
           for(int i=inputData.size()-1; i!=-1; i-- )
        	{
				      g.addTerm(k,inputData[i]);     //adding the terms of the second object g
            	k++;
            }
          flag=3; 

        }
        else if(flag==3)
        {
          
          for(unsigned j=0;j<=(listOfTokens.size()-1);j++)
          {
              double values = stod(listOfTokens[j]); //converting values of f(x) from string to double
              evaluateResult.push_back(f.evaluate(values));
          }
          flag=1;
          count++;
          cout<<"g: "<<g;
          cout<<endl;
          for(unsigned i=0;i<evaluateResult.size();i++)  // loop to print evaluate function results
          {
              if(i < (evaluateResult.size()) -1)
              cout<<evaluateResult[i]<<" ";
              else
              cout<<evaluateResult[i];
          }
          cout<<endl<<"f+g: "<<(f+g);
          cout<<endl<<"f-g: "<<(f-g);
          cout<<endl<<"f*g: "<<(f*g);
          cout<<endl<<" -g: "<<(-g);
          cout<<endl<<"f^2: "<<(f^2);
          cout<<endl<<"g^3: "<<(g^3);
          cout<<endl<<"f^0: "<<(f^0);
          Polynomial z = f(g);
          cout<<endl<<"f(g): "<<z;
          double res = g(f(-1));
          cout<<endl<<"g(f(-1)): "<<res;
          cout<<endl<<endl;
          f.clear();  //clearing first object for next input
          g.clear();   //clearing second object for next input
          evaluateResult.clear();     //clearing result
        }
 
    }
    
    return 0;


}
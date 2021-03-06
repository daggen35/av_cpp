/*
 * smart_pointer-basics-test.cc    Smart pointer I, Step 1
 *
 * Testing constructors, destructor, dereferencing, indirection and
 * assignment.
 */
#include <iostream>
#include <iomanip>
#include "smart_pointer.h"
using namespace std;
using namespace IDA_Smart_Pointer_I;

int main()
{
  cout << "Default constructor initializes to null pointer:\n";
  cout << "smart_pointer sp0;\n\n";
  smart_pointer sp0();
  //cout <<"\nny\n";
  //smart_pointer apa();//l�gg till private default �ss� funkar ej heller

   // Trick to check the value of the raw pointer.
   cout << "Using operator-> with ordinary member function call syntax\n";
   cout << "sp0.operator->(): " << sp0.operator->() << "\n\n";

   // operator* applicerar inbyggda operator* p� den r�a pekaren ptr_, vilket
   // ger exekveringsfel f�r sp0, eftersom dess ptr_ �r en tompekare.

   cout << "Typomvandlande konstruktor initierar med pekare till objekt\n";
   cout << "smart_pointer sp1(new int(1));\n\n";
   smart_pointer sp1(new int(1));

   cout << "Using operator-> with ordinary member function call syntax\n";
   cout << "sp1.operator->(): " << sp1.operator->() << "\n\n";

   cout << "Using operator* with ordinary member function call syntax\n";
   cout << "sp1.operator*(): " << sp1.operator*() << "\n\n";

   cout << "operator* applied the usual way (dereferencing)\n";
   cout << "*sp1: " << *sp1 << "\n\n";

   *sp1 = 11147;
   cout << "*sp1 = 11147 is perfomed\n*sp1: " << *sp1 << "\n\n";

   cout << "Copy constructor is used\nsmart_pointer sp2(sp1);\n";
   smart_pointer sp2(sp1);
   cout << "*sp2: " << *sp2 << "\n\n";

   cout << "Copy assignment operator is used:\nsp0 = sp2;\n";
   sp0 = sp2;
   cout << "*sp0: " << *sp0 << "\n\n";

   cout << "Declaring and initializing a raw pointer\n";
   cout << "int* px = new int(2);\n";
   int* p = new int(2);
   cout << "\nAssigning to the raw pointer:\nsp2 = p;\n";
   sp2 = p;
   cout << "*sp2: " << *sp2 << "\n\n";

   cout << "Declaring constant smart_pointer\n";
   cout << "const smart_pointer csp(new int(0));\n";
   const smart_pointer csp(new int(0));
   // Should be possible, but not with current implementation:
// cout << "*csp: " << *csp << "\n\n";

   // Shall not be possible to do, and is not possible with current implementation:
// csp = sp0;
// *csp = 0;

   cout << "Copy assignment operator is used:\nsp0 = csp;\n";
   sp0 = csp;
   cout << "*sp0: " << *sp0 << "\n\n";

   return 0;
}

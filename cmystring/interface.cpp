#include "cmystring.h"

using namespace std;

int main()
{
  CMystring ss("hello");

  CMystring xx(ss);

  CMystring zz = "123";

  zz = (move(CMystring("HI")));
  return 0;
}
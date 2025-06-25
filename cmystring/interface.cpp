#include "cmystring.h"

using namespace std;

int main()
{
  CMystring ss("hello");

  CMystring xx(ss);

  CMystring zz = ss + move(xx);

  printf("%s\n", zz.get_string());
  return 0;
}
#include "cmystring.h"

using namespace std;

int main()
{
  CMystring ss;
  ss.set_string("hello");

  CMystring xx;
  char buf[5] = "123";

  printf("%s\n", xx.get_string());
  printf("%d\n", xx.get_len());

  return 0;
}
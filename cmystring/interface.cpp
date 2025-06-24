#include "cmystring.h"

using namespace std;

int main()
{
  CMystring ss;
  ss.set_string("hello");
  printf("%s\n", ss.get_string());
  return 0;
}
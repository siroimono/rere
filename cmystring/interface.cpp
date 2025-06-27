#include "cmystring_Ex.h"

using namespace std;

int main()
{
  CMystring_Ex aaa;
  aaa.set_string("1 sex 1");
  printf("%s\n", aaa.get_string());

  CMystring *bbb = new CMystring_Ex;
  bbb->set_string("1 fuck 1");
  printf("%s\n", bbb->get_string());
  delete bbb;
  return 0;
}
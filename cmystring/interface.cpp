#include "cmystring.h"

using namespace std;

int main()
{
  // CMystring ss("hello");
  // CMystring xx(" world");
  // CMystring zz = ss + move(xx);

  CMystring haha("haha");
  CMystring hihi("hihi");
  CMystring tmp = haha.operator+(hihi);

  CMystring aa;
  CMystring ret1 = aa + "world";

  CMystring cc("ccc");
  CMystring ret3 = cc + "ddd";

  CMystring ff("fff");
  CMystring ret4 = "ddd" + ff;

  printf("%s\n", ret1.get_string());

  printf("%s\n", ret3.get_string());

  printf("%s\n", ret4.get_string());

  return 0;
}
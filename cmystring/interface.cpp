#include "cmystring.h"

using namespace std;

int main()
{
  CMystring aaa("aaa ");
  CMystring bbb("bbb");
  aaa += bbb;
  printf("%s \t %d\n", aaa.get_string(), aaa.get_len());

  CMystring ccc("ccc");
  aaa += move(ccc);
  printf("%s \t %d\n", aaa.get_string(), aaa.get_len());

  aaa += "ddd";
  printf("%s \t %d\n", aaa.get_string(), aaa.get_len());

  CMystring fff("fff");
  aaa += ("eee" += fff);
  printf("%s \t %d\n", aaa.get_string(), aaa.get_len());

  CMystring ggg("hello");
  for (int i = 0; i < ggg.get_len() - 1; i++)
  {
    printf("%c\n", ggg.operator[](i));
  }

  ggg[999];

  return 0;
}
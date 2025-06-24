#include "cmystring.h"

using namespace std;

int main()
{
  CMystring ss("hello");
  // ss.set_string("hello");

  // printf("%s\n", ss);
  cout << ss << endl;
  printf("%s\n", ss.get_string());

  return 0;
}
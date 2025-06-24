#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class CMystring
{
private:
  char *pchar;

public:
  CMystring();

  ~CMystring();

  char *get_string();

  void set_string(const char *cin);
};
// C++
#include <string>
#include <iostream>
#include <cstddef>

// C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class CMystring
{
private:
  char *pchar;
  size_t st_len;

public:
  CMystring();

  ~CMystring();

  const char *get_string() const;

  size_t get_len() const;

  void set_string(const char *cin);
};
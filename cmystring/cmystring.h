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
  char *pchar = nullptr;
  size_t st_len;

public:
  CMystring();

  ~CMystring();

  CMystring(const CMystring &r_v);

  CMystring(CMystring &&r_v);

  CMystring(const char *r_v);
  //-----------------------------------------------------------------//
  CMystring &operator=(const CMystring &r_v);

  CMystring &operator=(CMystring &&r_v);

  CMystring operator+(const CMystring &r_v);

  CMystring operator+(CMystring &&r_v);

  operator const char *();
  //-----------------------------------------------------------------//

  char *get_string() const;

  size_t get_len() const;

  void set_string(const char *cin);

  char *make_plus(int len1, int len2, const CMystring &r_v);
};
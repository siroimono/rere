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
  size_t st_len = 0;

public:
  CMystring();

  ~CMystring();

  CMystring(const CMystring &r_v);

  CMystring(CMystring &&r_v);

  explicit CMystring(const char *r_v);
  //-----------------------------------------------------------------//
  CMystring &operator=(const CMystring &r_v);

  CMystring &operator=(CMystring &&r_v);

  CMystring &operator=(const char *r_v);

  CMystring operator+(const CMystring &r_v);

  CMystring operator+(CMystring &&r_v);

  CMystring operator+(const char *r_v);

  char &operator[](const int r_v);

  CMystring &operator+=(const CMystring &r_v);

  CMystring &operator+=(CMystring &&r_v);

  CMystring &operator+=(const char *r_v);

  friend CMystring operator+(const char *pChar, CMystring &&r_v);

  friend CMystring operator+(const char *pChar, CMystring &r_v);

  friend const char *operator+=(const char *pChar, CMystring &&r_v);

  friend const char *operator+=(const char *pChar, CMystring &r_v);

  // operator const char *();
  //-----------------------------------------------------------------//

  char *get_string() const;

  size_t get_len() const;

  void set_string(const char *cin);

  char *append_1(int len1, int len2, const CMystring &r_v);

  char *append_2(int len1, int len2, const char *pChar);

  char *append_3(int len1, int len2, const char *pChar);
};

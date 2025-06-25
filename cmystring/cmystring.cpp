#include "cmystring.h"

using namespace std;

CMystring::CMystring()
{
  printf("CMystring()\n");
}

CMystring::~CMystring()
{
  printf("~CMystring()\n");
  free(this->pchar);
}

CMystring::CMystring(const CMystring &r_v)
{
  printf("CMystring(CMystring& r_v)\n");
  this->set_string(r_v.get_string());
}

CMystring::CMystring(CMystring &&r_v)
{
  printf("CMystring(CMystring&& r_v) - move\n");
  free(this->pchar);
  this->pchar = r_v.pchar;
  r_v.pchar = nullptr;
}

CMystring::CMystring(const char *r_v)
{
  printf("CMystring(const char* r_v)\n");
  this->set_string(r_v);
}

//------------------------------------------------------------------//
CMystring &CMystring::operator=(const CMystring &r_v)
{
  printf("CMystring::operator=(const CMystring &r_v)");
  this->set_string(r_v.get_string());
  return *this;
}

CMystring &CMystring::operator=(CMystring &&r_v)
{
  printf("CMystring::operator=(CMystring&& r_v) - move");
  free(this->pchar);
  this->pchar = r_v.pchar;
  r_v.pchar = nullptr;
  return *this;
}

CMystring::operator const char *()
{
  return this->pchar;
}
//------------------------------------------------------------------//
char *CMystring::get_string() const
{
  return this->pchar;
}

size_t CMystring::get_len() const
{
  return this->st_len;
}

void CMystring::set_string(const char *cin)
{
  if (pchar != NULL)
  {
    free(this->pchar);
  }
  size_t st_len = strlen(cin) + 1;
  this->st_len = st_len;
  this->pchar = (char *)malloc(st_len);
  memset(this->pchar, 0, sizeof(*cin));
  strcpy(this->pchar, cin);
}

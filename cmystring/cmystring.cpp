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
  printf("CMystring::operator=(const CMystring &r_v)\n");
  this->set_string(r_v.get_string());
  return *this;
}

CMystring &CMystring::operator=(CMystring &&r_v)
{
  printf("CMystring::operator=(CMystring &&r_v)\n");
  free(this->pchar);
  this->pchar = r_v.pchar;
  r_v.pchar = nullptr;
  return *this;
}

CMystring CMystring::operator+(const CMystring &r_v)
{
  printf("CMystring::operator+(const CMystring &r_v)\n");

  CMystring tmp_obj;
  char *p_tmpc = this->append_1(this->st_len, r_v.st_len, r_v);
  tmp_obj.pchar = p_tmpc;
  return tmp_obj;
}

CMystring CMystring::operator+(CMystring &&r_v)
{
  printf("CMystring::operator+(CMystring &&r_v)\n");

  CMystring tmp_obj;
  char *p_tmpc = append_1(this->st_len, r_v.st_len, r_v);
  tmp_obj.pchar = p_tmpc;
  return tmp_obj;
}

CMystring CMystring::operator+(const char *r_v)
{
  printf("CMystring::operator+(const char *r_v)\n");

  CMystring tmp_obj;
  int len2 = strlen(r_v);
  char *p_tmpc = this->append_3(this->st_len, len2, r_v);
  tmp_obj.pchar = p_tmpc;
  return tmp_obj;
}

CMystring operator+(const char *pChar, CMystring &r_v) // friend
{
  printf("operator+(const char *pChar, CMystring &r_v)\n");

  CMystring tmp_obj;
  int len1 = strlen(pChar);
  char *p_tmpc = r_v.append_2(len1, r_v.st_len, pChar);
  tmp_obj.pchar = p_tmpc;
  return tmp_obj;
}

CMystring operator+(const char *pChar, CMystring &&r_v) // friend
{
  printf("operator+(const char *pChar, CMystring &&r_v)\n");

  CMystring tmp_obj;
  int len1 = strlen(pChar);
  char *p_tmpc = r_v.append_2(len1, r_v.st_len, pChar);
  tmp_obj.pchar = p_tmpc;
  return tmp_obj;
}

/*
CMystring::operator const char *()
{
  return this->pchar;
}
  */
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
  memset(this->pchar, 0, st_len);
  strcpy(this->pchar, cin);
}

char *CMystring::append_1(int len1, int len2, const CMystring &r_v)
{
  if (this->pchar == nullptr && r_v.pchar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len2) + 1);
    strcpy(p_tmpc, r_v.pchar);
    return p_tmpc;
  }
  else if (r_v.pchar == nullptr && this->pchar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len1) + 1);
    strcpy(p_tmpc, this->pchar);
    return p_tmpc;
  }
  else if (this->pchar != nullptr && r_v.pchar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len1 + len2) + 1);
    strcpy(p_tmpc, this->pchar);
    strcat(p_tmpc, r_v.pchar);
    return p_tmpc;
  }
}

char *CMystring::append_2(int len1, int len2, const char *pChar)
{
  if (this->pchar == nullptr && pChar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len2) + 1);
    strcpy(p_tmpc, pChar);
    return p_tmpc;
  }
  else if (pChar == nullptr && this->pchar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len1) + 1);
    strcpy(p_tmpc, this->pchar);
    return p_tmpc;
  }
  else if (this->pchar != nullptr && pChar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len1 + len2) + 1);
    strcpy(p_tmpc, pChar);
    strcat(p_tmpc, this->pchar);
    return p_tmpc;
  }
}

char *CMystring::append_3(int len1, int len2, const char *pChar)
{
  if (this->pchar == nullptr && pChar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len2) + 1);
    strcpy(p_tmpc, pChar);
    return p_tmpc;
  }
  else if (pChar == nullptr && this->pchar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len1) + 1);
    strcpy(p_tmpc, this->pchar);
    return p_tmpc;
  }
  else if (this->pchar != nullptr && pChar != nullptr)
  {
    char *p_tmpc = (char *)malloc((len1 + len2) + 1);
    strcpy(p_tmpc, this->pchar);
    strcat(p_tmpc, pChar);
    return p_tmpc;
  }
}

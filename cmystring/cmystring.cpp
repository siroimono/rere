#include "cmystring.h"

using namespace std;

CMystring::CMystring()
{
  printf("CMystring()\n");
}

CMystring::~CMystring()
{
  printf("~CMystring()\n");
  delete[] (this->pchar);
}

CMystring::CMystring(const CMystring &r_v)
{
  printf("CMystring(CMystring& r_v)\n");
  this->set_string(r_v.get_string());
}

CMystring::CMystring(CMystring &&r_v)
{
  printf("CMystring(CMystring&& r_v) - move\n");
  delete[] (this->pchar);
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
  delete[] (this->pchar);
  this->pchar = r_v.pchar;
  r_v.pchar = nullptr;
  return *this;
}

CMystring &CMystring::operator=(const char *r_v)
{
  printf("operator=(const char *r_v)\n");
  this->set_string(r_v);
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

char &CMystring::operator[](const int r_v)
{
  try
  {
    printf("operator[](const int r_v)\n");
    if (r_v < 0 || r_v >= strlen(this->pchar))
    {
      throw string("... this obj char * == nullptr... \n");
    }
    else if (this->pchar == nullptr)
    {
      throw string("... this obj char * == nullptr... \n");
    }
    return *(this->pchar + r_v);
  }
  catch (string err)
  {
    printf("ERR... %s\n", err.c_str());
  }
}

CMystring &CMystring::operator+=(const CMystring &r_v)
{
  printf("operator+=(const CMystring &r_v)\n");

  int len1 = this->st_len;
  int len2 = r_v.st_len;
  char *p_tmpc = this->append_1(len1, len2, r_v);
  delete[] (this->pchar);
  this->pchar = p_tmpc;
  this->st_len = strlen(this->pchar);
  return *this;
}

CMystring &CMystring::operator+=(CMystring &&r_v)
{
  printf("operator+=(CMystring &&r_v)\n");

  int len1 = this->st_len;
  int len2 = r_v.st_len;
  char *p_tmpc = this->append_1(len1, len2, r_v);
  delete[] (this->pchar);
  this->pchar = p_tmpc;
  this->st_len = strlen(this->pchar);
  return *this;
}

CMystring &CMystring::operator+=(const char *r_v)
{
  printf("operator+=(const CMystring &r_v)\n");

  int len1 = this->st_len;
  int len2 = strlen(r_v);
  char *p_tmpc = this->append_3(len1, len2, r_v);
  delete[] (this->pchar);
  this->pchar = p_tmpc;
  this->st_len = strlen(this->pchar);
  return *this;
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

const char *operator+=(const char *pChar, CMystring &r_v) // friend
{
  printf("operator+=(const char *pChar, CMystring &r_v)\n");

  int len1 = strlen(pChar);
  int len2 = strlen(r_v.pchar);
  const char *p_tmpc = r_v.append_2(len1, len2, pChar);
  return p_tmpc;
}

const char *operator+=(const char *pChar, CMystring &&r_v) // friend
{
  printf("operator+=(const char *pChar, CMystring &&r_v)\n");

  int len1 = strlen(pChar);
  int len2 = strlen(r_v.pchar);
  const char *p_tmpc = r_v.append_2(len1, len2, pChar);
  return p_tmpc;
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
  if (set_(cin))
  {
    if (pchar != NULL)
    {
      delete[] (this->pchar);
    }
    this->pchar = new char[10];
    strcpy(this->pchar, "fix_name");
    return;
  }

  if (pchar != NULL)
  {
    delete[] (this->pchar);
  }
  size_t st_len = strlen(cin) + 1;
  this->st_len = st_len;
  this->pchar = new char[st_len];
  strcpy(this->pchar, cin);
}

bool CMystring::set_(const char *&cin) // virtual
{
  cout << "?" << endl;
  return false;
}

char *CMystring::append_1(int len1, int len2, const CMystring &r_v)
{
  if (this->pchar == nullptr && r_v.pchar != nullptr)
  {
    char *p_tmpc = new char[len2];
    strcpy(p_tmpc, r_v.pchar);
    return p_tmpc;
  }
  else if (r_v.pchar == nullptr && this->pchar != nullptr)
  {
    char *p_tmpc = new char[len1];
    strcpy(p_tmpc, this->pchar);
    return p_tmpc;
  }
  else if (this->pchar != nullptr && r_v.pchar != nullptr)
  {
    char *p_tmpc = new char[len1 + len2];
    strcpy(p_tmpc, this->pchar);
    strcat(p_tmpc, r_v.pchar);
    return p_tmpc;
  }
}

char *CMystring::append_2(int len1, int len2, const char *pChar)
{
  if (this->pchar == nullptr && pChar != nullptr)
  {
    char *p_tmpc = new char[len1];
    strcpy(p_tmpc, pChar);
    return p_tmpc;
  }
  else if (pChar == nullptr && this->pchar != nullptr)
  {
    char *p_tmpc = new char[len2];
    strcpy(p_tmpc, this->pchar);
    return p_tmpc;
  }
  else if (this->pchar != nullptr && pChar != nullptr)
  {
    char *p_tmpc = new char[len1 + len2];
    strcpy(p_tmpc, pChar);
    strcat(p_tmpc, this->pchar);
    return p_tmpc;
  }
}

char *CMystring::append_3(int len1, int len2, const char *pChar)
{
  if (this->pchar == nullptr && pChar != nullptr)
  {
    char *p_tmpc = new char[len2];
    strcpy(p_tmpc, pChar);
    return p_tmpc;
  }
  else if (pChar == nullptr && this->pchar != nullptr)
  {
    char *p_tmpc = new char[len1];
    strcpy(p_tmpc, this->pchar);
    return p_tmpc;
  }
  else if (this->pchar != nullptr && pChar != nullptr)
  {
    char *p_tmpc = new char[len1 + len2];
    strcpy(p_tmpc, this->pchar);
    strcat(p_tmpc, pChar);
    return p_tmpc;
  }
}

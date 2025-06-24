#include "cmystring.h"

using namespace std;

CMystring::CMystring()
{
  printf("CMystring()\n");
}

CMystring::~CMystring()
{
  printf("~CMystring()\n");
}

char *CMystring::get_string()
{
  return this->pchar;
}

void CMystring::set_string(const char *cin)
{
  if (pchar != NULL)
  {
    free(this->pchar);
  }
  this->pchar = (char *)malloc(sizeof(*cin));
  memset(this->pchar, 0, sizeof(*cin));
  strcpy(this->pchar, cin);
}

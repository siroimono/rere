#include "cmystring_Ex.h"

using namespace std;

CMystring_Ex::CMystring_Ex()
{
  printf("CMystring_Ex::CMystring_Ex()\n");
}

CMystring_Ex::~CMystring_Ex()
{
  printf("CMystring_Ex::~CMystring_Ex()\n");
}

bool compare(const char *s)
{
  regex rex(R"(\bsex\b | \bfuck\b)");
  string tmps(s);
  return regex_search(tmps, rex);
}

bool CMystring_Ex::set_(const char *&cin)
{
  cout << "???" << endl;
  return compare(cin);
}

/*
void CMystring_Ex::set_string(const char *cin)
{
  if (compare(cin))
  {
    printf("... sex ... fuck ... -> name X\n");
    CMystring::set_string("fix_name");
  }
  return;
}
  */
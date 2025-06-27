#include "cmystring.h"

using namespace std;

class CMystring_Ex : public CMystring
{
public:
  CMystring_Ex();

  ~CMystring_Ex();

  // void set_string(const char *cin);

  bool set_(const char *&cin);
};

bool compare(const char *s);
#ifndef __GIT_OID__H
#define __GIT_OID__H

#include <git2.h>

class GitObjectID
{
  public:
    GitObjectID(const git_oid* oid);

    const git_oid* oid;

  private:

};

#endif

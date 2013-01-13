#ifndef __GIT_REFERENCE__H
#define __GIT_REFERENCE__H

#include <git2.h>
#include "git_object_id.h"

class GitReference
{
  public:
    GitReference(git_reference* reference);
    ~GitReference();

    // Move semantics:
    GitReference(GitReference&& other);
    GitReference& operator=(GitReference&& other);

    bool is_oid();
    GitObjectID get_object_id();

  private:
    // TODO - find a way to copy a reference in libgit2
    // For now though, disable copy constructor and assignment operator
    // Copy semantics:
    GitReference(const GitReference& other) = delete;
    GitReference& operator=(GitReference& other) = delete;

    git_reference* ref;

};

#endif

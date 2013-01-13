#include "git_reference.h"

GitReference::GitReference(git_reference* reference) :
  ref(reference)
{
}

GitReference::GitReference(GitReference&& other)
{
  this->ref = other.ref;
  other.ref = NULL;
}

GitReference& GitReference::operator=(GitReference&& other)
{
  this->ref = other.ref;
  other.ref = NULL;
  return *this;
}

GitReference::~GitReference()
{
  git_reference_free(ref);
}

GitObjectID GitReference::get_object_id()
{
  const git_oid* oid = git_reference_target(ref);

  if (oid == NULL)
  {
    //Probably a symlink
    //TODO - Throw an exception
  }

  GitObjectID object_id(oid);

  return object_id;
}

bool GitReference::is_oid()
{
  //TODO - implement
  return true;
}

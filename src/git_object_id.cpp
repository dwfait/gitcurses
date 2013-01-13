#include "git_object_id.h"

GitObjectID::GitObjectID(const git_oid* oid) :
  oid(oid)
{
}

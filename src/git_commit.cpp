#include "git_commit.h"
#include <iostream>

GitCommit::GitCommit(git_commit* commit) :
  commit(commit)
{
}

GitCommit::~GitCommit()
{
  git_commit_free(commit);
}

GitCommit::GitCommit(GitCommit&& other)
{
  this->commit = other.commit;
  other.commit = NULL;
}

GitCommit& GitCommit::operator=(GitCommit&& other)
{
  this->commit = other.commit;
  other.commit = NULL;
  return *this;
}

std::string GitCommit::message()
{
  std::string msg(git_commit_message(commit));

  return msg;
}

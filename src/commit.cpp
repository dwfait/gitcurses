#include "commit.h"
#include <git2.h>
#include <sstream>
#include <iostream>

Commit::Commit(GitCommit& commit)
{
  git_commit* c = commit.commit;
  const git_signature* signature = git_commit_author(c);

  this->author_name = signature->name;
  this->author_email = signature->email;

  this->message = std::string{git_commit_message(c)};

  char* oid_string = git_oid_allocfmt(git_commit_id(c));
  this->ref_hash = oid_string;
  delete[] oid_string;
}


bool Commit::is_valid()
{
  return (
      first_line_under_50_chars() &&
      second_line_blank() &&
      all_under_72_chars());
}

bool Commit::first_line_under_50_chars()
{
  size_t first_nl = message.find_first_of("\n", 0);

  if (first_nl == std::string::npos)
  {
    if (message.size() <= 50)
    {
      return true;
    } else {
      return false;
    }
  } else {
    if (first_nl > 50)
    {
      return false;
    } else {
      return true;
    }
  }
}

bool Commit::second_line_blank()
{
  size_t first_new_line = message.find_first_of("\n", 0);
  size_t second_new_line = message.find_first_of("\n", first_new_line + 1);

  if (first_new_line == std::string::npos ||
      second_new_line == std::string::npos)
    return true;

  return (second_new_line == first_new_line + 1);
}

bool Commit::all_under_72_chars()
{
  size_t nl_marker = message.find_first_of("\n", 0);
  size_t next_nl_marker = message.find_first_of("\n", nl_marker + 1);

  while (next_nl_marker != std::string::npos)
  {
    if ((next_nl_marker - nl_marker) > 72)
      return false;

    nl_marker = next_nl_marker;
    next_nl_marker = message.find_first_of("\n", nl_marker + 1);
  }

  return true;
}

std::string Commit::to_str()
{
  std::stringstream str;

  str << "commit: " << ref_hash << std::endl;
  str << message << std::endl;
  str << std::endl;

  return str.str();
}

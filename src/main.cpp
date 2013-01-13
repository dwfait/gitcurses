#include <iostream>
#include <git2.h>

#include "git_repository.h"
#include "git_walker.h"
#include "commit.h"

void print_git2_verion()
{
  int major, minor, rev;
  git_libgit2_version(&major, &minor, &rev);
  std::cout << "Using version: " << major <<"."<<minor<<"."<<rev<<std::endl;
}

void print_commits()
{
  std::string remote_repo = "https://github.com/libgit2/libgit2.git";

  GitRepository repo = GitRepository::init_or_clone_repo(remote_repo, "libgit2");

  GitWalker walker{repo};

  auto commits = walker.extract_head_commits();

  for (auto& c : commits)
  {
    if (!c.is_valid())
    {
      std::cout << c.to_str();
    }
  }
}

int main(int argc, char** argv)
{
  print_commits();

  return 0;
}

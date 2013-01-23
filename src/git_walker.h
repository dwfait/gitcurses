#ifndef __GIT_WALKER__H
#define __GIT_WALKER__H

#include <git2.h>
#include "commit.h"
#include "git_repository.h"
#include <vector>
#include <string>

class GitWalker
{
  public:
    GitWalker(GitRepository& repository);
    ~GitWalker();

    // Move semantics:
    GitWalker(GitWalker&& other);
    GitWalker& operator=(GitWalker&& other);

    std::vector<Commit> extract_head_commits();
    std::vector<Commit> extract_commits();

  private:
    // TODO - find a way to copy a repo in libgit2
    // For now though, disable copy constructor and assignment operator
    // Copy semantics:
    GitWalker(GitWalker& other) = delete;
    GitWalker& operator=(GitWalker& other) = delete;
    GitWalker(const GitWalker& other) = delete;
    GitWalker& operator=(const GitWalker& other) = delete;

    git_revwalk* walker;
    git_repository* repo;

};

#endif

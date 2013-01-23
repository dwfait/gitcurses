#ifndef __GIT_COMMIT__H
#define __GIT_COMMIT__H

#include <git2.h>
#include <string>
#include <vector>

class GitCommit
{
  public:
    GitCommit(git_commit* commit);
    ~GitCommit();

    GitCommit(GitCommit&& other);
    GitCommit& operator=(GitCommit&& other);

    std::string message();
    std::vector<GitCommit> commit_ancestry();

    git_commit* commit;
  private:
    GitCommit(GitCommit& other) = delete;
    GitCommit(const GitCommit& other) = delete;
    GitCommit& operator=(GitCommit& other) = delete;
    GitCommit& operator=(const GitCommit& other) = delete;
};

#endif

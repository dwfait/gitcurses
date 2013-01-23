#ifndef __GIT_REPO__H
#define __GIT_REPO__H

#include <git2.h>
#include "git_reference.h"
#include "git_commit.h"
#include <string>

class GitRepository
{
  public:
    GitRepository(git_repository* repo);
    ~GitRepository();

    // Move semantics:
    GitRepository(GitRepository&& other);
    GitRepository& operator=(GitRepository&& other);

    GitReference get_head_reference();
    GitCommit commit_lookup(GitObjectID& oid);

    static GitRepository init_or_clone_repo(
        std::string url,
        std::string path);

    const git_repository* get_repo() const;

  private:
    // Disabled Copy semantics:
    GitRepository(GitRepository& other) = delete;
    GitRepository& operator=(GitRepository& other) = delete;
    GitRepository(const GitRepository& other) = delete;
    GitRepository& operator=(const GitRepository& other) = delete;

    git_repository* repo;

};

#endif

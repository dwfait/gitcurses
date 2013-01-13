#include "git_walker.h"

GitWalker::GitWalker(GitRepository& repository)
{
  this->repo = const_cast<git_repository*>(repository.get_repo());

  git_revwalk_new(&walker, repo);

  // Default settings for the walker:
  git_revwalk_sorting(walker, GIT_SORT_TIME);
}

GitWalker::~GitWalker()
{
  git_revwalk_free(walker);
}


std::vector<Commit> GitWalker::extract_head_commits()
{
  git_revwalk_push_head(walker);

  return extract_commits();
}

std::vector<Commit> GitWalker::extract_commits()
{
  std::vector<Commit> commits;

  git_oid current_oid;

  while ((git_revwalk_next(&current_oid, walker)) == 0)
  {
    git_commit* c = NULL;

    int error = git_commit_lookup(&c, repo, &current_oid);

    if (error != 0)
    {
      // TODO - handle error (exception)
    }
    GitCommit commit(c);

    commits.push_back(Commit(commit));
  }

  return commits;
}

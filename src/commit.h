#ifndef __COMMIT__H
#define __COMMIT__H

#include <string>
#include <vector>
#include "git_commit.h"

class Commit
{
  public:
    Commit(GitCommit& commit);

    std::string message;
    std::string author_name;
    std::string author_email;
    std::string ref_hash;

    bool is_valid();
    std::string to_str();

  private:
    bool first_line_under_50_chars();
    bool second_line_blank();
    bool all_under_72_chars();
};

#endif

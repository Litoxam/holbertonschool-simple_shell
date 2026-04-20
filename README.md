# holbertonschool-simple_shell

## Project GitHub Flow

For this project we will use externals ressources in order to have a nice collaboration flow.

Using keywords to prefix branches and commits messages like:

- feat
- docs
- fix
- build

<u>examples</u>:\
branch -> "feat/build_main_header"\
commit -> "docs: adding gitflow chapter to readme"

### How to push my work ?

In order to make a new feature, fix or documentation I need to make a new branch as explain above. 
```bash
git checkout -b <branch_name>
```

When work is done I fetch the parent branch (dev) to see there is some change, if there are changes I need to pull and merge.
```bash
git checkout dev
git fetch
git pull
git checkout <working_branch>
git merge dev
```
This process avoids breaking dev or main branch. So I need to resolve conflict on my working branch before making a PR on GitHub and merge on dev.

If I have a new PR from my coworker I need to check his code and  comment if I have questions or validate the PR to merge.

## Ressources:

### Github Flow:
- https://githubflow.github.io/
- https://nvie.com/posts/a-successful-git-branching-model/

### Naming convention (branches and commits messages)
- https://buzut.net/cours/versioning-avec-git/bien-nommer-ses-commits
- https://codeheroes.fr/blog/git-comment-nommer-ses-branches-et-ses-commits/

### Markdown styling documentation
- https://google.github.io/styleguide/docguide/style.html

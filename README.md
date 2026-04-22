<img height="35" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# holbertonschool-simple_shell

## Description
This project aims to recreate a simplified version of a Unix shell. While not implementing all features, it handles PATH resolution, built-in commands such as `exit` and `env`, and supports both interactive and non-interactive modes.
## Flowchart
![flowchart](assets/flowchart_simple_shell.svg)
## Requirements
For this school project the asking requirements are:
- OS: Ubuntu 20.04 LTS (development OS)
- Compiler: `gcc`
- Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty Style

External ressources:
- Betty linter: https://github.com/hs-hq/Betty
## Installation
In order to use this beautiful program you need to clone the repo with git, compile with flag and launch it:
```bash
git clone https://github.com/Litoxam/holbertonschool-simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
```
## Usage
### Interactive mode
Interactive mode starts when you launch program and you can interact with it. You can stop it with `exit` or `CTRL+D`.
```bash
./hsh
<3 /bin/ls
AUTHORS                 _atoi.c                 a.out                   check_builtins.c        execute_cmd_line.c      handle_env.c            hsh.1                   main.h
README.md               _getenv.c               assets                  cmd_checker.c           get_cmd_path.c          handle_exit.c           main.c                  parsing_user_input.c
<3 
```
### Non-Interactive mode
Non-Interactive mode starts when you launch program and you can't interact with. It launches program and stop.
```bash
echo "/bin/ls" | ./hsh
AUTHORS                 _atoi.c                 a.out                   check_builtins.c        execute_cmd_line.c      handle_env.c            hsh.1                   main.h
README.md               _getenv.c               assets                  cmd_checker.c           get_cmd_path.c          handle_exit.c           main.c                  parsing_user_input.c
```

## Built-ins
We implemented in this project some builtins commands.

### `exit`
You can stop the simple shell with this command and add a output code.
```bash
<3 exit 98
julien@ubuntu:~/shell$ echo $?
98
julien@ubuntu:~/shell$ 
```

### `env`
You can print your environment variables with this command.
```bash
julien@ubuntu:~/shell$ ./simple_shell
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
julien@ubuntu:~/shell$ 
```

## Project GitHub Flow

For this project we will use externals resources in order to have a nice collaboration flow.

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

## Resources:

### Github Flow:
- https://githubflow.github.io/
- https://nvie.com/posts/a-successful-git-branching-model/

### Naming convention (branches and commits messages)
- https://buzut.net/cours/versioning-avec-git/bien-nommer-ses-commits
- https://codeheroes.fr/blog/git-comment-nommer-ses-branches-et-ses-commits/

### Markdown styling documentation
- https://google.github.io/styleguide/docguide/style.html

## Authors
BERNIER Maxime [github profile](https://github.com/Litoxam)\
VAUDET Guillaume [github profile](https://github.com/GuillaumeVaudet)
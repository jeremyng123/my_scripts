@REM commmand to add a new repo into current module
@REM git submodule add <remote_url> <destination_folder>
git submodule add %1 %2

@REM after cloning this submodule into this project, we commit and push it to github
@REM MAKE SURE YOU USE FORWARD SLASH `/` and not `\`!!! git interprets the slashes differently!
git filter-branch --force --index-filter "git rm --cached --ignore-unmatch %1" --prune-empty --tag-name-filter cat -- --all

@REM NOTE: DO NOT USE THIS SCRIPT UNLESS U KNOW WHAT U ARE DOING!
git push origin --force --all
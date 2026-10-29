# Basic commands

## 1. Check what's going on git status `git status`

- Before commiting check what has changes

`git status`

Example: 

```terminal
Changes to be committed:
	modified: uml/class-diagram.png

Changes not staged for commit:
	modified: src/Customer.java
```

## 2. See exactly waht you staged git diff `git diff`

After:
`git add filename`

run:
`git diff --cached`
This shows **the actual changes that are staged**

Can also run:
`git diff`
This shows **the changes that are NOT staged**

## 3. git add `git add`

Stages changes for the next commit

**dir** = directory name

One file:
`git add dir/filename`

Multiple files:
`git add dir/filename1 dir/filename2`

Entire directory:
`git add dir/`

Everything that's been changed:

`git add .`


## 4. Git commit `git commit`

Creates a snapshot from whatever you've staged previously using `git add`

`git commit -m "message"`

## 5. Git push `git push`

Uploads your local commits to GitHub

`git push`

Might need to initially write:
`git push -u origin development`

The `-u` establishes the upstream relationship


## 6. Git pull `git pull`

Downloads changes from GitHub and incorporates them into your local branch

`git pull`

Useful when:

- Working from multiple computers
- Prof/teammate changed something
- Someone pushed changes to the branch


## 7. Branches `git branch`

See your branches:

`git branch`

Example:
```
* development
  main
```

The `*` means you're curently on development

### Create a branch 

`git branch feature/customer`

This creates it but doesn't switch to it

### Switch branches

Modern Git:

`  git switch feature/customer`

Older/common command:

`git checkout feature/customer`

**Both do the same**

## 8. Create AND switch to a branch

Modern Git:

`git switch -c feature/customer`

Older syntax:

`git checkout  -b feature/customer`

## 9. Git checkout `git checkout`

Switch to a branch:
`git checkout development`

Create and switch to branch:
`git checkout -b feature-x`

## 10. Git log `git log`

See your commit History
`git log`

Example:
```
commit fffff
Author: Kem
Date: ......

	Add UML Class Diagram

comit ffffa
	
	Initial project structure 
```

Can use: 

`git log --oneline`
to make each commit appear in a line **easier to read**

## 11. Undo staging `git restore`

Suppose you accidentaly used 

`git add .`

You can unstage a file with 
`git restore --stages filename`

## 12. rename/move files `git mv`

`git mv oldname.c newname.c`


## 13. Delete a tracked file `git rm`

`git rm filename`

Then commit:
`git commit -m "Removed old UML Diagram`


## 14. Fetch without changing your files `git fetch`

`git fetch`

This downloads information about changes from GitHub but doesn't actually merge them into your current branch.
## 15. Merge `git merge`

Suppose youre on:
**development**

and want to merge another branch into it
`git merge feature/customer`

Git will then incorporate the commits from feature/customer into the `development` branch


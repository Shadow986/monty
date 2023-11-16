#!/bin/bash
# Updating local with remote changes
git pull

# Run 'git add .' to stage all changes
git add .

# Get the list of modified files
modified_files=$(git diff --name-only --cached)

# Generate the commit message
	commit_message="Applied modifications to files:"
	for file in $modified_files; do
	commit_message+=" $file"
	done

# Commit the changes with the generated message			
	git commit -m "$commit_message"

# Push the changes to the remote repository				
	git push

	echo "Changes committed and pushed with message: $commit_message"

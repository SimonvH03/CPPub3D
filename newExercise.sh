#!/bin/bash

# Ensure the script is called with the correct number of arguments
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <target_directory> <program_name> [class_name_1 ...]"
	exit 1
fi

# Assign arguments to variables
TARGET_DIR=$1
PROGRAM_NAME=$2
SRC_DIR="$TARGET_DIR/src"
CLASSES=("${@:3}")

# Create required directories
mkdir -p "$TARGET_DIR"
mkdir -p "$SRC_DIR"

# Call scripts to mke Class files, MakeFile and main
printf "\n\e[32mCalling makeClassFiles.sh\e[0m\n"
./makeClassFiles.sh "$SRC_DIR" "${CLASSES[@]}"

printf "\n\e[32mCalling makeMake.sh\e[0m\n"
./makeMake.sh "$TARGET_DIR" "$PROGRAM_NAME" "1"

# Summary of created files
printf "\n\e[32mAll files created:\e[0m\n"
find "$TARGET_DIR" -type f | sort | while read -r file; do
	filename=$(basename "$file")
	filepath=$(realpath --relative-to="./" "$file")
	case "${filename##*.}" in
		hpp) color="\e[35m" ;; # Purple
		cpp) color="\e[36m" ;; # Cyan
		Makefile) color="\e[31m" ;; # Red
		*) color="\e[37m" ;; # Default
	esac
	printf "${color}+\e[0m %s/${color}%s\e[0m\n" "$(dirname "$filepath")" "$filename"
done

#!/bin/bash

# Ensure the script is called with the correct number of arguments
if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <target_directory> <class_name_1> [class_name_2 ...]"
	exit 1
fi

# Assign arguments to variables
DEST_DIR="$1/classes"
shift

# Create the source directory if it doesn't exist
mkdir -p "$DEST_DIR"

for CLASS_NAME in "$@"; do
# Define filenames
HEADER_FILE="$DEST_DIR/$CLASS_NAME.hpp"
SOURCE_FILE="$DEST_DIR/$CLASS_NAME.cpp"

# Create the header file with basic class definition
cat > "$HEADER_FILE" <<EOF
#ifndef ${CLASS_NAME^^}_HPP
# define ${CLASS_NAME^^}_HPP
# include <iostream>

class $CLASS_NAME
{
	private:

	protected:

	public:
		$CLASS_NAME();
		$CLASS_NAME($CLASS_NAME const &original);
		$CLASS_NAME &operator=($CLASS_NAME const &original);
		~$CLASS_NAME();
};

#endif
EOF

# Create the source file with basic class implementation
cat > "$SOURCE_FILE" <<EOF
#include "$CLASS_NAME.hpp"

$CLASS_NAME::$CLASS_NAME()
{
	std::cout << "$CLASS_NAME Default Constructor\n";
}

$CLASS_NAME::$CLASS_NAME($CLASS_NAME const &original)
{
	std::cout << "$CLASS_NAME Copy Constructor\n";
	*this = original;
}

$CLASS_NAME &$CLASS_NAME::operator=($CLASS_NAME const &original)
{
	std::cout << "$CLASS_NAME Assignment Operator\n";
	if (this != &original)
	{
	}
	return (*this);
}

$CLASS_NAME::~$CLASS_NAME()
{
	std::cout << "$CLASS_NAME Destructor\n";
}
EOF

# Notify the user of the created files
echo "Created class files:"
echo "+ $HEADER_FILE"
echo "+ $SOURCE_FILE"
done
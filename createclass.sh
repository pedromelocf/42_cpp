#!/bin/bash

if [ -z "$1" ]; then
  echo "Error: Please provide a class name."
  exit 1
fi

CLASS_NAME=$1
HEADER_DIR="includes"
SOURCE_DIR="src"

mkdir -p $HEADER_DIR
mkdir -p $SOURCE_DIR

HEADER_FILE="${HEADER_DIR}/${CLASS_NAME}.hpp"
SOURCE_FILE="${SOURCE_DIR}/${CLASS_NAME}.cpp"

cat > $HEADER_FILE <<EOL
#ifndef ${CLASS_NAME^^}_HPP
# define ${CLASS_NAME^^}_HPP

#include <iostream>

class ${CLASS_NAME} {

    private:

    public:
        ${CLASS_NAME}();
        ${CLASS_NAME}(const ${CLASS_NAME}& other);
        ${CLASS_NAME}& operator=(const ${CLASS_NAME}& other);
        ~${CLASS_NAME}();
};

#endif 
EOL

cat > $SOURCE_FILE <<EOL
#include "../${HEADER_FILE}"

${CLASS_NAME}::${CLASS_NAME}() {
    // Constructor implementation
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) {
    // Copy constructor implementation
}

${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& other) {
    if (this != &other) {
        // Copy assignment implementation
    }
    return *this;
}

${CLASS_NAME}::~${CLASS_NAME}() {
    // Destructor implementation
}
EOL

echo "Class files for '$CLASS_NAME' generated successfully."

#paste into /usr/local/bin to use system wide.
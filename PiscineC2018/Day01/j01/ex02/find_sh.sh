find . -name "*.sh" -print | rev | cut -c 4- | rev | grep -o '[^\/]*$'

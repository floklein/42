find . -name "*.sh" -print | rev | cut -d '.' -f2 | cut -d '/' -f1 | rev

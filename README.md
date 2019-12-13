# text_analysis
Run from the command line

# Project Summary:
This project takes input in the form of text files, I personally used Project Gutenberg texts such as Sherlock Holmes or other classics. This input is then processed, removing all the most common words, found in stop-word-list.txt, which can be added to or removed as needed. This process then finds the remaining words, how many times they appear in the text, and the number of unique words found in the text. As well, it finds the shortest and longest words in the text. It is compiled, runs, and outputs data all on the CLI.


# Compilation Copy/Paste:
gcc text_analyzer.c -o analyzer.exe

gcc text_analyzer.h

# Execution Copy/Paste:
./analyzer.exe

# Known Bugs:
Occurrence tracking fails on first couple words

trim isnt applying to min/max for some reason

Does not trim unicode characters, primarily works only with ASCII values



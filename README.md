# Tower-puzzle-solver
A project made to solve the lesser known tower sudoku game using a recursive function to fill it out and check the validity,
until a solution has been found. Will work up until 7x7 tower puzzles (in under 8s on a home machine), 
bigger ones will take significantly longer and may time out. Normal Tower puzzles use the 5x5 format.

The only external funtion used iw write, all other functions are "home-made". I included the program in an already compiled form. To (re)compile it simply use the:
gcc *.c -Wall -Wextra -Werror "program name" command while in the directory where you put the C files.

The input required for the format is: first views from top row, than from bottom row, than from left colomn and lastly from right colomn. 
The program will figure out the size of the puzzle and solve it. (e.g. for 4x4 ./puzzle-solver.out TOP1 TOP2 TOP3 TOP4 BOT1 BOT2 BOT3 BOT4 LEFT1 LEFT2 LEFT3 LEFT4 RIGHT1 RIGHT2 RIGHT3 RIGHT4), giving you and error when given a puzzle that's impossible to solve or if inputs are wrong. (according to what caused the erro you'll get a different error message.)

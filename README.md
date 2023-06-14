# Lem_in
=======

## Description
Lem_in is a first-year project at Epitech in which we aim to determine the optimal path for each ant. The program must be run with a specific file that contains all necessary information.

The first number in this file represents the number of ants. Following this, the subsequent lines will detail the rooms available. Each room entry is described by its name, followed by two numbers. These numbers are necessary for the program to run, but their specific values do not matter.

Special commands are used to designate the start and end rooms: ##start and ##end, respectively. The ##start command denotes the room where the ants begin their journey, and the ##end command designates the finish line.

Finally, the connections between rooms are provided. This is represented by two room names separated by a '-' character.

## Install and Run the project
### Requirements
---
To use the Lem_in, you need to install the dependencies and launch it locally on your PC.

*Clone the project:*
```
git clone git@github.com:ablaring/Lem_in.git

cd Lem_in
```

*Generate the anthill file:*
```
usage : gmin.pl size density nb_of_fourmiz
When size is the number of rooms and density the percentage of probability of connexions between rooms
```

*Run the project:*
```
./lem_in < anthill
```

Enjoy !

---

## Example of Program Execution
Here's an example of how you might run the lem_in program and what the expected output would look like:

```
./lem_in < anthill
```

This command feeds the 'anthill' file into the lem_in program. Below is an illustration of the format the 'anthill' file might take and the corresponding output:

```
#number_of_ants
3

#rooms
##start
0 1 0
##end
1 13 0
2 5 0
3 9 0

#tunnels
0-2
2-3
3-1

#moves
P1-2
P1-3 P2-2
P1-1 P2-3 P3-2
P2-1 P3-3
P3-1
```
Note the specific sections of the file:

#number_of_ants specifies the number of ants in the simulation.
#rooms gives the list of rooms available, denoted by their names followed by two necessary but value-unimportant numbers.
#tunnels lists the connections between the rooms.
#moves indicates the movement of ants from one room to another, in the format P<ant_number>-<room_name>.
Each move is separated by a space, and each move in a new time unit is separated by a newline. The simulation progresses until all ants have reached the end.

## Developers
- [Arthur Blaringhem](https://github.com/ablaring)
- [Maxence Poirette](https://github.com/MaxencePrt)
- [Raphaël Sillegue](https://github.com/raaphh)
- [Enzo Boron](https://github.com/EnzoBoron)
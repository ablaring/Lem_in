# Lem_in
=======

## Description
Lem_in is a first-year project at Epitech in which we aim to determine the optimal path for each ant. The program must be run with a specific file that contains all necessary information.

The first number in this file represents the number of ants. Following this, the subsequent lines will detail the rooms available. Each room entry is described by its name, followed by two numbers. These numbers are necessary for the program to run, but their specific values do not matter.

Special commands are used to designate the start and end rooms: ##start and ##end, respectively. The ##start command denotes the room where the ants begin their journey, and the ##end command designates the finish line.

Finally, the connections between rooms are provided. This is represented by two room names separated by a '-' character.

Remember to format your README file well to improve readability. Break the text into smaller sections or bullet points, and consider adding some examples to help your users understand better.

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

## RESULT
∼/B-CPE-200> ./lem_in < anthill
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

## Developers
- [Arthur Blaringhem](https://github.com/ablaring)
- [Maxence Poirette](https://github.com/MaxencePrt)
- [Raphaël Sillegue](https://github.com/raaphh)
- [Enzo Boron](https://github.com/EnzoBoron)
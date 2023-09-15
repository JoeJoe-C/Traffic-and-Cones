# Assignment 01

By: Yoseph Campbell

---

## What do

In this assignment, we will be making our own game.
The game will use Terminal as our interface

---

## Requirements

- Proper use of a makefile to compile the program
- program executable is called **"traffic"**

### Command Line Arguements

- Program is called **"traffic"**
- Program accepts two arguements, <map_row>, <map_col> such
that it defines the size of the playable area.
- Assumptions:
  - User will provide proper datatype
  - BUT you need to check for negative integers and respond
  accordingly
  - min value for <map_row> is 3 AND has to be and ODD number
  min value for <map_col> is 5
  - If the amound of arguements are > 2 or < 2, should print a
  msg and end program but NOT using the exit() function. This
  assumption applies for the same range of <map_row> and <map_col>
  - Use malloc() to allocate the 2d matrix for mapSize.

### Main Interface

Once program is run, it should:

- clear terminal screen & then print 2D map along with:
  - player (P)
  - goal (G)
  - traffics

e.g:

```
*******
*P    *
*-->--*
*    G*
*******
Press w to move up
Press s to move down
press a to move left
press d to move right
```

- The player, P is always at the top left
- The goal, G is always at the bottom right
- every even line there is a road, where initial location of car
is random.
- The user can move the Player one tile, in according to the
typed commands
- Each time the user moves, it updates the interface by clearingand printing the updated display

### Game Play

Demonstration video available in blackboard

#### User input

- User only needs to type 1 character for each command (lower
case)
- only (w,a,s,d) any other characters, should print("invalid key")
- Program should receive input wihtout pressing enter, this
means we have to disable echo and canonical feature on linux
temporarily.
- Player can only move, if there is space to move.
- The player can "jump" over the car if both of them do not
arrive at the same location, the game will continue

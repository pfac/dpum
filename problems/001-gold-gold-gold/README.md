Gold! Gold! Gold!
=================

![Glóin](https://raw.github.com/pfac/dpum/master/problems/001-gold-gold-gold/img.jpg "Glóin")

## Introduction

Like all Dwarves, Glóin Rockcrusher loves gold. He loves to hunt for gold while singing his favourite song "Gold! Gold! Gold!". Thanks to his magic map, it is a somewhat simple task. Glóin wants you to tell him how many spots of gold are reachable.


## Problem

You are given a map of the entire mine that contains Glóin's position as long as all the position of all the gold. Your goal is to count how many are reachable from Glóin's position. Notice that, due to a family curse, Glóin can only walk orthogonally and not diagonally.


## Constraints

 Limit         | Description
:-------------:|:---------------------------------
 3 < Rs <= 200 | The number of rows on the map
 3 < Cs <= 200 | The number of columns on the map
 0 <= G < 4000 | The number of gold sites
 0 <= R < Rs   | Glóin's row on the map
 0 <= C < Cs   | Glóin's column on the map


## Input

The input starts by a line containing the number of columns Cs and rows Rs on the map. The following lines contain the map. Each character can be:

 :symbols: | Description
:---------:|:---------------------------
 #         | A wall tile
 .         | An empty tile
 @         | Glóin's position on the map
 %         | GOLD!


## Output

Your program should print a line with the number of gold tiles Glóin can reach.
Sample Input 1

```
40 20
########################################
#########....###############..##########
###.......%....................#####.###
##........%....................####%..##
##.....#################.......###....##
###..####################......###.....#
########......###########......###.....#
######...............####.......##.....#
###..................%###.......###..%.#
##.....................##........###...#
##.............@.#.....######....###...#
###...................#######.....##..##
###..................########.....##..##
##..%......%.%......######.......##....#
##.....##################.......###....#
##....###################....####.....##
###....##...........######..##.......###
#####................##...###.......####
#######......#######............########
########################################
```


## Sample Output 1

```
6
```


## Sample Input 2

```
40 20
########################################
#.#@..#...#.#.##%...#%####%....##......#
#.#.#.#.#.#.#%.#.##.#......###.##.####.#
#...#.#.#.#.##.#.##.###.######%##.#.%#.#
#####.#.#.#%...#..#.....#....#.##.#.##.#
#.....#.#.#.##.##.#######.##.#.#..#....#
#.#####.#.#.#.....#######..#.#.##.##.###
#......%#.#.###.###.......##.#.##.##.#.#
#########.#...#######.######.#.##.##.#.#
#......%..#.#......##.#.##.....##.##.#.#
#.################.##.#.#########.##.#.#
#......%...........##.#...........##%..#
#####################.#.###%############
#......%###...........#.##########....##
#.#######.#.###########.......%....##.##
#.#....%..#%#%........###############.##
#.#.#####.#.#.#######...%..............#
#########.#.#########.##.###############
#.........##..........##......%........#
########################################
```


Sample Output 2

```
10
```

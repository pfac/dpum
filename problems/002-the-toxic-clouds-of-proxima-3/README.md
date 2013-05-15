The Toxic Clouds of Proxima III
===============================

![Rodericus](https://raw.github.com/pfac/dpum/master/problems/002-the-toxic-clouds-of-proxima-3/img.jpg "Rodericus")

## Introduction

Rodericus is an intrepid adventurer (a little too temerarious for his own good) who boasts about exploring every corner of the universe, no matter how inhospitable. In fact, he doesn't visit the planets where people can easily live in, he prefers those where only a madman would go with a very good reason (several millions of credits for instance). His latest exploit is trying to survive in Proxima III. The problem is that Proxima III suffers from storms of highly corrosive acids that destroy everything, including spacesuits that were especially designed to withstand corrosion.

Our intrepid explorer was caught in a rectangular area in the middle of one of these storms. Fortunately, he has an instrument that is capable of measuring the exact concentration of acid on each sector and how much damage it does to his spacesuit. Now, he only needs to find out if he can escape the storm.


## Problem

The problem consists of finding an escape route that will allow Rodericus to escape the noxious storm. You are given the initial energy of the spacesuit, the size of the rectangular area and the damage that the spacesuit will suffer while standing in each sector.

Your task is to find the exit sector, the number of steps necessary to reach it and the amount of energy his suit will have when he leaves the rectangular area. The escape route chosen should be the safest one (i.e., the one where his spacesuit will be the least damaged). Notice that Rodericus will perish if the energy of his suit reaches zero.

In case there are more than one possible solutions, choose the one that uses the least number of steps. If there are at least two sectors with the same number of steps (X1, Y1) and (X2, Y2) then choose the first if X1 < X2 or if X1 = X2 and Y1 < Y2.


## Constraints

 Limit         | Description
:-------------:|:-----------------------------------
 0 < E ≤ 30000 | the suit's starting energy
 3 ≤ W ≤ 500   | the rectangle's width
 3 ≤ H ≤ 500   | rectangle's height
 0 < X < W	   | the starting X position
 0 < Y < H	   | the starting Y position
 0 ≤ D ≤ 10000 | the damage sustained in each sector


## Input

The first number given is the number of test cases. Each case will consist of a line with the integers E, X and Y. The following line will have the integers W and H. The following lines will hold the matrix containing the damage D the spacesuit will suffer whilst in the corresponding sector. Notice that, as is often the case for computer geeks, (1,1) corresponds to the upper left corner.


## Output

If there is a solution, the output will be the remaining energy, the exit sector's X and Y coordinates and the number of steps of the route that will lead Rodericus to safety. In case there is no solution, the phrase Goodbye cruel world! will be written.


## Sample Input

```
3
40 3 3
7 8
12 11 12 11  3 12 12
12 11 11 12  2  1 13
11 11 12  2 13  2 14
10 11 13  3  2  1 12
10 11 13 13 11 12 13
12 12 11 13 11 13 12
13 12 12 11 11 11 11
13 13 10 10 13 11 12
8 3 4
7 6
4  3  3  2  2  3  2
2  5  2  2  2  3  3
2  1  2  2  3  2  2
4  3  3  2  2  4  1
3  1  4  3  2  3  1
2  2  3  3  0  3  4
10 3 4
7 6
3  3  1  2  2  1  0
2  2  2  4  2  2  5
2  2  1  3  0  2  2
2  2  1  3  3  4  2
3  4  4  3  1  1  3
1  2  2  4  2  2  1
```


## Sample Output

```
12 5 1 8
Goodbye cruel world!
5 1 4 2
```

Hyperspace Jumping
==================

![Wormhole](https://raw.github.com/pfac/dpum/master/problems/003-hyperspace-jumping/img.jpg "Wormhole")


## Problem

You want to know which systems you can reach by using wormholes. Your ship can use the wormholes by sending energy using the improbability drive. You can reach a system by using several wormholes. The problem is that each existing wormhole requires energy to use.


## Constraints

 Limit             | Description
:-----------------:|:----------------------------
 N < 10000         | The number of solar systems
 1 <= H <= 10000   | The number of wormholes
 1 <= S, U, V <= N | IDs of the systems
 1 <= E <= 100000  | Energy


## Input

The input starts with a line containing the number of solar systems `N`, the initial amount of energy in the spaceship `E`, the starting system ID `S` and the number of wormholes `H`. Each wormhole has information about the ID of the starting system `U`, the destination `V` and the energy necessary for using the wormhole `E`.


## Output

The output should be a line with the systems reachable from the starting system sepparated by a single space ordered by their ID.


## Sample Input

```
4
20
1
10
1 2 20
1 4 10
2 1 7
2 3 6
3 4 12
4 2 14
4 3 5
3 2 6
3 1 14
2 4 9
```


## Sample Output

```
1 3 4
```

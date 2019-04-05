# Boids_cpp

Boids implementation in C++ inspired by [Craig Reynolds](http://www.red3d.com/cwr/boids/) and this [pseudo-algorithm](http://www.kfish.org/boids/pseudocode.html)

The main idea here is to learn C++ and to optimize performances for displaying as much boids as possible with a correct framerate. 

To do so, I use a grid system to solve the nearest neighbor problem without a brute-force approach. On top of that, some computations are made in parallel thanks to the Openmp library. I also avoid as much as possible arithmetic functions of the cmath library which are very time-consuming.

A POO approach is useful for code clearness but may cut down the performance. 

## Compilation
`make all` clean and compile everything

`make` compile the boid binary

`make test` compile the test binary that I use for performance testing

## TO DO

I'm sure that performance can be optimized in many ways. This project is not over yet !
  - use profiling and tracing tools to find bottlenecks
  - improve the parallelism
  - keep the code clear and readable
  

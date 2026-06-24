# Grid traversal algorithm
For given NxM grid with blocked and unblocked squares find a maximum number of movement poists returns the path with highest number of unique unblocked squares (one of paths, if multiple paths for specific gridand movement points amount are possible) and a number of visited unblocked squares.

## Instalation:
### Requirements:
CMake 3.5
gcc 7.5.0

### Building
In main directory:
 mkdir build
 cd build
 cmake ..
 make

Output file can be found in bin/ directory
            
## Usage:
grid_traversal N M <lst_blk_squares> mov_points [options]"
where:
N               - number of rows in grid
M               - number of columns in grid
lst_blk_squares - list of blocked points in format "(a,b) (c,d) ... ", where a,b c,d - coordinates of squares
mov_points      - available movement points

## Example:
grid_traversal 5 5 \"(1,1) (2,4) (2,5)\" 10   - 5x5 grid with blocked (1,1) (2,4) and (2,5) squares and 10 movement points
Options:
--draw          - Draw input grid with blocked squares and output grid with traversed path.\n"
--help          - Display this infomation.


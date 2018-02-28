//
// Created by Mikel Matticoli on 2/14/18.
//
#include "Grid.h"

/**
 * Default constructor for Grid, constructs a Grid of given size
 * @param size width and height of square grid
 */
Grid::Grid(int size) : size(size), numOrganisms(0), doodleCount(0), antCount(0) {
    grid = new Organism**[size];
    /* Invariants (nested loop iteration):
      - Pre: Current index of 2d array is unallocated
        - Post: current index of 2d array is allocated, and all Organism ptrs
        are initialized to null.
    */
    // For each row (sub-array)
    for(int i = 0; i < size; i++) {
        // Init a 1D Organism array (row)
        grid[i] = new Organism*[size];
        // For each Organism* (column) in row
        for(int j = 0; j < size; j++) {
            grid[i][j] = nullptr;
        }
    }
}

/**
 * Generate a random number between 0 and max
 * @param max maximum number (exclusive) for return val
 * @return random int between 0 and max
 */
int Grid::randMax(int max) {
    return (int)(rand() * float(max) / float(RAND_MAX));
}

/**
 * Returns random index for grid width or height
 * @return random int betwen 0 and Grid::size
 */
int Grid::randIndex() {
    return randMax(size);
}

/**
    Prints a 2D character-based representation of grid
*/
void Grid::print() {
    /* Invariants (nested loop iteration):
        - Pre: x and y are within bounds of arr, arr[x][y] is a defined character
        - Post: char[x][y] have been printed to stdout, arr is unmutated
    */
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++) {
            // Print out Organism at current index
            std::cout << (grid[x][y] ? grid[x][y]->toString() : "_") << " ";
        }
        // If end of row, print newline
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

/**
 *
 * @param o Reference to organism to be added
 * @param x x position in grid for new organism
 * @param y y position in grid for new organism
 * @return true/false whether or not the organism was added
 */
bool Grid::add(Organism &o, int x, int y) {
    if(occupied(x, y)) {
       return false;
    }
    o.x = x;
    o.y = y;
    grid[x][y] = &o;
    numOrganisms++;
    doodleCount += o.getType() == Organism::DOODLE ? 1 : 0;
    antCount += o.getType() == Organism::ANT ? 1 : 0;
    return true;
}

/**
 * Add organism to random empty cell in grid
 * @param reference to organism to be added
 */
void Grid::addRand(Organism &o) {
    while(!add(o, randIndex(), randIndex()));
}

/**
 * Checks whether given coordinates are in bounds of the grid array
 * @param x x pos of cell to check
 * @param y y pos of cell to check
 * @return return true if pos [x][y] is in bounds of grid, else false
 */
bool Grid::inBounds(int x, int y) {
    return x >=0 && x < size && y  >= 0 && y < size;
}

/**
 * Checks whether given cell in grid is occupied
 * @param x x pos of cell to check
 * @param y y pos of cell to check
 * @return return true if grid[x][y] is not null
 */
bool Grid::occupied(int x, int y) {
    return inBounds(x, y) && (grid[x][y] != nullptr);
}

/**
 * Remove organism from grid
 * @param x x pos of organism in grid to remove
 * @param y y pos of organism in grid to remove
 */
void Grid::remove(int x, int y) {
    Organism *o = grid[x][y];
    if(o !=nullptr) {
        doodleCount -= o->getType() == Organism::DOODLE ? 1 : 0;
        antCount -= o->getType() == Organism::ANT ? 1 : 0;
        grid[x][y] = nullptr;
    }
}

/**
 * Move organism from one grid cell to another (OVERWRITES ANY ORGANISM AT DESTINATION POSITION)
 * @param fromx x-pos of organism to move
 * @param fromy y pos of organism to move
 * @param x destination x to move organism to
 * @param y destination y to move organism to
 */
void Grid::move(int fromx, int fromy, int x, int y) {
    if(grid[fromx][fromy] != nullptr) {
        grid[x][y] = grid[fromx][fromy];
        grid[fromx][fromy] = nullptr;
        grid[x][y]->x = x;
        grid[x][y]->y = y;
    }
}

/**
 * Gets organism adjecent to a given grid cell
 * @param x target cell x
 * @param y target cell y
 * @return a random adjecent organism if one exists, or nullptr
 */
Organism * Grid::getAdjecentOrganism(int x, int y) {
    vector<Organism*> cells(0);
    // Left
    if(inBounds(x - 1, y) && occupied(x - 1, y) && grid[x-1][y]->getType() == Organism::ANT) {
        cells.push_back(grid[x-1][y]);
    }
    // Right
    if(inBounds(x + 1, y) && occupied(x + 1, y) && grid[x+1][y]->getType() == Organism::ANT) {
        cells.push_back(grid[x+1][y]);
    }
    // Up
    if(inBounds(x, y - 1) && occupied(x, y - 1) && grid[x][y-1]->getType() == Organism::ANT) {
        cells.push_back(grid[x][y-1]);
    }
    // Down
    if(inBounds(x, y + 1) && occupied(x, y + 1) && grid[x][y+1]->getType() == Organism::ANT) {
        cells.push_back(grid[x][y+1]);
    }
    if(cells.empty()) return nullptr;
    return cells.size() > 0 ? cells[randMax(cells.size())] : nullptr;
}

/**
 * Gets empty cell adjecent to a given grid cell
 * @param x target cell x
 * @param y target cell y
 * @return a random adjecent empty cell if one exists, or nullptr
 */
Cell *Grid::getEmptyAdjecentCell(int x, int y) {
    vector<Cell*> cells(0);
    // Left
    if(inBounds(x - 1, y) && !occupied(x - 1, y)) cells.push_back(new Cell(x - 1, y));
    // Right
    if(inBounds(x + 1, y) && !occupied(x + 1, y)) cells.push_back(new Cell(x + 1, y));
    // Up
    if(inBounds(x, y - 1) && !occupied(x, y - 1)) cells.push_back(new Cell(x, y - 1));
    // Down
    if(inBounds(x, y + 1) && !occupied(x, y + 1)) cells.push_back(new Cell(x, y + 1));
    return cells.size() > 0 ? cells[randMax(cells.size())] : nullptr;
}

/**
 * Calls the move() method of each organism in the grid (left-to-right, top-to-bottom)
 */
void Grid::moveAll() {
    // Initialize empty queue of organism pointers
    std::queue<Organism *> moveQueue = *new std::queue<Organism *>();
    // Iterate through grid
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++) {
            // Invariant: (x,y) is a position within grid
            // If the cell at the cursor's current pos is NOT empty
            if(grid[x][y] != nullptr) {
                // Add it to the queue to be moved
                // (It can't be moved here or it may move into an unchecked pos)
                moveQueue.push(grid[x][y]);
            };
        }
    }
    // Call move on each item in queue
    while(!moveQueue.empty()){
        // Invariant: queue is not empty, first item in queue is next to be moved
        moveQueue.front()->move();
        moveQueue.pop();
        // Invariant: first item has been processed and removed from moveQueue
    }
}

﻿///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Contains implementation of \a grid class
///
/// Should be augmented by students if needed
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>      // std::setw() if needed
#include <stdexcept>

#include "grid.h"

// According to new restrictions of C++ standards, an explicit definition of static consts is a need
const bool grid::NOT_INFECTED;      // = false;
const bool grid::INFECTED;          // = true;



// Students may need to alter the constructor
grid::grid(const std::string &fileName)
{

    std::ifstream grid_file;

    try
    {
        grid_file.open(fileName.c_str());

        // check if it's all ok
        if (!grid_file.good())
            throw std::runtime_error("File cannot be open");

        // opened correctly
        grid_file >> _rows;
        grid_file >> _cols;

        _area = new std::vector<bool>(_rows * _cols, grid::NOT_INFECTED);
        _visit = new std::vector<bool >(_rows*_cols,grid::NOT_INFECTED);

        int blob_row;
        int blob_col;

        while (!grid_file.eof() && grid_file.good())
        {
            grid_file >> blob_row;
            grid_file >> blob_col;

            _area->operator[](indexof(blob_row, blob_col)) = INFECTED;
        }
    }
    catch (...)
    {
        // always tries to properly close the file!
        grid_file.close();
        throw;              // dispatch further
    }

    grid_file.close();
}

// Students may need to alter the destructor
grid::~grid()
{
    delete _area;
    delete _visit;
}


// Students will need to alter this function to display the
// plus signs (+) next to the cells that belong to
// a counted colony.
std::ostream &operator<<(std::ostream &stream, const grid &ob)
{

    for (int row = 0; row < ob._rows; ++row)
    {
        for (int col = 0; col < ob._cols; col++)
        {
            bool flag =ob._visit->operator[](ob.indexof(row,col));

            stream << ob._area->operator[](ob.indexof(row, col));
            if(flag)
                stream << "+";

            stream << "   ";
        }

        stream << std::endl;
    }
    stream << std::endl;

    return stream;
}

// Students have to replace the return statement in this function with their
// recursive implementation of this method */
int grid::count(int row, int col)
{
    if (!checkIndex(row, col) || !infected(row, col))
        return 0;

    int c = 0;// count;
    (*_visit)[indexof(row,col)] = true; //we visit it

    //go through children
    for (int i = row - 1; i <= row + 1; ++i)
    {
        for (int j = col - 1; j <= col + 1; ++j)
        {
            if(i == row && j == col)
                continue;

            if(checkIndex(i,j) && !checkVisit(i,j))
                c += count(i, j);
        }
    }

    return c + 1;
}


// Students may need to alter this function
int grid::getCount(int row, int col)
{
    int c =count(row, col);

    return c;

}


// Students do not need to alter function indexof.
int grid::indexof(int row, int col) const
{
    if (!checkIndex(row, col))
        throw std::invalid_argument("Index out of range");

    return row * _cols + col;
}

// Students do not need to alter function infected.
bool grid::infected(int row, int col) const
{
    return (_area->operator[](indexof(row, col)) == INFECTED);
}


// Students do not need to alter this function w/o any special reasons.
bool grid::checkIndex(int row, int col) const
{
    if (row >= _rows || row < 0 || col >= _cols || col < 0)
        return false;
    return true;
}

bool grid::checkVisit(int row, int col) const
{
    return _visit->operator[](indexof(row, col));
}

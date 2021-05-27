#pragma once
#include <iostream>


class FieldNotSettedUp : public std::exception
{
public:
    virtual char const* what() const { return "This field should remain empty."; }
};


class NotAlpha : public std::exception
{
public:
    virtual char const* what() const { return "This is not a letter."; }
};


class NotNumber : public std::exception
{
public:
    virtual char const* what() const { return "This is not a number."; }
};


class InvalidOrientation : public std::exception
{
public:
    virtual char const* what() const { return "Invalid orientation."; }
};


class BoardSizeException : public std::exception
{
public:
    virtual char const* what() const { return "Invalid board size."; }
};


class InvalidData : public std::exception
{
public:
    virtual char const* what() const { return "Invalid input data."; }
};


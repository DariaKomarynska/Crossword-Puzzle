#pragma once
#include <iostream>


class FieldNotSettedUp : public std::exception
{
public:
    virtual char const* what() const { return "This field should remain empty."; }
};


class NotAlphaOrSpace : public std::exception
{
public:
    virtual char const* what() const { return "This field should store alpha or space."; }
};


class NotAlpha : public std::exception
{
public:
    virtual char const* what() const { return "This shoule be an alpha."; }
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


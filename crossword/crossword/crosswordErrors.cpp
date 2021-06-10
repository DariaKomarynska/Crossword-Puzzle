#pragma once
#include <iostream>


class FieldNotSettedUp : public std::exception
{
public:
    virtual char const* what() const noexcept override { return "This field should remain empty."; }
};


class NotAlphaOrSpace : public std::exception
{
public:
    virtual char const* what() const noexcept override { return "This field should store alpha or space."; }
};


class NotAlpha : public std::exception
{
public:
    virtual char const* what() const noexcept override { return "This shoule be an alpha."; }
};


class NotNumber : public std::exception
{
public:
    virtual char const* what() const noexcept override { return "This is not a number."; }
};


class InvalidOrientation : public std::exception
{
public:
    virtual char const* what() const noexcept override { return "Invalid orientation."; }
};


class BoardSizeException : public std::exception
{
public:
    virtual char const* what() const noexcept override { return "Invalid board size."; }
};


class InvalidData : public std::exception
{
public:
    virtual char const* what() const noexcept override { return "Invalid input data."; }
};


class InvalidFilename : public std::exception
{
public:
    virtual char const* what() const noexcept override { return "Invalid filename."; }
};



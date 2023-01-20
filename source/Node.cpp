#pragma once
#include "Node.h"
#include <string>
#include <sstream>

Node::Node()
    : Node(0)
{
}

Node::Node(const int key)
    : key(key), left(nullptr), right(nullptr)
{
}

Node::~Node() {
    left  = nullptr;
    right = nullptr;
}

std::wstring ToString(const Node& node)
{
    std::wstringstream out;
    out << node;
    return out.str();
}

std::ostream& operator<<(std::ostream& out, const Node& leaf)
{
    out << leaf.key;
    return out;
}

std::wostream& operator<<(std::wostream& out, const Node& leaf)
{
    out << leaf.key;
    return out;
}

std::istream& operator>>(std::istream& in, Node& node)
{
    if (in.peek() == '\n' || in.eof())
    {
        return in;
    }

    in >> node.key;
    return in;
}

bool operator==(const Node& left, const Node& right)
{
    return left.key == right.key;
}

bool operator!=(const Node& left, const Node& right)
{
    return left.key != right.key;
}

bool operator>(const Node& left, const Node& right)
{
    return left.key > right.key;
}

bool operator>=(const Node& left, const Node& right)
{
    return left.key >= right.key;
}

bool operator<(const Node& left, const Node& right)
{
    return left.key < right.key;
}

bool operator<=(const Node& left, const Node& right)
{
    return left.key <= right.key;
}
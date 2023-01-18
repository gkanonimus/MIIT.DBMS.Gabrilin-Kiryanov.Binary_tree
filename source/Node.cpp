#pragma once
#include <iostream>
#include <string>
#include <sstream>


/*
 * \brief Узел дерева
 */
struct node;

/*
 * \brief Создание нового узла дерева
 * \param Данные узла
 */
struct node* newNode(int key);

struct node {
    int          key;
    struct node* left = NULL;
    struct node* right = NULL;


    /*
     * \brief Конструктор без параметров
     */
    node();

    /*
     * \brief Конструктор с параметрами
     * \param Данные узла
     */
    node(const int key);

    /*
     * \brief Деструктор
     */
    ~node();

    /*
     * \brief Оператор вывода в стандартный поток данных
     * \param Стандартный поток данных
     * \param Узел дерева
     */
    friend std::ostream& operator<<(std::ostream& out, const node& node);

    /*
     * \brief Оператор вывода в стандартный поток данных
     * \param Стандартный поток данных
     * \param Узел дерева
     */
    friend std::wostream& operator<<(std::wostream& out, const node& node);

    /*
     * \brief Оператор ввода из стандартного потока данных
     * \param Стандартный поток данных
     * \param Узел дерева
     */
    friend std::istream& operator>>(std::istream& in, node& node);

    /*
     * \brief Оператор равенства двух узлов
     * \param Левый узел
     * \param Правый узел
     * \return true, если равны
     */
    friend bool operator==(const node& left, const node& right);

    /*
     * \brief Оператор неравенства двух узлов
     * \param Левый узел
     * \param Правый узел
     * \return true, если не равны
     */
    friend bool operator!=(const node& left, const node& right);

    /*
     * \brief Оператор больше
     * \param Левый узел
     * \param Правый узел
     * \return true, если левый узел больше
     */
    friend bool operator>(const node& left, const node& right);

    /*
     * \brief Оператор больше или равно
     * \param Левый узел
     * \param Правый узел
     * \return true, если левый узел больше
     */
    friend bool operator>=(const node& left, const node& right);

    /*
     * \brief Оператор меньше
     * \param Левый узел
     * \param Правый узел
     * \return true, если левый узел меньше
     */
    friend bool operator<(const node& left, const node& right);

    /*
     * \brief Оператор меньше
     * \param Левый узел
     * \param Правый узел
     * \return true, если левый узел меньше
     */
    friend bool operator<=(const node& left, const node& right);
};

struct node* newNode(int key) {
    struct node* temp = new struct node;
    temp->key = key;
    return temp;
}

node::node() {}

node::node(const int key) {
    this->key = key;
}

node::~node() { left = NULL; right = NULL; }

std::ostream& operator<<(std::ostream& out, const node& root)
{
    out << root.key;
    return out;
}

std::wostream& operator<<(std::wostream& out, const node& root)
{
    out << root.key;
    return out;
}

std::istream& operator>>(std::istream& in, node& node)
{
    if (in.peek() == '\n' || in.eof())
    {
        return in;
    }

    in >> node.key;
    return in;
}

bool operator==(const node& left, const node& right)
{
    return left.key == right.key;
}

bool operator!=(const node& left, const node& right)
{
    return left.key != right.key;
}

bool operator>(const node& left, const node& right)
{
    return left.key > right.key;
}

bool operator>=(const node& left, const node& right)
{
    return left.key >= right.key;
}

bool operator<(const node& left, const node& right)
{
    return left.key < right.key;
}

bool operator<=(const node& left, const node& right)
{
    return left.key <= right.key;
}
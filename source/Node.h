#pragma once
#include <iostream>


struct Node;

/*
 * \brief Метод преобразования узла в строку
 * \param Узел дерева
 * \return Данные в виде строки
 */
std::wstring ToString(const Node& node);

/*
 * \brief Узел дерева
 */
struct Node {
    /*
     * \brief Данные для узла
     */
    int key;

    /*
     * \brief Указатель на левый узел
     */
    Node* left = nullptr;

    /*
     * \brief Указатель на правый узел
     */
    Node* right = nullptr;


    /*
     * \brief Конструктор без параметров
     */
    Node();

    /*
     * \brief Конструктор с параметрами
     * \param Данные узла
     */
    Node(const int key);

    /*
     * \brief Деструктор
     */
    ~Node();

    /*
     * \brief Оператор вывода в стандартный поток данных
     * \param Стандартный поток данных
     * \param Узел дерева
     */
    friend std::ostream& operator<<(std::ostream& out, const Node& node);

    /*
     * \brief Оператор вывода в стандартный поток данных
     * \param Стандартный поток данных
     * \param Узел дерева
     */
    friend std::wostream& operator<<(std::wostream& out, const Node& node);

    /*
     * \brief Оператор ввода из стандартного потока данных
     * \param Стандартный поток данных
     * \param Узел дерева
     */
    friend std::istream& operator>>(std::istream& in, Node& node);

    /*
     * \brief Оператор равенства двух узлов
     * \param Левый узел
     * \param Правый узел
     * \return true, если равны
     */
    friend bool operator==(const Node& left, const Node& right);

    /*
     * \brief Оператор неравенства двух узлов
     * \param Левый узел
     * \param Правый узел
     * \return true, если не равны
     */
    friend bool operator!=(const Node& left, const Node& right);

    /*
     * \brief Оператор больше
     * \param Левый узел
     * \param Правый узел
     * \return true, если левый узел больше
     */
    friend bool operator>(const Node& left, const Node& right);

    /*
     * \brief Оператор больше или равно
     * \param Левый узел
     * \param Правый узел
     * \return true, если левый узел больше
     */
    friend bool operator>=(const Node& left, const Node& right);

    /*
     * \brief Оператор меньше
     * \param Левый узел
     * \param Правый узел
     * \return true, если левый узел меньше
     */
    friend bool operator<(const Node& left, const Node& right);

    /*
     * \brief Оператор меньше
     * \param Левый узел
     * \param Правый узел
     * \return true, если левый узел меньше
     */
    friend bool operator<=(const Node& left, const Node& right);
};
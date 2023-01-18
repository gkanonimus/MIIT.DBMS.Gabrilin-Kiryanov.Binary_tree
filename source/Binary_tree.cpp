#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Node.cpp"


/*
 * \brief Вывод дерева
 * \param Корень дерева
 */
std::string ToString(struct node* root);


/*
 * \brief Добавить ноду в дерево
 * \param Значение для вставки
 */
struct node* insert(struct node* node, int key);

/*
 * \brief Поиск inorder-преемника
 * \param Корень дерева
 */
struct node* minValueNode(struct node* node);

/*
 * \brief Удалить ноду из дерева
 * \param Корень дерева
 * \param Значение для удаления
 */
struct node* deleteNode(struct node* root, int key);

/*
 * \brief Заменить одну ноду на другую в дереве
 * \param Корень дерева
 * \param Текущая нода
 * \param Старое значение
 * \param Новое значение
 */
void changeNode(struct node* tree_root, struct node* root, int old_key, int new_key);

/*
 * \brief Проверка дерева на пустоту
 * \param Корень дерева
 */
bool IsEmpty(struct node* root);

/*
 * \brief Узел дерева
 * \param Корень дерева
 */
void deleteTree(struct node* root);


std::string ToString(struct node* root) {
    if (root == nullptr) {
        return std::string("");
    }
    std::stringstream ss;
    ss << ToString(root->left) << " " << root->key << " " << ToString(root->right);
    return ss.str();
}

struct node* insert(struct node* node, int key) {
    // Возвращаем новый узел, если дерево пустое
    if (node == NULL) {
        return newNode(key);
    }

    // Проходим в нужное место и вставляет узел
    if (key <= node->key) {
        node->left = insert(node->left, key);
    }
    else {
        node->right = insert(node->right, key);
    }
    return node;
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;

    // Ищем крайний левый лист — он и будет inorder-преемником
    while (current && current->left != NULL) {
           current = current->left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int key) {
    // Возвращаем, если дерево пустое
    if (root == NULL) {
        return root;
    }

    // Ищем узел, который хотим удалить
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Если у узла один дочерний элемент или их нет
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Если у узла два дочерних элемента
        struct node* temp = minValueNode(root->right);

        // Помещаем inorder-преемника на место узла, который хотим удалить
        root->key = temp->key;

        // Удаляем inorder-преемника
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void changeNode(struct node* tree_root, struct node* root, int old_key, int new_key) {
    if (root == NULL) {
        return;
    }
    if (root->key == old_key) {
        deleteNode(tree_root, old_key);
        insert(tree_root, new_key);
        return;
    }
    if (old_key <= root->key) {
        changeNode(tree_root, root->left, old_key, new_key);
    }
    else {
        changeNode(tree_root, root->right, old_key, new_key);
    }
}

bool IsEmpty(struct node* root) {
    return (root == NULL);
}

void deleteTree(struct node* root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
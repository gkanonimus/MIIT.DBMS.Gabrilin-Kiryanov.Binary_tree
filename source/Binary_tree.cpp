#pragma once
#include "Binary_tree.h"
#include <sstream>
#include <iostream>


Tree::Tree() : root(nullptr)
{
}

Tree::~Tree()
{
    deleteTree(root);
    root = nullptr;
}

Node* Tree::minValueNode(Node* leaf) {
    Node* current = leaf;

    // Ищем крайний левый лист — он и будет inorder-преемником
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void Tree::deleteNode(int key) {
    root = deleteNode(key, root);
}

Node* Tree::deleteNode(int key, Node* leaf) {
    // Возвращаем, если дерево пустое
    if (leaf == NULL) {
        return leaf;
    }

    // Ищем узел, который хотим удалить
    if (key < leaf->key) {
        leaf->left = deleteNode(key, leaf->left);
    }
    else if (key > leaf->key) {
        leaf->right = deleteNode(key, leaf->right);
    }
    else {
        // Если у узла один дочерний элемент или их нет
        if (leaf->left == NULL) {
            Node* temp = leaf->right;
            free(leaf);
            return temp;
        }
        else if (leaf->right == NULL) {
            Node* temp = leaf->left;
            free(leaf);
            return temp;
        }

        // Если у узла два дочерних элемента
        Node* temp = minValueNode(leaf->right);

        // Помещаем inorder-преемника на место узла, который хотим удалить
        leaf->key = temp->key;

        // Удаляем inorder-преемника
        leaf->right = deleteNode(temp->key, leaf->right);
    }
    return leaf;
}

void Tree::deleteTree()
{
    deleteTree(root);
    this->root = nullptr;
}

void Tree::deleteTree(Node* leaf)
{
    if (leaf != nullptr)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}

bool Tree::IsEmpty() {
    return this->root == nullptr;
}

void Tree::insert(int key)
{
    root = insert(key, root);
}

Node* Tree::newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    return temp;
}

Node* Tree::insert(int key, Node* leaf) {
    // Возвращаем новый узел, если дерево пустое
    if (leaf == nullptr) {
        return newNode(key);
    }

    // Проходим в нужное место и вставляет узел
    if (key <= leaf->key) {
        leaf->left = insert(key, leaf->left);
    }
    else {
        leaf->right = insert(key, leaf->right);
    }
    return leaf;
}

void Tree::printTree() {
    std::cout << ToString(this->root);
}

std::string Tree::ToString(Node* root) {
    if (root == nullptr) {
        return std::string("");
    }
    std::stringstream ss;
    ss << ToString(root->left) << " " << root->key << " " << ToString(root->right);
    return ss.str();
}

void Tree::changeNode(int old_key, int new_key) {
    changeNode(old_key, new_key, this->root);
}

void Tree::changeNode(int old_key, int new_key, Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->key == old_key) {
        deleteNode(old_key, this->root);
        insert(new_key, this->root);
        return;
    }
    if (old_key <= root->key) {
        changeNode(old_key, new_key, root->left);
    }
    else {
        changeNode(old_key, new_key, root->right);
    }
}
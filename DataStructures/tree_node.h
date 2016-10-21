//
//  tree_node
//  Algorithm
//
//  Created by dtysky on 16/9/9.
//  Copyright © 2016 dtysky@outlook.com. All rights reserved.
//

#ifndef ALGORITHM_TREE_NODE_H
#define ALGORITHM_TREE_NODE_H

#include <cstdio>
#include <iostream>


namespace data_structures {
    template <typename T>
    class TreeNode {
    protected:
        TreeNode *_left, *_right, *_parent;

    public:
        T element;
        TreeNode();
        TreeNode(const TreeNode& node);
        virtual ~TreeNode();
        void insertLeft(const TreeNode* node);
        void insertRight(const TreeNode* node);
        TreeNode<T>* deleteLeft(const TreeNode* node);
        TreeNode<T>* deleteRight(const TreeNode* node);
        TreeNode<T>* left();
        TreeNode<T>* right();
        TreeNode<T>* parent();
        void operator=(const TreeNode<T>& node);
        bool operator==(const TreeNode<T>& node);
        bool operator!=(const TreeNode<T>& node);
        friend std::ostream& operator<<(std::ostream& out, const TreeNode<T>& node){
            std::cout << "Current: " << &node << ", Element: " << node.element << ", Next: " << node._next;
            return out;
        }


        template <typename T> inline
        TreeNode<T>::TreeNode(){
            _left = nullptr;
            _right = nullptr;
            _parent = nullptr;
            element = T();
        }

        template <typename T> inline
        TreeNode<T>::TreeNode(const TreeNode<T>& node){
            element = node.element;
            _left = node._left;
            _right = node._right;
            _parent = node._parent;
        }

        template <typename T> inline
        TreeNode<T>::~TreeNode(){
            _left = nullptr;
            _right = nullptr;
            _parent = nullptr;
        }

        template <typename T> inline
        void TreeNode<T>::operator=(const TreeNode<T>& node){
            element = node.element;
            _left = node._left;
            _right = node._right;
            _parent = node._parent;
        }

        template <typename T> inline
        bool TreeNode<T>::operator==(const TreeNode<T>& node){
            return (element == node.element) && (_parent == node._parent) && (_left == node._left);
        }

        template <typename T> inline
        bool TreeNode<T>::operator!=(const TreeNode<T>& node){
            return !(*this == node);
        }

        template <typename T> inline
        void TreeNode<T>::insertLeft(TreeNode *node){
            node->_left = _left;
            node->_parent = this;
            _left = node;
        }

        template <typename T> inline
        void TreeNode<T>::insertRight(TreeNode *node){
            node->_left = _right;
            node->_parent = this;
            _right = node;
        }

        template <typename T> inline
        TreeNode<T>* TreeNode<T>::deleteLeft(const TreeNode *node){
            TreeNode<T>* temp_node = _next;
            if (_next != nullptr) {
                _next = _next->_next;
            }
            return temp_node;
        }

        template <typename T> inline
        TreeNode<T>* TreeNode<T>::deleteRight(const TreeNode *node){
            TreeNode<T>* temp_node = _next;
            if (_next != nullptr) {
                _next = _next->_next;
            }
            return temp_node;
        }

        template <typename T> inline
        TreeNode<T>* TreeNode<T>::left(){
            return _left;
        }

        template <typename T> inline
        TreeNode<T>* TreeNode<T>::right(){
            return _right;
        }

        template <typename T> inline
        TreeNode<T>* TreeNode<T>::parent(){
            return _parent;
        }
    };
}

#endif //ALGORITHM_TREE_NODE_H

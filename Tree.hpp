//
//  Tree.hpp
//  Learn
//
//  Created by Yuliia Ivanechko on 10/23/19.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

template <class T>
class Tree {
    struct Node {
        T item;
        Node* left_son;
        Node* right_son;
        
        Node(T i, Node* l = nullptr, Node* r = nullptr) {
            item = i;
            left_son = l;
            right_son = r;
        }
    };
    
        Node* root;
public:

    Tree() {
        root = nullptr;
    }
    ~Tree() {
        delete_subtree(root);
    }
    
    int get_height() {
        return get_height(root);
    }
    
    int get_nodes_on_level(int level) {
        return get_nodes_on_level(root, level);
    }
    
    void add(const T& elem) {
        add(root, elem);
    }
    
private:
    void delete_subtree(Node* node);
    int get_height(Node* node);
    void add(Node*& node, const T &item);
};

template <class T>
void Tree<T>::delete_subtree(Node* node) {
    if(!node)
        return;
    delete_subtree(node->left_son);
    delete_subtree(node->right_son);
    delete node;
}

template <class T>
int Tree<T>::get_height(Node* node) {
    if(node == nullptr) {
        return 0;
    }
    int max = 0;
    for(Node* current = node->left_son ; current; current = current->left_son) {
        int cur_height = get_height(current);
        if(cur_height > max)
            max = cur_height;
    }
    return max + 1;
}

template <class T>
void Tree<T>::add(Node*& node, const T &item) {
    if(node == nullptr) {
        node = new Node(item);
    } else if(item < node->item) {
        add(node->left_son, item);
    } else {
        add(node->right_son, item);
    }
}



    

#endif /* Tree_h */

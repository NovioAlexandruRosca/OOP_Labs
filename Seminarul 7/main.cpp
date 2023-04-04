#include "tema.h"
#include <iostream>

bool compare_int(int a, int b) {
    return a < b;
}

bool find_int(int n1, int n2) {
    if (n2 == n1)
        return true;
    else return false;
}

int main()
{

    Tree<int> my_tree;
    TreeNode<int>* node1 = my_tree.add_node(nullptr, 1);
    TreeNode<int>* node2 = my_tree.add_node(node1, 2);
    TreeNode<int>* node3 = my_tree.add_node(node1, 3);
    TreeNode<int>* node4 = my_tree.add_node(node2, 4);
    TreeNode<int>* node5 = my_tree.add_node(node3, 5);

    my_tree.delete_node(node5);
    TreeNode<int>* node6 = my_tree.insert(node1,1,6);
    TreeNode<int>* node7 = my_tree.find(node6,find_int);

    std::cout << "Noduri adaugate: " << std::endl;
    std::cout << node1->data_ << std::endl;
    std::cout << node1->child[0]->data_ << std::endl;
    std::cout << node1->child[1]->data_ << std::endl;
    std::cout << node1->child[2]->data_ << std::endl;
    std::cout << node7->data_ << std::endl;

    std::cout << std::endl << std::endl << my_tree.count(nullptr) << std::endl << std::endl;

    TreeNode<int>* node10 = my_tree.add_node(node4, 9);
    TreeNode<int>* node11 = my_tree.add_node(node4, 8);
    TreeNode<int>* node12 = my_tree.add_node(node4, 7);



    my_tree.sort(node4, [](int a, int b) { return a < b; });
    std::cout << node10->data_ << std::endl;
    std::cout << node11->data_ << std::endl;
    std::cout << node12->data_ << std::endl;

    Tree<int> my_treee;
    TreeNode<int>* nod1 = my_treee.add_node(nullptr, 1);
    TreeNode<int>* nod2 = my_treee.add_node(nod1, 2);
    TreeNode<int>* nod3 = my_treee.add_node(nod1, 3);
    std::cout << my_treee.count(nullptr);

}
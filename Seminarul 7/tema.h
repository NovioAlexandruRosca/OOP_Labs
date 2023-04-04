#pragma once

#include <iostream>

template <typename T>
class TreeNode {

public:

    T data_;
    int allocated = 5;
    int grow = 15;
    TreeNode** child;
    TreeNode* tata;
    int number_of_childs;

    TreeNode(T data) {
        data_ = data;
        number_of_childs = 0;
        child = new TreeNode *[allocated]();
    }
};

template <typename T>
class Tree
{
    TreeNode<T> * root_;
    TreeNode<T>* result;
    T all_kids = 1;

    public:

        ~Tree<T>()
        {
            deletee(root_);
        }

        void DFS_mod(TreeNode<T>* index, TreeNode<T>* caut)
        {
            for (int i = 0; i < index->number_of_childs; i++)
            {
                if (index->child[i] == caut)
                    index->child[i]->tata = index;
            
                if (index->child[i] != nullptr)
                   DFS_mod(index->child[i], caut);
                else
                    break;
            }
        }

        TreeNode<T>* add_node(TreeNode<T>* parent, T data) {
            
            TreeNode<T>* new_node = new TreeNode<T>(data);
            if (parent == nullptr) {
                
                root_ = new_node;
            }
            else {
                
                if (parent->number_of_childs >= parent->allocated)
                {
                    parent->allocated += parent->grow;
                    TreeNode<T>** Copie = new TreeNode<T>*[parent->allocated];

                    for (int i = 0; i < parent->number_of_childs; i++)
                        Copie[i] = parent->child[i];

                        delete[] parent->child;

                    parent->child = Copie;

                }

                parent->child[parent->number_of_childs] = new_node;
                parent->number_of_childs++;
            }

            return new_node;
        }

        TreeNode<T>* get_node(TreeNode<T>* parent,int index) {
            if (parent == nullptr) {
                
                return root_;
            }
            else
            {
                if (parent->child[index] != nullptr)
                    return parent->child[index];
            }
        }

        void deletee(TreeNode<T>* node)
        {
            if (node == nullptr) {
                return;
            }

            for (int i = 0; i < node->number_of_childs; i++) {
                deletee(node->child[i]);
            }

            delete node;
        }

        void delete_node(TreeNode<T>* node) {

            if (node != root_)
            {
                DFS_mod(root_, node);
                for (int i = 0; i < node->tata->number_of_childs; i++)
                {
                    if (node->tata->child[i] == node)
                    {
                        for (int j = i; j < node->tata->number_of_childs - 1; j++)
                            node->tata->child[j] = node->tata->child[j + 1];

                        node->tata->child[node->tata->number_of_childs] = nullptr;
                        node->tata->number_of_childs--;
                        break;
                    }
                }
            }

            deletee(node);

        }

        TreeNode<T>* insert(TreeNode<T>* parent, int index, T data)
        {
            TreeNode<T>* new_node = new TreeNode<T>(data);
   
            if (index >= 0 && index <= parent->number_of_childs)
            {
                if (parent->number_of_childs >= parent->allocated)
                {
                    parent->allocated += parent->grow;
                    TreeNode<T>** Copie = new TreeNode<T>*[parent->allocated];

                    for (int i = 0; i < parent->number_of_childs; i++)
                        Copie[i] = parent->child[i];

                    delete[] parent->child;

                    parent->child = Copie;

                }

                for (int i = parent->number_of_childs - 1; i >= index; i--)
                    parent->child[i + 1] = parent->child[i];

                parent->child[index] = new_node;
                parent->number_of_childs++;

                return new_node;
            }

        }

        void basic_dfs(TreeNode<T>* value, TreeNode<T>* index, bool (*cmp)(T, T))
        {
            if (cmp(value->data_,index->data_))result=index;
            else
                for (int i = 0; i < index->number_of_childs; i++)
                {
                    if (index->child[i] != nullptr)
                        basic_dfs(value, index->child[i],cmp);
                    else
                        break;
                }
        }

        TreeNode<T>* find(TreeNode<T>* index,bool (*cmp)(T,T)) {
             basic_dfs(index, root_,cmp);
             return result;
        }

        void helper_dfs(TreeNode<T>* index)
        {
            all_kids += index->number_of_childs;
                for (int i = 0; i < index->number_of_childs; i++)
                {
                    if (index->child[i] != nullptr)
                        helper_dfs( index->child[i]);
                    else
                        break;
                }
        }

        T count(TreeNode<T>* index)
        {
            if(index == nullptr)
                helper_dfs(root_);
            else
                helper_dfs(index);
            return all_kids;
        }

        void sort(TreeNode<T>* index,bool (*cmp)(T,T) = nullptr) {
            if (index->number_of_childs <= 1) {
                return;
            }
            if (cmp == nullptr) {
                cmp = [](T a,T b) -> bool {
                    return a < b;
                };
            }
            
            for(int i = 0 ; i < index->number_of_childs ; i++)
                for (int j = i + 1; j < index->number_of_childs; j++)
                {
                    if (cmp(index->child[j]->data_, index->child[i]->data_))
                    {
                        T aux;
                        aux = index->child[j]->data_;
                        index->child[j]->data_ = index->child[i]->data_;
                        index->child[i]->data_ = aux;
                    }
                }
        }
};

#include <iostream>

template <typename T>

class TreeNode
{
private:
    T value;
    TreeNode<T>* parent;
    TreeNode<T>* root;
    TreeNode<T>* children;
    TreeNode<T>* sibling;

public:
    TreeNode(const T& value) : value(value), root(nullptr), parent(nullptr), children(nullptr), sibling(nullptr) {}

    void add_node(TreeNode<T>* newNode, TreeNode<T>* parentNode = nullptr)
    {
        if (parentNode == nullptr)
        {
            if (newNode != nullptr)
            {
                newNode->parent = nullptr;
                root = newNode;
            }
            else
                std::cerr << "Cannot add a null node as root!" << std::endl;

        }
        else
        {
            if (parentNode->children == nullptr)
                parentNode->children = newNode;

            else
            {
                TreeNode<T>* aux = parentNode->children;
                while (aux->sibling != nullptr)
                {
                    aux = aux->sibling;
                }
                aux->sibling = newNode;
            }
            newNode->parent = parentNode;
        }
    }

    TreeNode<T>* get_node(TreeNode<T>* parentNode = nullptr)
    {
        if (parentNode == nullptr) return root;
        return parentNode;
    }

    void delete_node(TreeNode<T>* node)
    {
        if (node == nullptr) return;

        TreeNode<T>* child = node->children;
        while (child != nullptr)
        {
            TreeNode<T>* next = child->sibling;
            delete_node(child);
            child = next;
        }

        if (node->parent != nullptr)
        {
            TreeNode<T>* aux = node->parent->children;
            if (aux == node)
                node->parent->children = node->sibling;

            else
            {
                while (aux != nullptr && aux->sibling != node) aux = aux->sibling;

                if (aux != nullptr) aux->sibling = node->sibling;

            }
        }
        delete node;
    }

    TreeNode<T>* find(TreeNode<T>* node, T value)
    {
        if (node == nullptr) return nullptr;

        if (node->value == value) return node;

        TreeNode<T>* result = nullptr;
        TreeNode<T>* child = node->children;

        while (child != nullptr && result == nullptr)
        {
            result = find(child, value);
            child = child->sibling;
        }

        return result;
    }

    void insert(TreeNode<T>* newNode, TreeNode<T>* parentNode, int index)
    {
        if (parentNode == nullptr)
        {
            std::cout << "Parent node cannot be nullptr for insertion!" << std::endl;
            return;
        }

        if (index < 0)
        {
            std::cout << "Invalid index for insertion!" << std::endl;
            return;
        }

        if (index == 0)
        {
            newNode->sibling = parentNode->children;
            parentNode->children = newNode;
            newNode->parent = parentNode;
            return;
        }

        int count = 0;
        TreeNode<T>* temp = parentNode->children;
        while (temp != nullptr && count < index - 1)
        {
            temp = temp->sibling;
            count++;
        }

        if (temp == nullptr)
        {
            std::cerr << "Invalid index for insertion!" << std::endl;
            return;
        }

        newNode->sibling = temp->sibling;
        temp->sibling = newNode;
        newNode->parent = parentNode;
    }


    void sort(TreeNode<T>* node, bool comparator = true)
    {
        if (node == nullptr)
            return;

        if (node->children == nullptr)
            return;

        bool swapped;
        TreeNode<T>* last = nullptr;
        do
        {
            swapped = false;
            TreeNode<T>* current = node->children;
            TreeNode<T>* next = current->sibling;
            while (next != last)
            {
                if (comparator == true and (next->value < current->value))
                {
                    T temp = next->value;
                    next->value = current->value;
                    current->value = temp;
                    swapped = true;
                }
                else if (comparator == false and (next->value > current->value))
                {
                    T temp = next->value;
                    next->value = current->value;
                    current->value = temp;
                    swapped = true;
                }
                current = next;
                next = next->sibling;
            }
            last = current;
        } while (swapped);

        TreeNode<T>* current_node = node->children;
        while (current_node != nullptr)
        {
            std::cout << current_node->value << ' ';
            current_node = current_node->sibling;
        }
        std::cout << std::endl;
    }

    int count(TreeNode<T>* node = nullptr)
    {
        if (node == nullptr) node = root;

        int cnt = 0;
        TreeNode<T>* child = node->children;
        while (child != nullptr)
        {
            cnt++;
            child = child->sibling;
        }
        return cnt;
    }

    void print(TreeNode<T>* node)
    {
        TreeNode<T>* current = node->children;
        while (current != nullptr)
        {
            std::cout << current->value << ' ';
            current = current->sibling;
        }
        std::cout << std::endl;
    }
};

int main()
{
    TreeNode<int> root(10);

    TreeNode<int> node1(5);
    TreeNode<int> node2(15);
    TreeNode<int> node3(3);

    root.add_node(&root, nullptr);
    root.add_node(&node1, &root);
    root.add_node(&node2, &root);
    node1.add_node(&node3, &node1);

    std::cout << "Number of children of the root node: " << root.count(&root) << std::endl;

    std::cout << root.get_node() << std::endl;

    std::cout << root.find(&root, 15) << std::endl;

    TreeNode<int> node4(2);
    root.insert(&node4, &root, 1);
    std::cout << "Number of children of the root node: " << root.count(&root) << std::endl;

    root.print(&root);
    root.sort(&root, true);
    root.sort(&root, false);

    //root.delete_node(&node1);
    //std::cout << "Number of children of the root node: " << root.count(&root) << std::endl;

    return 0;
}

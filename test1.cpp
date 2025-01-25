#include <iostream>

struct tree {
    int x;       // ID of the node
    tree* l;     // Pointer to the left subtree
    tree* r;     // Pointer to the right subtree
};

// Recursive function to reroot the tree to the node with left_id
tree* reroot(tree* root, int left_id) {
    if (!root) return nullptr;

    if (root->x == left_id) {
        return root;  // Found the node to reroot
    }

    // Try to find the left_id in the left subtree
    if (root->l) {
        tree* newRoot = reroot(root->l, left_id);
        if (newRoot) {
            root->l = nullptr; // Detach the left subtree from the current root

            // Attach the current root as either the left or right child of the new root
            if (!newRoot->l) {
                newRoot->l = root;
            } else if (!newRoot->r) {
                newRoot->r = root;
            }

            return newRoot;
        }
    }

    // Try to find the left_id in the right subtree
    if (root->r) {
        tree* newRoot = reroot(root->r, left_id);
        if (newRoot) {
            root->r = nullptr; // Detach the right subtree from the current root

            // Attach the current root as either the left or right child of the new root
            if (!newRoot->l) {
                newRoot->l = root;
            } else if (!newRoot->r) {
                newRoot->r = root;
            }

            return newRoot;
        }
    }

    return nullptr; // If left_id is not found, return nullptr
}

// Function to reroot the tree to the specified left_id
tree* solution(tree* t, int left_id) {
    return reroot(t, left_id);
}

// Helper function to print the tree in preorder traversal
void printTree(tree* root) {
    if (!root) return;
    
    std::cout << root->x << " ";
    printTree(root->l);
    printTree(root->r);
}

int main() {
    // Example tree construction
    tree* root = new tree{4, nullptr, nullptr};
    root->l = new tree{2, nullptr, nullptr};
    root->r = new tree{8, nullptr, nullptr};
    
    root->r->r = new tree{7, nullptr, nullptr};
    root->r->r->l = new tree{6, nullptr, nullptr};
    root->r->r->r = new tree{1, nullptr, nullptr};
    root->r->r->r->l = new tree{3, nullptr, nullptr};
    root->r->r->r->r = new tree{5, nullptr, nullptr};
    
    int left_id = 6;  // Specify the new root by its ID
    
    tree* newRoot = solution(root, left_id);
    
    std::cout << "New root tree (preorder): ";
    printTree(root);
    
    return 0;
}

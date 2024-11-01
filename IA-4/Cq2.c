#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 100

typedef struct Node {
    char name[256];
    int is_directory; // 1 for directory, 0 for file
    int size; // Only for files
    struct Node* children[MAX_CHILDREN];
    int child_count;
} Node;

typedef struct FileSystem {
    Node* root;
} FileSystem;

FileSystem* create_file_system();
Node* create_node(const char* name, int is_directory, int size);
void create(FileSystem* fs, const char* path, const char* name, int is_directory);
void delete(FileSystem* fs, const char* path);
void list_contents(FileSystem* fs, const char* path);
void move(FileSystem* fs, const char* source_path, const char* dest_path);
Node* find(FileSystem* fs, const char* name);
int calculate_size(FileSystem* fs, const char* path);
Node* find_node(Node* root, const char* path);
Node* find_parent_node(Node* root, const char* path);
void free_node(Node* node);

FileSystem* create_file_system() {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->root = create_node("/", 1, 0); // Root directory
    return fs;
}

Node* create_node(const char* name, int is_directory, int size) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->is_directory = is_directory;
    node->size = size;
    node->child_count = 0;
    return node;
}

void create(FileSystem* fs, const char* path, const char* name, int is_directory) {
    Node* parent = find_node(fs->root, path);
    if (parent && parent->is_directory) {
        Node* new_node = create_node(name, is_directory, is_directory ? 0 : 1); // Size for files (1 for simplicity)
        parent->children[parent->child_count++] = new_node;
    } else {
        printf("Error: Parent directory not found or not a directory.\n");
    }
}

void delete(FileSystem* fs, const char* path) {
    Node* node_to_delete = find_node(fs->root, path);
    if (node_to_delete) {
        Node* parent = find_parent_node(fs->root, path);
        if (parent) {
            for (int i = 0; i < parent->child_count; i++) {
                if (parent->children[i] == node_to_delete) {
                    free_node(node_to_delete);
                    parent->children[i] = parent->children[--parent->child_count];
                    return;
                }
            }
        }
    } else {
        printf("Error: Node not found.\n");
    }
}

void list_contents(FileSystem* fs, const char* path) {
    Node* node = find_node(fs->root, path);
    if (node && node->is_directory) {
        for (int i = 0; i < node->child_count; i++) {
            printf("%s\n", node->children[i]->name);
        }
    } else {
        printf("Error: Not a directory or not found.\n");
    }
}

void move(FileSystem* fs, const char* source_path, const char* dest_path) {
    Node* node_to_move = find_node(fs->root, source_path);
    if (node_to_move) {
        Node* source_parent = find_parent_node(fs->root, source_path);
        Node* dest_parent = find_node(fs->root, dest_path);
        if (dest_parent && dest_parent->is_directory) {
            for (int i = 0; i < source_parent->child_count; i++) {
                if (source_parent->children[i] == node_to_move) {
                    source_parent->children[i] = source_parent->children[--source_parent->child_count];
                    dest_parent->children[dest_parent->child_count++] = node_to_move;
                    return;
                }
            }
        }
    } else {
        printf("Error: Node not found.\n");
    }
}

Node* find(FileSystem* fs, const char* name) {
    Node* result = NULL;
    // Recursive search (helper function)
    // Implementation omitted for brevity
    return result;
}

int calculate_size(FileSystem* fs, const char* path) {
    Node* node = find_node(fs->root, path);
    if (node) {
        int total_size = 0;
        for (int i = 0; i < node->child_count; i++) {
            if (node->children[i]->is_directory) {
                total_size += calculate_size(fs, node->children[i]->name);
            } else {
                total_size += node->children[i]->size; // size for files
            }
        }
        return total_size;
    }
    return 0;
}

Node* find_node(Node* root, const char* path) {
    // Implementation for finding a node based on the path
}

Node* find_parent_node(Node* root, const char* path) {
    // Implementation for finding the parent node based on the path
}

void free_node(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node);
}

int main() {
    FileSystem* fs = create_file_system();
    create(fs, "/", "home", 1);
    create(fs, "/home", "user", 1);
    create(fs, "/home/user", "file.txt", 0);

    printf("Contents of /home:\n");
    list_contents(fs, "/home");

    printf("Size of /home/user: %d\n", calculate_size(fs, "/home/user"));

    delete(fs, "/home/user/file.txt");
    list_contents(fs, "/home/user");

    free_node(fs->root);
    free(fs);
    return 0;
}


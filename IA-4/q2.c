#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char Name[20];
    int is_Directory; // 1 for Directory and 0 for Files
    int size;
    struct Node *children[5];
    int children_count;
}*node_ptr;


node_ptr RootInit(){
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    strcpy(new_node->Name,"root");new_node->is_Directory = 1;new_node->children_count = 0;
    return new_node;
}

node_ptr Navigate_Dir(node_ptr dir,char path[]){
    if(strcmp(path,"")==0)return dir;
    char subdir[20];int len = strlen(path);
    subdir[0] = '\0';node_ptr out;
    for(int i=0;i<=len;i++){
        if(path[i] == '/'|| path[i] == '\0'){
            printf("%s",subdir);
            if(dir->is_Directory == 1){
                for(int i = 0;i<dir->children_count;i++){
                    if(strcmp(dir->children[i]->Name,subdir) == 0)out = dir->children[i];
                }
            }else return dir;
            strcpy(subdir,"");
        }else{
            int len1 = strlen(subdir);
            subdir[len1] = path[i];
            subdir[len1 + 1] = '\0';
        }
    }
    return out;
}

node_ptr Create_Dir(node_ptr root,char path[],char Name[]){
    node_ptr dir = Navigate_Dir(root,path);
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    strcpy(new_node->Name,Name);new_node->is_Directory = 1;new_node->children_count = 0;
    dir->children[(dir->children_count)++] = new_node;
    return new_node;
}
node_ptr Create_File(node_ptr root,char path[],char Name[],int size){
    node_ptr dir = Navigate_Dir(root,path);
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    strcpy(new_node->Name,Name);new_node->is_Directory = 0;new_node->size = size;
    dir->children[(dir->children_count)++] = new_node;
    return new_node;
}

void Delete_Directory(node_ptr dir){
    if(dir->children_count == 0){
        free(dir);return;
    }
    for(int i=0;i<dir->children_count;i++){
        Delete_Directory()
    }

}

int main(){
    printf("Hello World!");
    node_ptr root = RootInit();
    node_ptr folder1 = Create_Dir(root,"","Folder1");
    node_ptr folder2 = Create_Dir(root,"Folder1","Folder2");
    node_ptr root2 = Navigate_Dir(root,"Folder1/Folder2");
    node_ptr file1 = Create_File(root,"","karthik.py",20);
    printf("%p,%p",file1,root->children[1]);

    return 0; 
}
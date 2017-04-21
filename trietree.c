#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct _DATA{
	char d;
};

typedef struct _TRIATREE{
	struct _DATA data;
	struct _TRIATREE *next;
	struct _TRIATREE *child;
}trieTree,*pTrieTree;

pTrieTree root; // root node 

pTrieTree construct(char* data,int sl);

int insertTrieTreeNode(pTrieTree root,char* str,int sl);
int ergodicTrieTreenode(pTrieTree root);

pTrieTree construct(char* data,int sl){
	if(strlen(data)<=sl)
		return NULL;
	pTrieTree ptt;
	ptt = (pTrieTree)malloc(sizeof(trieTree));

	if(!ptt)
		return NULL;

	ptt->data.d = data[sl++];
	ptt->next = NULL;
	ptt->child = construct(data,sl);
	return ptt;
}

int insertTrieTreeNode(pTrieTree root,char* str,int sl){
	char dd = str[sl];

	if(strlen(str)<=sl)
		return 0;

	pTrieTree pTmpTreeNode;
	pTmpTreeNode = root;
	if(pTmpTreeNode->child == NULL){
		pTmpTreeNode->child = construct(str,sl);
		return 1;
	}

	pTmpTreeNode = pTmpTreeNode->child;
	if(!(pTmpTreeNode->data.d ^ str[sl])){
		return insertTrieTreeNode(pTmpTreeNode->child,str,sl++);
	}

	while(pTmpTreeNode->next != NULL){
		pTmpTreeNode = pTmpTreeNode->next;
		if(!(pTmpTreeNode->data.d ^ str[sl]))
			return insertTrieTreeNode(pTmpTreeNode->child,str,sl++);
	}

	pTmpTreeNode->next = construct(str,sl++);
	return 1;

}

int ergodicTrieTreenode(pTrieTree root){
	if(root->child !=NULL){
		printf("%c",root->child->data.d);
		ergodicTrieTreenode(root->child);
	}
	if(root->next !=NULL){
		printf("%c",root->next->data.d);
		ergodicTrieTreenode(root->next);
	}
	return 1;
}
int main(int argc,char **argv){
	char* str="hello world";
	char* str2="hello foolish";
	root = (pTrieTree)malloc(sizeof(trieTree));
	root->child = construct(str,0);
	insertTrieTreeNode(root,str2,0);
	ergodicTrieTreenode(root);

	if(root->child->next !=NULL)
		printf("%c",root->child->next->data.d);
	return 1;
}
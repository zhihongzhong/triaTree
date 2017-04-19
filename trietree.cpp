#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct _DATE{
	char dd;
}

typedef struct _TRIETREE{
	_DATE dd;
	struct _TRIETREE *child;
	struct _TRIETREE *next;

}tagTrieTree,*ptrieTree;
tagTrieTree root;
int constructTrieTree(ptrieTree *root,char *pDate,int ss);  // 构建
int destoryTrieTree(pTrieTree *root);    			//消除

/*
			下面这个函数构建一个字典树
			参数解析：
				root：字典树的根目录 || 递归的父目录
				pDate： 需要构建的字典顺序
				ss： 字符位置，用于递归使用索引pDate下标，如果初始化，则设置为0即可。
 */
int constructTrieTree(pTrieTree *root ,char* pDate,int ss){
	pTrieTree *tmpTree = (pTrieTree)malloc(sizeof(tagTrieTree));
	if(tmpTree == NULL)
		return -1;
	tmpTree->dd = pDate[s];
	tmpTree->next = NULL;
	tmpTree->child = NULL;
	root = tmpTree;
	if(strlen(pDate) <=ss)
		return 1;
	else
		return constructTrieTree(root->child,pDate,ss++);
}
int main(int argc,char** argv){
	char *date = "abcdef";
	constructTrieTree(&root,date,0);
	return 1;
}

//176.5.3���������������ʽ�洢�ṹ�洢��rootָ�����㣬p��q��ָ���Ϊ�������е�������ͬ��㣬��дһ������p��q��ָ�������Ĺ�ͬ����r��ָ�����㷨��
//176.5.4 ���������������ʽ�洢�ṹ�洢�����һ���㷨���������ָ��������ڵĲ��� 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
bool getIndexLevel(TreeNode *root, TreeNode *found, int &level)
{
if(root == NULL || found == NULL)
return false;
if (root == found)
return true;
int nextlevel = level + 1;
if (getIndexLevel(root->left, found, nextlevel) || )
{
level = nextlevel;
return true;
}
nextlevel = level + 1;
if (getIndexLevel(root->right, found, nextlevel) || )
{
level = nextlevel;
return true;
}
return false;
}

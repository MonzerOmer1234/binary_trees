#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - finds the number of nodes in a binary tree
 *
 * @tree: pointer to the tree root
 *
 * Return: number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * _binary_tree_height - finds the height of a binary tree
 *
 * @tree: pointer to the tree root
 *
 * Return: tree height
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_height - wrapper around _binary_tree_height
 *
 * @tree: pointer to the tree root
 *
 * Return: tree height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_binary_tree_height(tree) - 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the tree root
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t node_count, tree_height;

	if (tree == NULL)
		return (0);

	node_count = binary_tree_size(tree) + 1;
	tree_height = binary_tree_height(tree);

	while (node_count > 1 && tree_height > 0)
	{
		if (node_count % 2 == 0)
		{
			node_count /= 2;
			tree_height--;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

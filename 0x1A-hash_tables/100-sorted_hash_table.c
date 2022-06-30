#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *shash_table_create - creates an ordered hash table
 *@size: size of the array
 *Return:pointer to a hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;
	unsigned long int i;

	new_table = malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (new_table->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		new_table->array[i] = NULL;
	}
	new_table->shead = NULL;
	new_table->stail = NULL;
	return (new_table);
}
/**
 *shash_table_set - sets the value of a shash table
 *@ht: pointer to shash_table
 *@key: key
 *@value:value associated with key
 *Return:1- success, 0 - failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *copy;
	shash_node_t *new, *tmp;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	copy = strdup(value);
	if (copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	/*shead points to first element of the sorted linked list*/
	tmp = ht->shead;
	while (tmp)
	{
		/*updating a key that exists*/
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = copy;
			return (1);
		}
		tmp = tmp->snext;
	}
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(copy);
		free(new);
		return (0);
	}
	new->value = copy;
	/*Node assigned from end, next points to the beginning of
	  linked list*/
	new->next = ht->array[index];
	ht->array[index] = new;
	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	/*sorting, value greater than the key*/
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	/*value less than*/
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}
	return (1);
}

/**
 *shash_table_get - returns a value based on associated key
 *@ht:pointer to hash table
 *@key:key to retrieve data with
 *Return: value
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);
	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;
	if (node == NULL)
		return (NULL);
	return node->value;
}
/**
 *shash_table_print - prints a shash table
 *@ht:pointer to sorted hash table
 *Return:void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 *shash_table_print_rev - prints a table's contents in reverse
 *@ht:pointer to hash_table
 *Return:void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 *shash_table_delete - frees a sorted hash table
 *@ht:pointer to sorted hash table
 *Return:void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;
	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->value);
		free(node->key);
		free(node);
		node = tmp;
	}
	free(ht->array);
	free(ht);
}

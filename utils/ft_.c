#include "../cub3D.h"

t_gc **ft_gc(void)
{
    static t_gc *head;

    return (&head);
}

void *ft_malloc(size_t size)
{
    void *ptr;
    t_gc *new_node;
    t_gc **gc_list;

    ptr = malloc(size);
    if (!ptr)
        ft_error("Memory allocation failed");
    gc_list = ft_gc();
    new_node = malloc(sizeof(t_gc));
    if (!new_node)
    {
        free(ptr);
        ft_error("Memory allocation for garbage collector failed");
    }
    new_node->ptr = ptr;
    new_node->next = *gc_list;
    *gc_list = new_node;
    return (ptr);
}

void ft_free(void)
{
    t_gc **gc_list;
    t_gc *current;
    t_gc *next;

    gc_list = ft_gc();
    current = *gc_list;
    while (current)
    {
        next = current->next;
        free(current->ptr);
        free(current);
        current = next;
    }
    *gc_list = NULL;
}

void ft_error(const char *msg)
{
    perror("Error\n");
    perror(msg);
    ft_exit(EXIT_FAILURE);
}
void ft_exit(int code)
{
   ft_free();
    exit(code);
}

//
// Created by Mandi Burnette on 29/01/2020.
//

#include "LIBFT/libft.h"
#include "LIBFT/dlist.h"

void    oper_s(t_dlist **stack_a)
{
    t_dlist *begin_a;
    t_dlist *second_el;
    int count;

    count = 0;
    begin_a = *stack_a;
    while (begin_a)
    {
        count++;
        begin_a = begin_a->next;
    }
    if (count < 2)
        ;
    else
    {
        begin_a = (*stack_a);
        second_el = begin_a->next;
        begin_a->next = second_el->next;
        begin_a->previous = second_el;
        second_el->next = begin_a;
        second_el->previous = NULL;
        (*stack_a) = second_el;
    }
}

void    oper_p(t_dlist **stack_push, t_dlist **stack_pop) //  push - положить, pop - вытащить
{
    t_dlist *begin_pop;
    t_dlist *begin_push;
    t_dlist *second_el;
    int count;

    count = 0;
    begin_pop = (*stack_pop);
    begin_push = (*stack_push);
    if ((*stack_pop) != NULL)
    {
        if (begin_pop == NULL) // если стек из которого хотим взять пустой
            ;
        else         // если стек из которого хотим взять - не пустой
        {
            if (begin_pop->next != NULL) // если откуда берем есть стопочка
            {
                second_el = begin_pop->next;
                if (begin_push != NULL)  // 4
                {
                    begin_pop->next = begin_push;
                    begin_push->previous = begin_pop;
                    begin_pop->previous = NULL;
                }
                else                     // 3
                {
                    begin_pop->next = NULL;
                    begin_pop->previous = NULL;
                }
                (*stack_pop) = second_el;
            }
            else      // если откуда берем нет стопочки
            {
                if (begin_push != NULL)  // 2
                {
                    begin_pop->next = begin_push;
                    begin_push->previous = begin_pop;
                    begin_pop->previous = NULL;
                }
                else                      // 1
                {
                    begin_pop->next = NULL;
                    begin_pop->previous = NULL;
                }
                (*stack_pop) = NULL;
            }
            (*stack_push) = begin_pop;
        }
    }
}

void    oper_r(t_dlist **stack)
{
    t_dlist *begin;     // начало листа
    t_dlist *second_el; // сохраняем второй элемент

    begin = (*stack);
    if (begin && begin->next) // если первый и второй элемент существуют
    {
        second_el = begin->next;
        while ((*stack)->next)
            (*stack) = (*stack)->next;
        (*stack)->next = begin;
        begin->previous = (*stack);
        begin->next = NULL;
        second_el->previous = NULL;
        (*stack) = second_el;
    }
}

void    oper_rr(t_dlist **stack)
{
    t_dlist *previous_el;
    t_dlist *begin;

    begin = (*stack);
    if (begin && begin->next)
    {
        while ((*stack)->next)
            (*stack) = (*stack)->next;
        previous_el = (*stack)->previous;
        (*stack)->next = begin;
        (*stack)->previous = NULL;
        begin->previous = (*stack);
        previous_el->next = NULL;
    }
}
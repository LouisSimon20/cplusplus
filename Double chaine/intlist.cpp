#include <iostream>
#include "intlist.h"

IntCell::IntCell(int valeur)
{
    value = valeur;
}

IntList::~IntList()
{
    if (first_cell != nullptr)
    {
        IntCell *pcell = last_cell;
        while (pcell != first_cell)
        {
            delete pcell->next_cell;
            pcell = pcell->previous_cell;
        }
        delete pcell->next_cell;
        delete pcell;
    }
}

void IntList::add_front(int valeur)
{
    IntCell *pcell = new IntCell(valeur);

    if (first_cell != nullptr)
    {                                      //il existe au moins une cellule
        pcell->next_cell = first_cell;     // lien vers la queue de liste
        first_cell->previous_cell = pcell; //lien vers la tête de liste
    }
    else
    {
        last_cell = pcell;
    }
    first_cell = pcell; //actualisation de la liste
}

void IntList::add_back(int valeur)
{
    IntCell *pcell = new IntCell(valeur);

    if (last_cell != nullptr)
    {
        pcell->previous_cell = last_cell;
        last_cell->next_cell = pcell;
    }
    else
    {
        first_cell = pcell;
    }
    last_cell = pcell;
}

void IntList::remove_front()
{
    if (first_cell != nullptr)
    {
        if (first_cell->next_cell != nullptr)
        {
            first_cell = first_cell->next_cell;
            delete first_cell->previous_cell;
        }
        else
        { //il n'y a qu'une seule cellule
            delete first_cell;
            first_cell = nullptr;
            last_cell = nullptr;
        }
    }
}

void IntList::remove_back()
{
    if (last_cell != nullptr)
    {
        if (last_cell->previous_cell != nullptr)
        {
            last_cell = last_cell->previous_cell;
            delete last_cell->next_cell;
        }
        else
        {
            delete last_cell;
            first_cell = nullptr;
            last_cell = nullptr;
        }
    }
}

void IntList::remove(int valeur)
{
    IntCell *pcell = last_cell;

    while (pcell->previous_cell != nullptr)
    {
        if (valeur == pcell->value)
        {

            if (pcell == first_cell)
            {
                (pcell->next_cell)->previous_cell = nullptr;
                first_cell = pcell->next_cell;
            }

            if (pcell == last_cell)
            {
                (pcell->previous_cell)->next_cell = nullptr;
                last_cell = pcell->previous_cell;
            }
            else
            {
                (pcell->previous_cell)->next_cell = pcell->next_cell;
                (pcell->next_cell)->previous_cell = pcell->previous_cell;
            }

            delete pcell;
            break;
        }
        pcell = pcell->previous_cell;
    }
}

bool IntList::search(int value)
{
    bool result = false;
    IntCell *pcell = last_cell;

    while ((pcell->previous_cell != nullptr) and result == false)
    {
        if (value == pcell->value)
        {
            result = true;
        }
        pcell = pcell->previous_cell;
    }
    return result;
}

void IntList::print()
{
    std::cout << '{';
    IntCell *pcell = last_cell;
    if (pcell != nullptr)
    {
        while (pcell != first_cell)
        {
            std::cout << pcell->value << " ";
            pcell = pcell->previous_cell;
        }
        std::cout << first_cell->value;
    }
    std::cout << "}" << std::endl;
}
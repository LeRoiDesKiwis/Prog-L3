/****************
 * fichier body *
 ****************/

#include "motif.h"

typedef struct {
    int d, f;
} Couple;

const Couple dessin[NX][NY+1] =
{
    {{-1,-1}},
    {{ 1, 1},{17,17},{-1,-1}},
    {{ 1, 1},{17,17},{-1,-1}},
    {{ 1, 1},{12,12},{18,18},{-1,-1}},
    {{ 1, 4},{11,11},{18,18},{-1,-1}},
    {{ 4, 4},{10,10},{18,18},{-1,-1}},
    {{ 3, 3},{ 9, 9},{18,18},{-1,-1}},
    {{ 2, 2},{ 8, 8},{18,18},{-1,-1}},
    {{ 1, 1},{ 9, 9},{18,18},{-1,-1}},
    {{10,10},{18,18},{-1,-1}},
    {{11,11},{18,18},{-1,-1}},
    {{12,12},{18,18},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{ 8,12},{18,18},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{12,12},{18,18},{-1,-1}},
    {{11,11},{18,18},{-1,-1}},
    {{10,10},{18,18},{-1,-1}},
    {{ 9, 9},{18,18},{-1,-1}},
    {{ 8, 8},{18,18},{-1,-1}},
    {{ 9, 9},{18,18},{-1,-1}},
    {{10,10},{18,18},{-1,-1}},
    {{11,11},{18,18},{-1,-1}},
    {{12,12},{18,18},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{ 8,12},{18,18},{-1,-1}},
    {{ 8, 8},{10,10},{12,12},{18,18},{-1,-1}},
    {{ 8, 8},{12,12},{18,18},{-1,-1}},
    {{ 8, 8},{12,12},{18,18},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{ 8,12},{18,18},{-1,-1}},
    {{ 8, 8},{18,18},{-1,-1}},
    {{ 8, 8},{18,18},{-1,-1}},
    {{ 8, 8},{18,18},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{ 8,12},{18,18},{-1,-1}},
    {{ 8, 8},{10,10},{12,12},{18,18},{-1,-1}},
    {{ 8, 8},{12,12},{18,18},{-1,-1}},
    {{ 8, 8},{12,12},{18,18},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{17,17},{-1,-1}},
    {{ 8,12},{18,18},{-1,-1}},
    {{ 8, 8},{12,12},{18,18},{-1,-1}},
    {{ 8, 8},{12,12},{18,18},{-1,-1}},
    {{ 8, 8},{12,12},{18,18},{-1,-1}},
    {{17,17},{-1,-1}},
    {{ 1, 1},{17,17},{-1,-1}},
    {{ 2, 2},{17,17},{-1,-1}},
    {{ 3, 3},{17,17},{-1,-1}},
    {{ 4, 4},{17,17},{-1,-1}},
    {{ 1, 4},{17,17},{-1,-1}},
    {{ 1, 1},{17,17},{-1,-1}},
    {{ 1, 1},{ 8, 8},{10,12},{18,18},{-1,-1}},
    {{ 1, 1},{17,17},{-1,-1}},
    {{-1,-1}}
};

bool isOn(int x, int y)
{
    if ((x < 0) || (x >= NX) || (y < 0) || (y >= NY))
        return false;

    bool ok = false;
    int i = 0;

    while ((! ok) && (dessin[x][i].d != -1))
    {
        if ((dessin[x][i].d <= y) && (y <= dessin[x][i].f))
            ok = true;
        i ++;
    }
    return ok;
}
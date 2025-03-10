// Copyright 2025 Aleksandr Bocharov
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
// 2025-03-09
// https://github.com/Aleksandr3Bocharov/RefalABBrainfuck

//====================================================================
// Модуль "RefalABEinshteinPuzzlec" (GUI версия)
//====================================================================

#include <stdint.h>
#include <stdbool.h>
#include "refal.def"
#include "gui.h"

extern uint8_t refalab_true, refalab_false;

static uint32_t steps = 0;
static uint32_t stepsBack = 0;
static char answer[21] = {'\0'};
static uint32_t rule = 0;
static uint32_t position = 0;
static char ruleText[150] = {'\0'};
static char table[6][6][32] = {{{"Дом"}, {"Цвет"}, {"Национальность"}, {"Сигареты"}, {"Животное"}, {"Напиток"}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
                               {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}}};

// <GInit> ==
static void ginit_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    guiInit();
    return;
}
char ginit_0[] = {Z5 'G', 'I', 'N', 'I', 'T', '\005'};
G_L_B uint8_t refalab_ginit = '\122';
void (*ginit_1)(void) = ginit_;

// <GClose> ==
static void gclose_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    guiClose();
    return;
}
char gclose_0[] = {Z6 'G', 'C', 'L', 'O', 'S', 'E', '\006'};
G_L_B uint8_t refalab_gclose = '\122';
void (*gclose_1)(void) = gclose_;

// <Info> == /True/ | /False/
static void info_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    T_LINKCB *p = refal.prevr;
    if (!slins(p, 1))
        return;
    p = p->next;
    p->tag = TAGF;
    p->info.codep = NULL;
    p->info.codef = &refalab_true;
    if (!guiInfo())
        p->info.codef = &refalab_false;
    return;
}
char info_0[] = {Z4 'I', 'N', 'F', 'O', '\004'};
G_L_B uint8_t refalab_info = '\122';
void (*info_1)(void) = info_;

// <VAnswer S(N)S S(N)B E(O)A> ==
static void vanswer_(void)
{
    const T_LINKCB *p = refal.preva->next;
    do
    {
        if (p->tag != TAGN)
            break;
        steps = gcoden(p);
        p = p->next;
        if (p->tag != TAGN)
            break;
        stepsBack = gcoden(p);
        p = p->next;
        bool neot = false;
        size_t i;
        for (i = 0; p != refal.nexta; i++)
        {
            if (p->tag != TAGO || i == 20)
            {
                neot = true;
                break;
            }
            answer[i] = p->info.infoc;
            p = p->next;
        }
        if (neot)
            break;
        answer[i] = '\0';
        return;
    } while (false);
    refal.upshot = 2;
    return;
}
char vanswer_0[] = {Z7 'V', 'A', 'N', 'S', 'W', 'E', 'R', '\007'};
G_L_B uint8_t refalab_vanswer = '\122';
void (*vanswer_1)(void) = vanswer_;

// <VRule S(N)P S(N)R E(O)T> ==
static void vrule_(void)
{
    const T_LINKCB *p = refal.preva->next;
    do
    {
        if (p->tag != TAGN)
            break;
        position = gcoden(p);
        if (position > 2)
            break;
        p = p->next;
        if (p->tag != TAGN)
            break;
        rule = gcoden(p);
        if (rule > 16)
            break;
        p = p->next;
        bool neot = false;
        size_t i;
        for (i = 0; p != refal.nexta; i++)
        {
            if (p->tag != TAGO || i == 149)
            {
                neot = true;
                break;
            }
            ruleText[i] = p->info.infoc;
            p = p->next;
        }
        if (neot)
            break;
        ruleText[i] = '\0';
        return;
    } while (false);
    refal.upshot = 2;
    return;
}
char vrule_0[] = {Z5 'V', 'R', 'U', 'L', 'E', '\005'};
G_L_B uint8_t refalab_vrule = '\122';
void (*vrule_1)(void) = vrule_;

// <VTable S(N)R S(N)C E(O)T> ==
static void vtable_(void)
{
    const T_LINKCB *p = refal.preva->next;
    do
    {
        if (p->tag != TAGN)
            break;
        const uint32_t row = gcoden(p);
        if (row < 1 || row > 5)
            break;
        p = p->next;
        if (p->tag != TAGN)
            break;
        const uint32_t col = gcoden(p);
        if (col > 5)
            break;
        p = p->next;
        bool neot = false;
        size_t i;
        for (i = 0; p != refal.nexta; i++)
        {
            if (p->tag != TAGO || i == 31)
            {
                neot = true;
                break;
            }
            table[row][col][i] = p->info.infoc;
            p = p->next;
        }
        if (neot)
            break;
        table[row][col][i] = '\0';
        return;
    } while (false);
    refal.upshot = 2;
    return;
}
char vtable_0[] = {Z6 'V', 'T', 'A', 'B', 'L', 'E', '\006'};
G_L_B uint8_t refalab_vtable = '\122';
void (*vtable_1)(void) = vtable_;

// <View> == 'Q' | 'B' | 'P' | 'N' | 'E'
static void view_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    T_LINKCB *p = refal.prevr;
    if (!slins(p, 1))
        return;
    p = p->next;
    p->tag = TAGO;
    p->info.codep = NULL;
    p->info.infoc = 'Q';
    const int result = guiView(answer, steps, stepsBack, rule, ruleText, table, position);
    if (result == 1)
        p->info.infoc = 'B';
    else if (result == 2)
        p->info.infoc = 'P';
    else if (result == 3)
        p->info.infoc = 'N';
    else if (result == 4)
        p->info.infoc = 'E';
    return;
}
char view_0[] = {Z4 'V', 'I', 'E', 'W', '\004'};
G_L_B uint8_t refalab_view = '\122';
void (*view_1)(void) = view_;

// <IsExit> == /True/ | /False/
static void isexit_(void)
{
    if (refal.preva->next != refal.nexta)
    {
        refal.upshot = 2;
        return;
    }
    T_LINKCB *p = refal.prevr;
    if (!slins(p, 1))
        return;
    p = p->next;
    p->tag = TAGF;
    p->info.codep = NULL;
    p->info.codef = &refalab_true;
    if (!guiIsExit())
        p->info.codef = &refalab_false;
    return;
}
char isexit_0[] = {Z6 'I', 'S', 'E', 'X', 'I', 'T', '\006'};
G_L_B uint8_t refalab_isexit = '\122';
void (*isexit_1)(void) = isexit_;

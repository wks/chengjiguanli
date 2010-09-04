/*
 * model.h
 * This file is part of Chengjiguanli
 *
 * Copyright (C) 2010 - Kunshan Wang
 *
 * Chengjiguanli is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Chengjiguanli is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Chengjiguanli; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */
#ifndef __MODEL_H__
#define __MODEL_H__

#include "linkedlist.h"

enum Sex {
    SEX_MALE,
    SEX_FEMALE
};

struct ScoreInfo {
    struct ListNode node;
    char *course_name;
    double score;
};

struct ScoreInfo* score_info_new(char *course_name, double score);
void score_inf_free(struct ScoreInfo *info);

struct StudentInfo {
    struct ListNode node;
    char *name;
    enum Sex sex;
    struct ScoreInfo score_infos;
};

struct StudentInfo* student_info_new(char *name, enum Sex sex);
void student_info_free(struct StudentInfo *info);

struct MainContext {
    struct StudentInfo student_infos;
};

void main_context_init(struct MainContext *context);

#endif

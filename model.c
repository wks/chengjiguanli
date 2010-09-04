/*
 * model.c
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
#include <stdlib.h>
#include <string.h>

#include "model.h"

struct ScoreInfo* score_info_new(char *course_name, double score) {
    struct ScoreInfo *info = malloc(sizeof(struct ScoreInfo));

    info->course_name = strdup(course_name);
    info->score = score;
}

void score_info_free(struct ScoreInfo *info) {
    free(info->course_name);
    free(info);
}

struct StudentInfo* student_info_new(char *name, enum Sex sex) {
    struct StudentInfo *info = malloc(sizeof(struct StudentInfo));

    info->name = strdup(name);
    info->sex = sex;
    list_init(&info->score_infos.node);

    return info;
}

void student_info_free(struct StudentInfo *info) {
    struct ScoreInfo *score_info;
    struct ListNode *ptr;

    free(info->name);
    list_for_each(ptr, &info->score_infos.node) {
        score_info = (struct ScoreInfo*)ptr;
        score_info_free(score_info);
    }

    free(info);
}

void main_context_init(struct MainContext *context)
{
    list_init(&context->student_infos.node);
}

/*
 * main.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "model.h"

struct MainContext main_context;

void print_everything(struct MainContext *context) {
    struct StudentInfo *student_info;
    struct ListNode *ptr;
    int index;

    printf("*******列表********\n");
    index=0;
    list_for_each(ptr, &context->student_infos.node) {
        student_info = (struct StudentInfo*) ptr;
        printf(
                "序号: [%d]\t"
                "姓名: [%s]\t"
                "性别: [%s]\n"
                , index
                , student_info->name
                , student_info->sex==SEX_MALE ? "男" : "女"
              );
        index++;
    }
    printf("*****列表结束******\n");
}

void add_student(struct MainContext *context) {
    char buffer[256];
    char name[256];
    enum Sex sex;
    struct StudentInfo *student_info;

    do {
        printf("姓名:");
        fgets(buffer, 256, stdin);
    } while (strlen(buffer) == 0);

    {
        char *nl;
        nl = strchr(buffer, '\n');
        if(nl != NULL) {
            *nl = '\0';
        }
    }

    strcpy(name, buffer);

    do {
        printf("性别[m/f]:");
        fgets(buffer, 256, stdin);
        switch(buffer[0]) {
            case 'm':
                sex = SEX_MALE;
                break;
            case 'f':
                sex = SEX_FEMALE;
                break;
            default:
                continue;
        }
    } while (strlen(buffer) == 0);

    student_info = student_info_new(name, sex);

    list_insert(&context->student_infos.node, &student_info->node);

    printf("完成\n");
}

void del_student(struct MainContext *context) {
    char buffer[256];
    struct StudentInfo *student_info;
    struct ListNode *ptr;
    int index;

    do {
        printf("序号:");
        fgets(buffer, 256, stdin);
    } while (sscanf(buffer, "%d", &index) != 1);

    ptr = list_delete(&context->student_infos.node, index);

    student_info = (struct StudentInfo*) ptr;

    student_info_free(student_info);

    printf("完成\n");
}

void print_student_info(struct StudentInfo *student_info) {
    struct ScoreInfo *score_info;
    struct ListNode *ptr;
    int index;

    printf("*******学生********\n");
    printf(
            "姓名: [%s]\n"
            "性别: [%s]\n"
            , student_info->name
            , student_info->sex==SEX_MALE ? "男" : "女"
          );
    index=0;
    list_for_each(ptr, &student_info->score_infos.node) {
        score_info = (struct ScoreInfo*) ptr;
        printf(
                "序号: [%d]\t"
                "科目: [%s]\t"
                "分数: [%lf]\n"
                , index
                , score_info->course_name
                , score_info->score
              );
        index++;
    }
    printf("*****学生结束******\n");
}

void add_score(struct StudentInfo *student_info) {
    char buffer[256];
    char course_name[256];
    double score;

    struct ScoreInfo *score_info;

    do {
        printf("科目:");
        fgets(buffer, 256, stdin);
    } while (strlen(buffer) == 0);

    {
        char *nl;
        nl = strchr(buffer, '\n');
        if(nl != NULL) {
            *nl = '\0';
        }
    }

    strcpy(course_name, buffer);

    do {
        printf("分数:");
        fgets(buffer, 256, stdin);
    } while (sscanf(buffer, "%lf", &score) != 1);

    score_info = score_info_new(course_name, score);

    list_insert(&student_info->score_infos.node, &score_info->node);

    printf("完成\n");
}

void del_score(struct StudentInfo *student_info) {
    char buffer[256];
    struct ScoreInfo *score_info;
    struct ListNode *ptr;
    int index;

    do {
        printf("序号:");
        fgets(buffer, 256, stdin);
    } while (sscanf(buffer, "%d", &index) != 1);

    ptr = list_delete(&student_info->score_infos.node, index);

    score_info = (struct ScoreInfo*) ptr;

    score_info_free(score_info);

    printf("完成\n");
}

void edit_student_detail(struct StudentInfo *student_info) {
    while(1) {
        char buffer[256];
        int selection;
        do {
            printf(
                    "学生\n"
                    "1. 信息\n"
                    "2. 添加分数\n"
                    "3. 删除分数\n"
                    "0. 返回\n"
                  );
            fgets(buffer, 256, stdin);
        } while (sscanf(buffer, "%d", &selection) != 1);

        switch(selection) {
            case 1:
                print_student_info(student_info);
                break;
            case 2:
                add_score(student_info);
                break;
            case 3:
                del_score(student_info);
                break;
            case 0:
                return;
        }
    }
}

void edit_student(struct MainContext *context) {
    char buffer[256];
    struct StudentInfo *student_info;
    struct ListNode *ptr;
    int index;

    do {
        printf("序号:");
        fgets(buffer, 256, stdin);
    } while (sscanf(buffer, "%d", &index) != 1);

    ptr = context->student_infos.node.next;
    while(index--) {
        ptr = ptr->next;
    }

    student_info = (struct StudentInfo*) ptr;

    edit_student_detail(student_info);

    printf("完成\n");
}

int main() {
    main_context_init(&main_context);

    printf("*** 学生管理系统 ***\n");
    while(1) {
        char buffer[256];
        int selection;
        do {
            printf(
                    "主菜单\n"
                    "1. 列表\n"
                    "2. 添加学生\n"
                    "3. 修改学生\n"
                    "4. 删除学生\n"
                    "0. 退出\n"
                  );
            fgets(buffer, 256, stdin);
        } while (sscanf(buffer, "%d", &selection) != 1);

        switch(selection) {
            case 1:
                print_everything(&main_context);
                break;
            case 2:
                add_student(&main_context);
                break;
            case 3:
                edit_student(&main_context);
                break;
            case 4:
                del_student(&main_context);
                break;
            case 0:
                exit(0);
        }
    }

    return 0;
}

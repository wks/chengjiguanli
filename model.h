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

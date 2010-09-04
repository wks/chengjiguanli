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

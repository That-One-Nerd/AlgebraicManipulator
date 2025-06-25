#pragma once

#include <inttypes.h>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

typedef struct
{
    const char* display_name;
    void (*select_func)();
} list_item;

typedef struct
{
    uint8_t start_row;
    uint8_t end_row;
} list_config;

int display_list(const list_item* list, const list_config& config);

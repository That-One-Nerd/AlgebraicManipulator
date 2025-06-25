#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
#include "main.h"

void demo_func()
{
    os_PutStrLine("and this is the demo func!\n");
}

list_item modes[] = {
    { "Option 1", demo_func },
    { "Option 2", nullptr },
    { "Option 3", nullptr },
    { "Option 4", nullptr },
    { "Option 5", nullptr },
    { "Option 6", nullptr },
    { "Option 7", nullptr },
    { "Option 8", nullptr },
    { "Option 9", nullptr },
    { "Option 10", demo_func },
    { nullptr, nullptr }
};

/* Main function, called first */
int main(void)
{
    /* Clear the homescreen */
    os_ClrHome();

    list_config config;
    config.start_row = 1;
    config.end_row = 5;
    display_list(modes, config);

    /* Waits for a key */
    while (!os_GetCSC());

    /* Return 0 for success */
    return 0;
}

int display_list(const list_item* list, const list_config& config)
{
    size_t item_count = 0;
    for (size_t i = 0; true; i++)
    {
        const list_item& item = list[i];
        if (item.display_name == nullptr) break;
        item_count++;
    }
    if (item_count == 0) return -1; // No list to display.

    uint8_t max_on_screen = MIN(config.end_row - config.start_row, 10 - config.start_row) + 1;
    uint24_t offset = 0;
    for (size_t i = 0, j = offset; i < max_on_screen && j < item_count; i++, j++)
    {
        os_SetCursorPos(config.start_row + i, 0);
        os_PutStrLine(list[j].display_name);
    }

    return -1;
}

#ifndef CONFIG_H
#define CONFIG_H

typedef enum {
    ENABLED, DISABLED, AUTO
} Conf;

typedef struct {
    Conf multithreading;
    unsigned int fps;
    char *window_name;
    int width;
    int height;
} Config;

Config *newConfig();
void destroyConfig(Config *pConfig);

#endif
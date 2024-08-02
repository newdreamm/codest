#pragma once

#include <iostream>
#include <string>
#include <cstdarg>
#include <ctime>
#include <unistd.h>

#define LOG_NORMAL "log.txt"
#define LOG_ERR "log.error"

#define DEBUG   0
#define NORMAL  1
#define WARNING 2
#define ERROR   3
#define FATAL   4

const char * to_levelstr(int level)
{
    switch(level)
    {
        case DEBUG : return "DEBUG";
        case NORMAL: return "NORMAL";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case FATAL: return "FATAL";
        default : return nullptr;
    }
}

// void logMessage(DEBUG, "hello %f, %d, %c", 3.14, 10, 'C');

void logMessage(int level, const char *format, ...)
{
    // [日志等级] [时间戳/时间] [pid] [messge]
    // [WARNING] [2023-05-11 18:09:08] [123] [创建socket失败]
    // va_list start;    
    // va_start(start);
    // while(*p){
    //     switch(*p)
    //     {
    //         case '%':
    //             p++;
    //             if(*p == 'f') arg = va_arg(start, float);
    //         ...
    //     }
    // }
    // va_end(start); 
#define NUM 1024
    char logprefix[NUM];
    snprintf(logprefix, sizeof(logprefix), "[%s][%ld][pid: %d]",
        to_levelstr(level), (long int)time(nullptr), getpid());

    char logcontent[NUM];
    va_list arg;
    va_start(arg, format);
    vsnprintf(logcontent, sizeof(logcontent), format, arg);

    // std::cout << logprefix << logcontent << std::endl;

    FILE *log =  fopen(LOG_NORMAL, "a");
    FILE *err = fopen(LOG_ERR, "a");
    if(log != nullptr && err != nullptr)
    {
        FILE *curr = nullptr;
        if(level == DEBUG || level == NORMAL || level == WARNING) curr = log;
        if(level == ERROR || level == FATAL) curr = err;
        if(curr) fprintf(curr, "%s%s\n", logprefix, logcontent);

        fclose(log);
        fclose(err);
    }
}

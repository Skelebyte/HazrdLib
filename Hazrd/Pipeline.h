#ifndef PIPELINE_H
#define PIPELINE_H

#include <stdio.h>
#include <stdlib.h>
#include "Shader.h"

typedef struct Pipeline {
    Shader vertexShader;
    Shader fragmentShader;
} Pipeline;


char* readFile(const char* path);

Pipeline createPipeline(const char* vertexShaderPath, const char* fragmentShaderPath);
void destroyPipeline(Pipeline* pipeline);

#endif

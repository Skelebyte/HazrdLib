#include "../Pipeline.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
Shader readShader(const char* path) {
    FILE* file;

    printf("reading\n");

    // char cwd[1024];
    // if (getcwd(cwd, sizeof(cwd)) != NULL) {
    //     printf("Current working dir: %s\n", cwd);
    // } else {
    //     printf("getcwd() error");
    // }

    file = fopen(path, "rb");
    if(file == NULL) {
        printf("Failed to read file: %s\n", path);
        return nullShader();
    }

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);


    char* buffer = (char*)malloc((fileSize + 1) * sizeof(char));
    int index = 0;
    int intermediate;
    while((intermediate = fgetc(file)) != EOF) {
        buffer[index] = intermediate;
        index++;
    }

    buffer[index] = '\0';


    Shader shader = {
        buffer,
        ftell(file)
    };

    rewind(file);
    fclose(file);
    return shader;

}

Pipeline createPipeline(const char* vertexShaderPath, const char* fragmentShaderPath) {
    Shader vertexShader = readShader(vertexShaderPath);
    Shader fragmentShader = readShader(fragmentShaderPath);

    // TODO: fix this returning -1 stuff
    // l
    printf("frag shader size: %ld\n", fragmentShader.shaderSize); // returns -1
    printf("vert shader size: %ld\n", vertexShader.shaderSize); // returns -1


    Pipeline pipeline = {
        vertexShader,
        fragmentShader
    };

    return pipeline;
}

void destroyPipeline(Pipeline* pipeline) {

    destroyShader(pipeline->vertexShader);
    destroyShader(pipeline->fragmentShader);

    pipeline->vertexShader = nullShader();
    pipeline->fragmentShader = nullShader();
}

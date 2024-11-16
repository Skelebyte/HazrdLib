#include <stddef.h>
typedef struct Shader {
    char* compiledCode;
    size_t shaderSize;
} Shader;

Shader nullShader();
void destroyShader(Shader target);

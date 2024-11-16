#include "../Shader.h"

#include <stdlib.h>

Shader nullShader() {
    Shader shader = {
        "",
        0
    };

    return shader;
}

void destroyShader(Shader target) {
    free(target.compiledCode);
    target.shaderSize = 0;
}

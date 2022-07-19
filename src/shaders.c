#include <gl.h>
#include <stdio.h>
#include <stdlib.h>
#include "shaders.h"

static char* readShaderSource(const char* sourcePath)
{
    FILE* file = fopen(sourcePath, "rb");

    if (file == NULL)
    {
        printf("Could not open file: %s\n", sourcePath);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);  /* same as rewind(f); */

    char* buffer = malloc(fileSize + 1);
    fread(buffer, 1, fileSize, file);
    fclose(file);

    buffer[fileSize] = 0;

    return buffer;
}

void shadersInit(struct Shaders* shaders)
{
    const char* vertexShaderSource = readShaderSource("shaders/shader_fragment_basic.glsl");
    const char* fragmentShaderSource = readShaderSource("shaders/shader_vertex_basic.glsl");

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n %s\n", infoLog);
    }
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n %s\n", infoLog);
    }

    // unsigned int shaderProgram;
    shaders->shaderProgram = glCreateProgram();
    glAttachShader(shaders->shaderProgram, vertexShader);
    glAttachShader(shaders->shaderProgram, fragmentShader);
    glLinkProgram(shaders->shaderProgram);

    glGetProgramiv(shaders->shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaders->shaderProgram, 512, NULL, infoLog);
        printf("ERROR::LINKING_FAILED\n %s\n", infoLog);
    }
    glUseProgram(shaders->shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
